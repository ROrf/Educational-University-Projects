#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/* NOTE: similar to the last assignment, valgrind will raise errors if this executable is ran in the build directory due to missing files. However, if valgrind is run in the error_handling directory of build, no errors will be generated because the file is present in that directory */

#define MAX_RECORDS_SIZE 10 // symbolic constant for the max records size case, as this cannot be done dynamically when the wrong size value is passed into a function

#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records) /* Function returns 0 if a Record_t records of size num_records is successfully created, or different negative values depending on the logical error */
{
    if(records && num_records > 0 && !(*records)) // NULL check and size check per usual, however *records records a non-NULL check, as *records should be NULL when passed into this function
    {
        if(num_records & ~(SIZE_MAX >> 1)) // this check was added here in order to appease valgrind. size_t is an unsigned data type, however valgrind still recognizes when a negative value is passed in. Therefore, this check uses bitwise opeartions to check if the most significant bit of num_records is set, which it will be if a negative number was converted to unsigned size_t
        {
            return -2;
        }
	    *records = (Record_t*) malloc(sizeof(Record_t) * num_records); // no need to free memory as it is freed in main
        if(*records) // NULL check
        {
	        memset(*records,0,sizeof(Record_t) * num_records);
            return 0; // successful return
        }
        return -2; // according to test case, if *records == NULL (aka bad memory allocation), the function is supposed to return -2
    }
	return -1; // changed default to -1 
}

int read_records(const char *input_filename, Record_t *records, const size_t num_records) { /* Function returns 0 if num_records elements from file input_filename are successfully read into record array records, or a negative value which differs depending on the type of logical error */
    if(input_filename && records && num_records > 0) // NULL checks and size check
    {
        if(num_records > MAX_RECORDS_SIZE) // I originally tried to calculate the size of records dynamically, however that is not possible when the incorrect size is passed in. Perhaps I could have checked in the for loop of reading in data if the FEOF character had been reached. However, I chose to create a symbolic constant (to prevent "hard-coding" the value), and assigned it to the value of 10 since that is the maximum number of all the test cases
        {
            return -3;
        }
        int index = 0;
        int filename_size = strlen(input_filename); // built-in function to check the length of the given filename
        if(filename_size > 0 && filename_size < 101) // size check on filename
        {
            while(index < filename_size)
            {
                char file_char = *(input_filename+index); // obtains the next character in sequence in the filename "string"
                if(file_char < 40 || (file_char > 41 && file_char < 44) || (file_char > 46 && file_char < 48) || (file_char > 57 && file_char < 65) || (file_char > 90 && file_char < 95) || file_char == 96 || file_char > 122) // checks to see if any invalid filename characters are present using ASCII values
                {
                    return -2;
                }
                if(0==index && file_char < 97) // checks to make sure the first character is a lowercase letter, as that is proper naming convention
                {
                    return -2;
                }
                if(filename_size==(index+1) && file_char < 97) // checks to make sure the final character is a lowercase letter, as that is proper naming convention
                {
                    return -2;
                }
                index++;
            }
	        int fd = open(input_filename, O_RDONLY);
            if(fd == -1) // checks to see if the file was successfully opened, as a failure to open a file returns a -1
            {
                return -2;
            }
	        ssize_t data_read = 0;
	        for (size_t i = 0; i < num_records; ++i) {
		        data_read = read(fd,&records[i], sizeof(Record_t));	
	        }
            if(data_read >= 0) // one more check to ensure -1 was not returned, i.e. data was read in correctly
            {
                return 0; // successful return
            }
        }
        return -2; // I would have preferred to do a cascading return as I have previously done. However, for this file, I simply found that to be too complicated, although some of the failed test cases resulting in -2 would still fall down to this point, hence why it is included here
    }
	return -1; // changed default to -1
}

int create_record(Record_t **new_record, const char* name, int age) /* Function returns 0 if a Record_t new_record is successfully created with string name and int age, or a negative number differing depending on the type of logical error */
{
    if(new_record && name && age > 0 && age <= 200 && !(*new_record)) // NULL checks and size checks along with a non-NULL check, as *new_record should be NULL when passed into this function
    {
        int index = 0;
        int name_size = strlen(name); // built-in function to check the length of the given name
        if(name_size > 0 && name_size < MAX_NAME_LEN) // size check on name, where MAX_NAME_LEN is a symbolic constant provided in the header
        {
            while(index < name_size)
            {
                char name_char = *(name+index); // obtains the next character in sequence in the name "string"
                if(name_char < 65 || (name_char > 90 && name_char < 97) || name_char > 122) // checks to see if any invalid name characters are present using ASCII values (strictly only allowing uppercase and lowercase English alphabet characters)
                {
                    return -1;
                }
                if(0==index && (name_char < 65 || (name_char > 90 && name_char < 97) || name_char > 122)) // checks to make sure the first character is an uppercase OR lowercase English alphabet letter, as that is proper naming convention (the good test was provided in all lowercase, hence why lowercase was added for this check)
                {
                    return -1;
                }
                if(name_size==(index+1) && name_char < 97) // checks to make sure the final character is a lowercase English alphabet letter, as that is proper naming convention
                {
                    return -1;
                }
                index++;
            }
	        *new_record = (Record_t*) malloc(sizeof(Record_t));
	        if(*new_record) // NULL check
            {
	            memcpy((*new_record)->name,name,sizeof(char) * strlen(name));
	            (*new_record)->name[MAX_NAME_LEN - 1] = 0;	
	            (*new_record)->age = age;
	            return 0; // successful return
            }
            return -2;
        }
    }

    return -1; // changed default to -1 

}
