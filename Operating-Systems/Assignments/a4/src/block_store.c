#include <stdio.h>
#include <stdint.h>
#include "bitmap.h"
#include "block_store.h"
// include more if you need
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

// You might find this handy.  I put it around unused parameters, but you should
// remove it before you submit. Just allows things to compile initially.
#define UNUSED(x) (void)(x)

typedef struct block_store
{
    bitmap_t* bitmap;
    uint8_t* blockInfo[BLOCK_STORE_NUM_BLOCKS][BLOCK_SIZE_BYTES];
} block_store_t;

block_store_t *block_store_create() /* block_store_create() creates a new Block Storage Device. The function returns the Block Storage Device as a struct block_store_t if it succeeds or NULL if it fails */
{
    block_store_t* block = (block_store_t*) calloc(1, sizeof(block_store_t)); // allocates memory for a Block Storage Device "block" (using calloc to avoid uninitialized values)
    if(block) // NULL check
    {
        block->bitmap = bitmap_create(BLOCK_STORE_NUM_BLOCKS); // calls bitmap_create() function proivded in "bitmap.c" in order to create a bitmap for the BLOCK_STORE_NUM_BLOCKS number of blocks our Block Storage Device.
        if(block->bitmap) // NULL check
        {
            for(size_t i = 0; i < BLOCK_STORE_NUM_BLOCKS; i++) // loops through the number of blocks our Block Storage Device has
            {
                bitmap_reset(block->bitmap, i); // calls bitmap_reset() function provided in "bitmap.c" in order to set the id "i" of our bitmap "block->bitmap" to 0
            }
            for(size_t i = 0; i < BITMAP_NUM_BLOCKS; i++) // loops through the number of blocks our bitmap has
            {
                bitmap_set(block->bitmap, BITMAP_START_BLOCK + i); // calls bitmap_set() function provided in "bitmap.c" in order to set the id "BITMAP_START_BLOCK+i" of our bitmap "block->bitmap" to 1
            }
        }
        return block; // successful return: return the Block Storage Device
    }
    return NULL; // default return: NULL
}

void block_store_destroy(block_store_t *const bs) /* block_store_destroy() destroys/frees our parameter Block Storage Device "bs". This function has a void return */ 
{
    if(bs) // NULL check
    {
        bitmap_destroy(bs->bitmap); // calls bitmap_destroy() function provided in "bitmap.c" in order to destroy/free our bitmap "bs->bitmap"
        free(bs); // frees the entire Block Storage Device
    }
}

size_t block_store_allocate(block_store_t *const bs) /* block_store_allocate() finds a free block in our Block Storage Device to then mark as in use. The function returns the block's id if successful or SIZE_MAX if it fails */
{
    if(bs && bs->bitmap) // NULL checks
    {
        size_t firstZeroBit = bitmap_ffz(bs->bitmap); // calls bitmap_ffz() function provided in "bitmap.c" in order to find the id of the first zero bit, i.e. a free block, in our bitmap "bs->bitmap"
        if(firstZeroBit < SIZE_MAX && firstZeroBit <= (BLOCK_STORE_NUM_BLOCKS - 1)) // checks to make sure the id number returned is valid
        { 
            bitmap_set(bs->bitmap, firstZeroBit); // calls bitmap_set() function provided in "bitmap.c" in order to set the block id "firstZeroBit" in our bitmap "bs->bitmap" to 1, i.e. in use
            return firstZeroBit; // successful return: return the block id in bitmap
        }
    }
    return SIZE_MAX; // default return: SIZE_MAX
}

bool block_store_request(block_store_t *const bs, const size_t block_id) /* block_store_request() "allocates" the requested block id "block_id" in our Block Storage Device "bs" by setting the block id to 1, i.e. in use. The function returns true if successful or false otherwise */
{
    if(bs && block_id < BLOCK_STORE_NUM_BLOCKS && bs->bitmap) // NULL check and valid id size check
    {
        if(!bitmap_test(bs->bitmap, block_id)) // checks if the return from our call to the bitmap_test() function provided in "bitmap.c" (which tests whether the block id "block_id" in our bitmap "bs->bitmap" is set) is NOT set, i.e. 0
        {
            bitmap_set(bs->bitmap, block_id); // sets the id to in use as described earlier
            if(bitmap_test(bs->bitmap, block_id)) // checks the return of the call to bitmap_test() as described earlier. However, now we want the return value to be 1, as the block id in the bitmap should be set now
            {
                return true; // successful return: true
            }
        }
    }
    return false; // default return: false
}

void block_store_release(block_store_t *const bs, const size_t block_id) /* block_store_release() frees the specified block id "block_id" from the bitmap of our Block Storage Device "bs". The function has a void return */
{
    if(bs && bs->bitmap) // NULL checks
    {
        bitmap_reset(bs->bitmap, block_id); // resets the id to not in use as described earlier
    }
}

size_t block_store_get_used_blocks(const block_store_t *const bs) /* block_store_get_used_blocks() counts the number of blocks marked as in use in our Block Storage Device "bs". The function returns the count if successful or SIZE_MAX upon failure */
{
    if(bs && bs->bitmap) // NULL check
    {
        return bitmap_total_set(bs->bitmap); // successful return: returns the count, which is the return value of the function call bitmap_total_set() provided in "bitmap.c", which counts the total number of blocks marked as in use in our bitmap "bs->bitmap" 
    }
    return SIZE_MAX; // default return: SIZE_MAX
}

