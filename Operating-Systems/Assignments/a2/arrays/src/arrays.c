#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count) /* function checks if elem_count elements of size elem_size of array src are correctly copied into array dst */
{
    if(src && dst && elem_size > 0 && elem_count > 0) // NULL check to prevent seg faults/other function call issues
    {
        memcpy(dst,src,elem_size*elem_count); // built-in function to copy contents of src into dst up to size*count bytes
        if(0==memcmp(src,dst,elem_size*elem_count)) // built-in function to compare src and dst up to size*count bytes and, if they are equal (0), then true is returned from the function
        {
            return true;
        }
    }
    return false; // default return: false
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count) //* function checks if two arrays (data_one and data_two) of elem_count elements of size elem_size are equal */
{
    if(data_one && data_two && elem_size > 0 && elem_count > 0) // NULL check to prevent seg faults/other function call issues
    {
        if(0==memcmp(data_one,data_two,elem_size*elem_count)) // built-in function to compare data_one and data_two up to size*count bytes and, if they are equal (0), then true is returned from the function
        {
            return true;
        }
    }
    return false; // default return: false

}

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) /* function returns the index of an element target in an array of elem_count elements of size elem_size if found, or -1 otherwise */
{
    if(data && target && elem_size > 0 && elem_count > 0) // NULL check to prevent seg faults/other function call issues
    {
        ssize_t index = 0;
        while(index < elem_count) // loops through indices in the data
        {
            if(0==memcmp(target,data+(elem_size*index),elem_size)) // built-in function to compare target and the (conceptually) current value of the data, only up to size bytes. If the target is found in the data, memcmp will return 0, and the current index will be returned from the function 
            {
                return index;
            }
            index += 1; // manual index increment since a while loop was used
        }
    }
    return -1; // default return: -1 (index does not exist)
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) /* function checks if elem_count elements of elem_size bytes of an array src_data are correctly written into a binary file dst_file */
{
    if(dst_file) // NULL check to prevent seg fault when attemtping to call functions using dst_file
    {
        ssize_t index = 0; 
        ssize_t filename_size = strlen(dst_file); // built-in function to check the length of the given filename
        if(filename_size > 0 && filename_size < 101) // size check to prevent illegal filenames from being used in function calls
        {
            while(index < filename_size)
            {
                char file_char = *(dst_file+index); // obtains the next character in sequence in the filename "string" 
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122) // checks to see if any invalid filename characters are present using ASCII values (could probably be optimized)
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
                index += 1; // manual index increment since a while loop was used
            }
            FILE *fp; 
            fp = fopen(dst_file, "wb"); // opens file "dst_file" using wb for writing in binary
            if(src_data && elem_size > 0 && elem_count > 0 && fp) // NULL check to prevent seg faults/other function call issues
            {
                fwrite(src_data, elem_size*elem_count, 1, fp); // built-in function to write the contents of src_data up to size*count bytes to the file pointer fp. The 3rd argument is 1 because we are reading in the entire array in one go instead of a certain number of elements, hence why we wrote in size*count bytes in the 2nd argument instead of just size bytes
                fclose(fp);
                return true; // in theory returns true if file was written to properly
            }
            fclose(fp);
        }
    }
    return false; // default return: false
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) /* function checks if elem_count elements of elem_size bytes of a binary file src_file are correctly read into an array dst_data */
{
    if(src_file) // NULL check to prevent seg fault when attempting to call functions using src_file
    {
        ssize_t index = 0;
        ssize_t filename_size = strlen(src_file); // not going to copy over the comments as well, but I could have modularized the filename checking into its own function to avoid this repetition
        if(filename_size > 0 && filename_size < 101)
        {
            while(index < filename_size)
            {
                char file_char = *(src_file+index);
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122)
                {
                    return false;
                }
                if(0==index && file_char < 97)
                {
                    return false;
                }
                if(filename_size==(index+1) && file_char < 97)
                {
                    return false;   
                }
                index += 1;
            }
            FILE *fp;
            fp = fopen(src_file, "rb"); // open file "src_file" using rb for reading in binary
            if(dst_data && elem_size > 0 && elem_count > 0 && fp)
            {
                fread(dst_data, elem_size*elem_count, 1, fp); // built-in function to read size*count bytes from the file pointer fp into the contents of dst_data. The 3rd argument is 1 because we are reading in the entire array in one go instead of a certain number of elements, hence why we read in size*count bytes in the 2nd argument instead of just size bytes
                fclose(fp);
                return true; // in theory returns true if file was read in properly
            }
            fclose(fp);
        }
    }
    return false; // default return: false
}

