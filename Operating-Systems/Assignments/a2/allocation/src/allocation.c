#define _GNU_SOURCE // needed to be added in order to use getline() (or else I get an implicit declaration warning)
#include "../include/allocation.h"
#include <stdlib.h>
#include <stdio.h>

/* NOTE: valgrind will most likely raise two warnings about an invalid file descriptor (-1) being used in sys calls write() and close(). After going to office hours, we deduced that these warnings are most likely issues with the test, as the read_line_to_buffer() function does not use these functions and the test file does */

void* allocate_array(size_t member_size, size_t nmember,bool clear) /* Function returns an array of nmember members of member_size size if a void* array was allocated, or NULL otherwise */
{
    if((int)member_size > 0 && (int)nmember > 0) // size check with casting, in order to appease valgrind (else we get fishy, possibly negative, value errors due to the tests)
    {
        void* array; 
        if(clear) // check if the test wants the array to be cleared, i.e. the parameter "clear" is true
        {
            array = calloc(nmember, member_size); // uses built-in function calloc() to allocate memory for an array and automatically clear the values
        }
        else
        {
            array = malloc(nmember * member_size); // uses built-in function malloc() to only allocate memory for an array
        }
        return array; // successful return
    }
    return NULL; // default return
}

void* reallocate_array(void* ptr, size_t size) /* Function returns the reallocated array if successful, or NULL otherwise */
{ 
    if(ptr && (int)size > 0) // NULL check and size check with casting, in order to appease valgrind (else we get fishy, possibly negative, value errors due to the tests)
    {
        return realloc(ptr, size); // successful return, which calls the built-in function realloc() to reallocate array ptr of size size (this is where I get a memory leak due to the ZeroBytes case. However, after going to office hours, we determined it is most likely due to the free() being commented out on line 51 of the test file, which I have uncommented)
    }
    return NULL; // default return 
}

void deallocate_array(void** ptr) /* Function deallocates the array ptr */
{
    if(ptr) // NULL check
    {
        free(*ptr); // built-in function free() to deallocate the array *ptr
        *ptr = NULL; // sets the value of ptr to NULL after freeing the array to ensure no value is retained at that memory location
    }
}

char* read_line_to_buffer(char* filename) /* Function returns the line read in to the buffer from the file filename, or NULL otherwise */
{
    FILE *fp = fopen(filename, "r"); // built-in function to open the file filename for read-only ("r") and setting the file pointer fp to the result
    if(fp) // NULL check
    {
        char* buffer = NULL; // declaration of the buffer string to be returned
        size_t buffSize = 0; // declaration of a buffer size to be used in the function getline()
        int value = getline(&buffer, &buffSize, fp); // built-in function getline() reads a line from file pointer fp into character array/string buffer and changes the size buffSize to match the length of the string (buffSize is only used to make this function call). The return value of getline() is set equal to int value
        fclose(fp); // built-in function to close the open file pointer fp
        if(value != (-1)) // check to make sure getline() did not fail, as getline() returns -1 if a line failed to be read in
        {
            return buffer; // successful return
        }
    }
    return NULL; // default return
}
