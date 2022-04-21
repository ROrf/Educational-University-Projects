#include "../include/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* FOR THIS SOURCE CODE, SINCE CODE ALREADY EXISTS AND I AM DEBUGGING, I WILL BE COMMENTING THE CHANGES I MADE */

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) { /* Function returns the difference of the value stored in a and the value stored in b */
    return *((uint16_t *)a) - *((uint16_t *)b); // for this line, I made five changes (with two instances where two were the same). The first change I made was to add an asterisk ("*") after the data type before casting a. This is because the parameter of a is a pointer so it must be cast to a pointer, similar to how b was already. Then, I changed both a and b to be cast to a "uint16_t" instead of a "uint8_t", as uint16_t was the data type used in the terrible_sort() function. Finally, both a and b had to be dereferenced in order to obtain their values, that way we were not trying to perform subtraction upon locations in memory, so the variables and castings were enclosed in parentheses and an asterisk ("*") was added before each set of parentheses
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) { /* Function returns true if value_count number of elements in the array data_array is sorted correctly, or false if it is not or some step fails */
    if(data_array && value_count > 0) // I added this NULL and size check as has become tradition in these files. The compiler could throw an error if data_array is NULL or value_count <= 0, and they are used in function calls or other operations
    {
        uint16_t *sorting_array = (uint16_t*)(malloc(value_count * sizeof(uint16_t))); // The first change I made was moving the asterisk ("*") from directly in front of the equal sign ("=") to directly in front of "sorting_array". "*=" implies that you are multiplying the right-hand to an already existing left-hand, whereas "*sorting_array" simply declares an array with name "sorting_array", which is what is desired. Next, the malloc operation is enclosed in parentheses and is cast as a (uint16_t*) to ensure that data types match up, as malloc returns a void type. Finally, "*data_array" is replaced with "uint16_t" in the sizeof() function. While data_array is an array of type uint16_t, dereferencing the pointer would give us the first number in the array, not the data type, and since we know the data type is uint16_t, we fill that in
        if(sorting_array) // Added another NULL check to ensure malloc worked
        {
            for (size_t i = 0; i < value_count; i++) 
            { // I changed i from "int" to "size_t", as make raises a warning of comparing signed and unsigned values. Unnecessarily, I changed "++i" to "i++" strictly because I like using the post-increment more whenever possible. This was not a bug that affected the program's outcome. I also moved the open brace down a line which, once again, has no impact on the success of the program
                sorting_array[i] = data_array[i];
            }

            qsort(sorting_array, value_count, sizeof(uint16_t), comparator_func); // This line was missing a semicolon, so first I added one. Additionally, accoridng to online documentation, the third argument of the qsort() function should be the size in bytes of each element in the array, NOT the number of elements in the array (which is what "sizeof(sorting_array) / sizeof(uint16_t)" would return), therefore the third argument was replaced by "sizeof(uint16_t)"

            bool sorted = true;
            for (size_t i = 0; i < value_count-1; i++) // I made 5 changes to this line of the for loop, 2 of which were necessary. First, I ended the loop at "value_count-1" instead of "value_count". This is because looping to compare two array elements, we have to either start at the second element or end at the second to last, or else we will try to pull data from outside the bounds of the array. Personally, I would start at 1, but to keep the integrity of the code that already existed, I ended at value_count-1. Second, I added the second semicolon, as it was missing. I also changed i to "size_t" instead of "i", as make raises a warning since a comparison will be made between signed and unsigned values if i remained an int. As for unnecessary changes, just as before, I changed "++i" to "i++" and moved the open brace down to its own line
            {
                if(sorting_array[i] > sorting_array[i+1]) // I have no clue what the first implementation was even attempting to do. It made a comparison between the current element of sorting_array and the next, however we need to check if the previous element is greater than, not less than. Additionally, "&=" was used, which is a bitwise operator. Only an equal sign ("=") should be used. Finally, this right-hand comparison was "&="ed to the left-hand "sorted", which is a boolean value which can only be set to true or false. With all those in mind, here is my implementation. I check if the current element is greater than the next and set "sorted" equal to false if that is the case
                {
                    sorted = false;
                    break; // We need to break if at any point any of these is false, or else the program could falsely assume the whole array is sorted correctly if only the second to last element is less than the last element
                }
            }   

            if (sorted) { // Need to check if sorting failed at any point, i.e. sorted is no longer true
                memcpy(data_array, sorting_array, value_count*sizeof(uint16_t)); // The entirety of the original memcpy() implementation was wrong. For starters, the first and second arguments were backwards, as the first should be the destination and the second should be the source. Additionally, data_array was initially dereferenced, which is definitel incorrect. Finally, the third argument is supposed to be the number of bytes, not the number of elements, so value_count was multiplied by "sizeof(uint16_t)" 
                free(sorting_array); // Need to free allocated data that will be unused in main to prevent memory leaks. Free is called before the true return as free would not have been called otherwise since the function reached a return, so this would have caused a memory leak if left out
                return true; // If the array exists and is sorted correctly, the program can finally return true
            }
        }
        free(sorting_array); // Need to free allocated data that will be unused in main to prevent memory leaks, so this call will free the array we created to check if data_array was sorted if something fails anywhere along the line
    }
    return false; // I changed the default return case to false instead of the sorted array, as this matches previous 
}

