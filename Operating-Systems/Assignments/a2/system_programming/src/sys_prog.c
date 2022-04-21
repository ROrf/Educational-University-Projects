#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP

bool bulk_read(const char *input_filename, void *dst, const size_t offset, const size_t dst_size) /* function checks if dst_size bytes starting at offset are properly read into from input_filename into dst */
{
    if(input_filename) // NULL check to prevent seg fault when attempting to call functions using input_filename
    {
        uint32_t index = 0;
        uint32_t filename_size = strlen(input_filename); // built-in function to check the length of the given filename
        if(filename_size > 0 && filename_size < 101) // size check to prevent illegal filenames from being used in function calls
        {
            while(index < filename_size)
            {
                uint8_t file_char = *(input_filename+index); //obtains the next character in sequence in the filename "string"
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122) // checks to see if any invalid filename characters are present using ASCII values
                {
                    return false;
                }
                if(0==index && file_char < 97) // checks to make sure the first character is a lowercase letter, as that is proper naming convention
                {
                    return false;
                }
                if(filename_size==(index+1) && file_char < 97) // checks to make sure the final character is a lowercase letter, as that is proper naming convention
                {
                    return false;
                }
                index += 1;
            }
            uint32_t fd = open(input_filename, O_RDONLY); // built-in function to open a file, in this case for read-only, using a file descriptor instead of a file pointer
            if(dst && dst_size > 0 && offset >= 0 && offset <= dst_size && fd && fd >= 0) // NULL checks to prevent seg faults/any other function issues, size checks on the destination size and offset to ensure the function was provided valid sizes, and < 0  check on the file descriptor to ensure the file opened properly
            {
                if(lseek(fd, offset, 0) >= 0) // built-in function to move the location of the start of the read to the offset from the beginning (the 3rd argument of 0 indicates offset the 2nd argument from the beginning of the file descriptor). In the same step, we also check to make sure lseek() returns a value >= 0, as -1 indicates a failure
                {
                    if(read(fd, dst, dst_size) >= 0) // built-in function to move to read dst_size bytes into dst from the file descriptor fd. In the same step, we also check to make sure read() returns a value >= 0, as -1 indicates failure
                    {
                        close(fd);
                        return true;
                    }
                }
            }
        }
    }
    return false; // default return: false
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size) /* function checks if src_size bytes starting at offset are properly written into output_filename from src */
{
    if(output_filename) // NULL check to prevent seg fault when attempting to call functions using output_filename
    {
        uint32_t index = 0;
        uint32_t filename_size = strlen(output_filename); // built-in function to check the length of the given filename
        if(filename_size > 0 && filename_size < 101) // size check to prevent illegal filenames from being used in function calls
        {
            while(index < filename_size)
            {
                uint8_t file_char = *(output_filename+index); // obtains the next character in sequence in the filename "string"
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122) // checks to see if any invalid filename characters are present using ASCII values
                {
                    return false;
                }
                if(0==index && file_char < 97) // checks to make sure the first character is a lowercase letter, as that is proper naming convention
                {
                    return false;
                }
                if(filename_size==(index+1) && file_char < 97) // checks to make sure the final character is a lowercase letter, as that is proper naming convention
                {
                    return false;
                }
                index += 1;
            }
            uint32_t fd = open(output_filename, O_WRONLY); // built-in function to open a file, in this case for write-only, using a file descriptor instead of a file pointer
            if(src && src_size > 0 && offset >= 0 && fd && fd >= 0) // NULL checks to prevent seg faults/any other function issues, size checks on the source size and offset to ensure the function was provided valid sizes, and < 0 check on the file descriptor to ensure the file opened properly
            {
                if(lseek(fd, offset, 0) >= 0) // built-in function to move the location of the start of the write to the offset from the beginning (the 3rd argument of 0 indicates offset the 2nd argument from the beginning of the file descriptor). In the same step, we also check to make sure lseek() returns a value >= 0, as -1 indicates a failure
                {
                    if(write(fd, src, src_size) >= 0) // built-in function to move to write src_size bytes into the file descriptor fd from src. In the same step, we also check to make sure write() returns a value >= 0, as -1 indicates failure
                    {
                        close(fd);
                        return true;
                    }
                }
            }
        }
    }
    return false; // default return: false
}


bool file_stat(const char *query_filename, struct stat *metadata) /* function checks if the metadata stats from the file query_filename are correctly read into the variable metadata */
{
    if(query_filename) // NULL check to prevent seg fault when attempting to call functions using query_filename
    {
        uint32_t index = 0;
        uint32_t filename_size = strlen(query_filename); // built-in function to check the length of the given filename
        if(filename_size > 0 && filename_size < 101) // size check to prevent illegal filenames from being used in function calls
        {
            while(index < filename_size)
            {
                uint8_t file_char = *(query_filename+index); // obtains the next character in sequence in the filename "string"
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122) // checks to see if any invalid filename characters are present using ASCII values
                {
                    return false;
                }
                if(0==index && file_char < 97) // checks to make sure the first character is a lowercase letter, as that is proper naming convention
                {
                    return false;
                }
                if(filename_size==(index+1) && file_char < 97) // checks to make sure the final character is a lowercase letter, as that is proper naming convention
                {
                    return false;
                }
                index += 1;
            }
            uint32_t fd = open(query_filename, O_RDONLY); // built-in function to open a file, in this case for read-only, using a file descriptor instead of a file pointer
            if(metadata && fd) // NULL checks to prevent seg faults/any other function issues
            {
                if(fstat(fd,metadata) >= 0) // built-in function to read the stats in the file descriptor fd into metadata. In the same step, we also check to make sure fstat() returns a value >= 0, as -1 indicates failure
                {
                    close(fd);
                    return true;
                }
            }
        }
    }
    return false; // default return: false
}

bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count)
{   
    if(src_data && dst_data && src_count > 0) // NULL checks to prevent seg faults/any other function issues and size check on the source count to ensure the function was provided a valid size
    {
        uint32_t index = 0;
        while(index < src_count) // loops through the number of elements src_count to be swapped and stored
        {
            uint32_t temp = *(src_data+index); // temp variable is created equal to the current index of the src_data
            temp = (((temp << 24) & 0xFF000000) | ((temp << 8) & 0x00FF0000) | ((temp >> 8) & 0x0000FF00) | ((temp >> 24) & 0x000000FF)); // bits are swapped to convert the endian format
            *(dst_data+index) = temp; // the temp value is stored into the current index of the dst_data
            index += 1; // manual increment since a while loop was used
        }
        return true;
    }
    return false; // default return: false
}

