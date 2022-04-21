#include "../include/bitmap.h"

// data is an array of uint8_t and needs to be allocated in bitmap_create
//      and used in the remaining bitmap functions. You will use data for any bit operations and bit logic
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create


bitmap_t *bitmap_create(size_t n_bits) /* functions returns a bitmap (using the bitmap_t struct from ../include/bitmap.h) of size n_bits bits if a bitmap can be created */
{
    if(n_bits > 0 && n_bits < SIZE_MAX) // size check to ensure the function was provided a valid number of bits n_bits
    {
        bitmap_t *bitMap = malloc(sizeof(bitmap_t)); // creation of bitmap struct
        if(bitMap) // NULL check to prevent seg faults/any other function issues
        {
            bitMap->bit_count = n_bits; // initializing the number of bits (bit_count) of the bitmap to the number of bits parameter n_bits
            if((n_bits%8) != 0) // need to check if the provided number of bits, n_bits, is divisible by 8 (number of bits in a byte) because...
            {
                bitMap->byte_count = (n_bits/8) + 1; // if n_bits is NOT divisible by 8, the number of bytes (byte_count) of the bitmap needs to be initialized to one more than n_bits/8
            }
            else
            {
                bitMap->byte_count = (n_bits/8); // if n_bits is divisible by 8, the number of bytes (byte_count) of the bitmap can be initialized to exactly n_bits/8
            }
            bitMap->data = malloc(bitMap->byte_count); // creation of data "array" of the bitmap
            size_t i;
            for(i = 0; i < bitMap->byte_count; i++) // initializing all values of data to 0 to prevent potential uninitialized value errors
            {
                bitMap->data[i] = 0;
            }
            return bitMap;
        }
    }
    return NULL; // default return: NULL/"nullptr"
}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit) /* function checks whether the bit was set correctly in the bitmap */
{
    if(bitmap && bit >= 0 && bit < bitmap->bit_count) // NULL check to prevent seg faults/any other function issues, and size checks to ensure the function was provided a valid size bit
    {
        uint8_t *bitPoint = bitmap->data + (bit/8); // creates a pointer to the start of the data. (bit/8) is added to start on the correct byte
        uint8_t mask = 0x01 << (bit%8); // creates mask to set bit using shift. (bit%8) is required since C can only go down to bytes, and there are 8 bits in a byte
        *bitPoint = *bitPoint | mask; // applying the mask. The '|' sets the bit in bit operations
        return true;
    }
	return false; // default return: false
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) /* function checks whether the bit was reset correctly in the bitmap */
{
    if(bitmap && bit >= 0 && bit < bitmap->bit_count) // NULL check to prevent seg faults/any other function issues, and size checks to ensure the function was provided a valid size bit
    {
        uint8_t *bitPoint = bitmap->data + (bit/8); // creates a pointer to the start of the data. (bit/8) is added to start on the correct byte
        uint8_t mask = 0xFF ^ (0x01 << (bit%8)); // creates mask to reset bit. As done earlier, we shift and use (bit%8) since C can only go down to bytes and there are 8 bits in a byte, however since we are resetting, the mask needs to be flipped (the '^' toggles the bit in bit operations, hence flipping)
        *bitPoint = *bitPoint & mask; // applying the mask. The '&' clears the bit in bit operations, hence resetting
        return true;
    }
    return false; // default return: false
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) /* function returns the state of the requested queried bit (bit) in the bitmap */
{
    if(bit && bit >= 0 && bit < bitmap->bit_count) // NULL check to prevent seg faults/any other function issues, and size checks to ensure the function was provided a valid size bit
    {
        uint8_t byteValue = *(bitmap->data + (bit/8)); // creates a byteValue of the dereferenced pointer to the start of the data. (bit/8) is added to start on the correct byte
        uint8_t mask = 0x01 << (bit%8); // creates mask to the set bit value we used earlier. This will help us determine the state of the requested queried bit when we apply the mask by allowing us to check if the byte is > 0
        byteValue = byteValue & mask; // applying the mask. The '&' clears the bit in bit operations, resetting the bit's value in byteValue to the value of the mask so we can test the specified bit
        if(byteValue > 0) // check on the byteValue to test the state of the requested queried bit. Since we are using a byte value as opposed to a bit, we can check if the byte value is greater than 0. This was not done earlier as bits can only hold a value of 0 and 1. However a byte is comprised of 8 bits
        {
            return true;
        }
    }
    return false; // default return: false
}

