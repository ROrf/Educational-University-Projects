#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) /* function checks if a provided string str of size length contains a NULL terminator */
{
    if(str && length > 0) // NULL check to prevent seg faults/any other function issues, and length > 0 check, as this function checks for if a string contains a NULL terminator, and even an empty string will contain the NULL terminator
    {
        for(int index = 0; index < length; index++) // loops through all the characters in a string, including the NULL terminator if it exists
        {
            if('\0'== *(str+index)) // check if the current character is the NULL terminator
            {
                return true;
            }
        }
    }
    return false; // default return: false
}

char *string_duplicate(const char *str, const size_t length) /* function returns a duplicate of string str of size length */
{
    if(str && length > 0) // NULL check to prevent seg faults/any other function issues, and length > 0 check, as even an empty string will contain the NULL terminator
    {
        char *duplicate = malloc(length*sizeof(char)); // dynamic character pointer memory must be malloced as opposed to declaring an array, however the test will free this pointer as there is no way to free memory in a function after returning it in C
        memcpy(duplicate,str,length); // built-in function to copy length bytes of str into duplicate
        if(0==memcmp(str,duplicate,length)) // built-in function to compare length bytes of str and duplicate, which returns 0 if they are equal
        {
            return duplicate;
        }
    }
    return NULL; // default return: NULL
}

bool string_equal(const char *str_a, const char *str_b, const size_t length) /* function checks if strings str_a and str_b of size length are equal */
{
    if(str_a && str_b && length > 0) // NULL check to prevent seg faults/any other function issues, and length > 0 check, as even an empty string will contain the NULL terminator
    {
        if(0==memcmp(str_a,str_b,length)) // built-in function to compare length bytes of str_a and str_b, which returns 0 if the are equal
        {
            return true;
        }
    }
    return false; // default return: false
}

int string_length(const char *str, const size_t length) /* function returns the length of string str (the length parameter is used to ensure the input is a string, i.e. it contains a NULL terminator) */
{
    if(str && length > 0) // NULL check to prevent seg faults/any other function issues, and length > 0 check, as even an empty string will contain the NULL terminator
    {
        return strlen(str); // built-in function that returns the length of str (not including the NULL terminator in this instance)
    }
    return -1; // default return: -1
}

int string_tokenize(const char *str, const char *delims, const size_t str_length, char **tokens, const size_t max_token_length, const size_t requested_tokens) /* function returns the number of tokens produced by a string. This function is more complex, as it takes a string str of size str_length and copies substrings separated by delimiter delims into tokens. There are requested_tokens number of tokens, and each token has a size of max_token_length */
{
    if(str && delims && str_length > 0 && tokens && max_token_length > 0 && requested_tokens > 0) // NULL check to prevent seg faults/any other function issues, and length/token length/requested tokens > 0 check, as even empty strings will contain the NULL terminator and we have to return at least one of something
    {
        for(int i = 0; i < requested_tokens; i++) // loops through all the number of requested tokens
        {
            if(!(tokens[i])) // NULL check, as any NULL token indicates inadequate token allocation and is supposed to return -1
            {
                return -1;
            }
        }
        int str_index = 0;
        int token_num = 0;
        int token_char = 0;
        while(str_index < str_length) // looping through characters in a string
        {
            if(0==memcmp(delims,str+str_index,sizeof(char))) // DELIMITER CHECK: built-in function to compare sizeof(char)/1 byte(s) of str+str_index (which acts as the current character in the string) and the delimiter, returning a 0 if they are equal
            {
                token_char = 0; // resets the index of the token as a new token will be started
                if((token_num+1) >= requested_tokens) // sets the str_index to the str_length, conceptually ending the loop, if the program is supposed to move onto the next token but the number of requested_tokens has been obtained
                {
                    str_index = str_length;
                }
                else // increments which token the program is on if the requested_tokens has not been obtained
                {
                    token_num += 1;
                }
            }
            else // runs if the deliminator is not detected for the current character
            {
                if(token_char < max_token_length) // checks if the program has surpassed the number of characters allowed in a token before a detected delimiter
                {
                    memcpy(&(tokens[token_num][token_char]),(str+str_index),sizeof(char)); // built-in function to copy sizeof(char)/1 byte(s) of content from str+str_index (the current character of the string) into the current character value of the current token
                    token_char += 1; // increment to the next character in the token to coincide with the next character in the string
                }
            }
            str_index += 1; // manual increment since I used a while loop
        }
        return token_num+1; // token_num has to be incremented once more before being returned as when my loop terminates, either due to having reached the number of tokens or the end of the string, token_num will read one less than the number of tokens (since we index starting at 0)
    }
    return 0; // default return value: 0
}

bool string_to_int(const char *str, int *converted_value) /* function checks if string str was correctly converted into an integer converted_value */
{
    if(str && converted_value) // NULL check to prevent seg faults/any other function issues
    {
        *converted_value = atoi(str); // built-in function to convert str into a stored int value (converted_value)
        if(-1== *converted_value) // checks if the string-to-int conversion failed
        {
            *converted_value = 0; // alters failed instances to 0, per requirements
            return false;
        }
        return true;
    }
    return false; // default return: false
}