size_t block_store_get_free_blocks(const block_store_t *const bs) /* block_store_get_free_blocks() counts the number of blocks marked as not in use in our Block Storage Device "bs". The function returns the count if successful or SIZE_MAX upon failure */
{
    if(bs && bs->bitmap)
    {
        bitmap_invert(bs->bitmap); // The bitmap_invert() function provided in "bitmap.c" inverts all the block id values in our bitmap "bs->bitmap"
        size_t freeBlocks = bitmap_total_set(bs->bitmap); // returns the total number of block ids marked as in use in our bitmap, as described earlier. Since we inverted the bitmap prior to this call, the return value of this function call is actually the number of not-set blocks
        bitmap_invert(bs->bitmap); // invert the bitmap again as described earlier so as not to mess up any future operations
        return freeBlocks; // successful return: count of number of free blocks in bitmap
    }
    return SIZE_MAX; // default return: SIZE_MAX
}

size_t block_store_get_total_blocks() /* block_store_get_total_blocks() returns the total number of user-addressable blocks */
{
    return BLOCK_STORE_NUM_BLOCKS; // successful return: the number of blocks in our Block Storage Device
}

size_t block_store_read(const block_store_t *const bs, const size_t block_id, void *buffer) /* block_store_read() reads data from the specified block id "block_id" from the bitmap of our Block Storage Device "bs" and writes it to the buffer "buffer". The function returns the number of bytes read if successful or 0 otherwise */
{
    if(bs && buffer && (block_id < BLOCK_STORE_NUM_BLOCKS)) // NULL checks and size check to ensure valid id number
    {
        memcpy(buffer, bs->blockInfo[block_id], BLOCK_SIZE_BYTES); // the built-in function memcpy() reads "BLOCK_SIZE_BYTES" number of bytes from "bs->blockInfo[block_id]" and copies the memory/writes the data to "buffer"
        return BLOCK_SIZE_BYTES; // successful return: the number of blocks read
    }
    return 0; // default return: 0
}

size_t block_store_write(block_store_t *const bs, const size_t block_id, const void *buffer) /* block_store_write() reads data from the "buffer" and writes it to the specified block id "block_id" from the bitmap of our Block Storage Device "bs". The function returns the number of bytes written to if successful or 0 otherwise */ 
{
    if(bs && buffer && (block_id < BLOCK_STORE_NUM_BLOCKS)) // NULL checks and size check to ensure valid id number
    {
        memcpy(bs->blockInfo[block_id], buffer, BLOCK_SIZE_BYTES); // memcpy() copies memory/writes data as described earlier, however this time, we are writing from the buffer to the block, theoretically writing in this sense as opposed to reading
        return BLOCK_SIZE_BYTES; // successful return: the number of blocks written
    }
    return 0; // default return: 0
}

block_store_t *block_store_deserialize(const char *const filename) /* block_store_deserialize() imports a Block Storage Device from a provided file "filename". The function returns the new Block Storage Device if successful or NULL upon failure */
{
    if(filename) // NULL check
    {
        int32_t fd = open(filename, O_RDONLY); // built-in function open() opens a file "filename" for read-only (O_RDONLY). The return of this function will be our file descriptor "fd"
        if(fd >= 0) // check if file was opened properly
        {
            block_store_t* block = (block_store_t*) calloc(1, sizeof(block_store_t)); // allocates a new Block Storage Device "block" using the built-in function calloc. We do not want to simply call block_store_create, as this will cause memory leak issues later with bitmap_import
            if(block) // NULL check
            {
                size_t isRead = read(fd, block, BLOCK_STORE_NUM_BYTES); // built-in function read() reads "BLOCK)STORE_NUM_BYTES" bytes from the file descriptor "fd" into the Block Storage Device "bs"
                if(isRead > 0) // checks to see if file was read in properly
                {
                    block->bitmap = bitmap_import(BITMAP_SIZE_BYTES, block); // the bitmap_import() function provided in "bitmap.c" will create a bitmap of "BITMAP_SIZE_BYTES" bytes using data from "block". As this function allocates a new bitmap, this is why we did not want to call block_store_create() earlier
                    if(block->bitmap) // NULL check
                    {
                        close(fd); // close file
                        return block; // successful return: Block Storage Device "block"
                    }
                }
                block_store_destroy(block); // destroys the block in the case that anything following would fail
            }
            close(fd); // close file
        }
    }
    return NULL; // default return: NULL
}

size_t block_store_serialize(const block_store_t *const bs, const char *const filename) /* block_store_serialize() writes the provided Block Storage Device "bs" to the given file "filename". The function returns the number of bytes written if successful or 0 upon failure */
{
    if(filename && bs) // NULL checks
    {
        int32_t fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644); // built-in function open() opens a file "filename" for write-only (O_WRONLY), or create (O_CREAT) if the file does not exist, or truncated (O_TRUNC) if the file exists but needs to be truncated. The mode 0644 allows the file's owner to read and write while allowing the file owner's group and all users to merely read. The return of this function will be our file descriptor "fd"
        if(fd >= 0) // check if file was opened properly
        {
            size_t isWritten = write(fd, bs, BLOCK_STORE_NUM_BYTES); // built-in function write() writes "BLOCK_STORE_NUM_BYTES" bytes from Block Storage Device "bs" to the file descriptor "fd"
            if(isWritten > 0) // checks to see if file was written to properly
            {
                close(fd); // closes file
                return isWritten; // successful return: the number of bytes written to, i.e. the return of the write() function
            }
            close(fd); // close file
        }
    }
    return 0; // default return: 0
}