size_t bitmap_ffs(const bitmap_t *const bitmap) /* function returns the first set/1 bit in the bitmap, or SIZE_MAX if a set/1 bit is not present */
{
    if(bitmap) // NULL check to prevent seg faults/any other function issues
    {
        uint8_t *bytePoint = bitmap->data; // creates a pointer to the start of the data
        size_t bitValue = 0; // bit value control variable for current total bit 
        size_t byteNum = 0; // byte number control variable for current byte
        size_t bitNum = 0; // bit number control variable for current bit within the current byte
        size_t bitCount = bitmap->bit_count; // bit count control variable to ensure that we do not evaluate any excess bits in case the last byte is not completely filled with 8 bits
        while(byteNum < bitmap->byte_count) // outer loop to go through the bytes of the bitmap
        {
            while(bitNum < 8) // inner loop to go through the bits of the byte
            {
                if(bitCount <= 0) // checks if we have exceeded the total number of bits that we want in the bitmap (bitCount is decremented, starting at the total number of bits to evaluate)
                {
                    return SIZE_MAX; // failure if we have reached the total number of bits in the bitmap (once again, there could be excess bits in the last byte)
                }
                if(bytePoint[byteNum] & (1<<bitNum)) // checks if the current bit within the current byte is a 1
                {
                    return bitValue; // return the current bit value since we want the instance of the first set/1 bit
                }
                bitValue += 1;
                bitNum += 1;
                bitCount -= 1;
            }
            bitNum = 0; // need to reset the current bit number since we are moving onto a new byte
            byteNum += 1;
        }
    }
    return SIZE_MAX; // default return: SIZE_MAX, indicating not found
}

size_t bitmap_ffz(const bitmap_t *const bitmap) /* function returns the first zero bit in the bitmap, or SIZE_MAX if a zero bit is not present */
{
    if(bitmap) // NULL check to prevent seg faults/any other funciton issues
    {
        uint8_t *bytePoint = bitmap->data; // creates a pointer to the start of the data
        size_t bitValue = 0; // bit value control variable for current total bit
        size_t byteNum = 0; // byte number control variable for current byte
        size_t bitNum = 0; // bit number control variable for current bit within the current byte
        size_t bitCount = bitmap->bit_count; // bit count control variable to ensure that we do not evaluate any excess bits in case the last byte is not completely filled with 8 bits
        while(byteNum < bitmap->byte_count) // outer loop to go through the bytes of the bitmap
        {
            while(bitNum < 8) // inner loop to go through the bits of the byte
            {
                if(bitCount <= 0) // checks if we have exceeded the total number of bits that we want in the bitmap (bitCount is decremented, starting at the total number of bits to evaluate)
                {
                    return SIZE_MAX; // failure if we have reached the total number of bits in the bitmap (once again, there could be excess bits in the last byte)
                }
                if(bytePoint[byteNum] & (1<<bitNum)) // checks if the current bit within the current byte is a 1. I tried implementing evaluating at 0 and failed, but since bits can only be 0 or 1, I figured why don't I just test based off of 1 again and put the return in the else?
                {
                    bitNum += 1; // I also incremented variables here so that the if was not empty, however these could have also been placed after the if/else. This placement has no impact on the computation
                    bitValue += 1;
                    bitCount -= 1;
                }
                else 
                {
                    return bitValue; // return the current bit value since we want the instance of the first zero bit, and since bits can only be 0 or 1, if the bit is not a 1 it must be a 0
                }
            }
            bitNum = 0;
            byteNum += 1;
        }
    }
    return SIZE_MAX; // default return: SIZE_MAX, indicating not found
}

bool bitmap_destroy(bitmap_t *bitmap) /* function checks if the bitmap and its data was correctly freed */
{
    if(bitmap) // NULL check to prevent seg faults/any other function issues
    {
        if(bitmap->data) // NULL check on the data to prevent seg faults/any other function issues
        {
            free(bitmap->data);
        }
        free(bitmap);
        return true;
    }
    return false; // default return: false
}
