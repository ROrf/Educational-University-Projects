//Ryan Orf
//rconzc
#include<stdio.h> //headers
#include<ctype.h>

void toUpperWord(char *string, int n) //function called in main
{
   int wordnum = 1, start = 0, end = 0, i = 0, found = 0; //each variable has a specific purpose, with wordnum and i as increment variables and the other three as indicators of the nth word
   while(string[i] != '\0') //end of string
   {
       if(isalpha(string[i])) //only counts if it is the first letter of the string
        {
            if(wordnum == n) //only if nth word
            {
                start = i; //start index for later
                found = 1; //variable indicating the nth word was found
            }
            while(isalpha(string[i])) //loops until the end of the word
            {
                i++;
            }
            if(wordnum == n) //only if nth word
            {
                end = i; //end index for later
            }
            wordnum++; //increments word number after a completed word 
        }
       i++; //increments index
   }
   if(found) //only occurs if nth word is found
   {
        for(int i = start; i < end; i++) //for loop to upper the entire word
        {
            string[i] = toupper(string[i]);
        }    
   }
   else //only occurs if nth word is not found
   {
       printf("**ERROR: The %dth word was not found in string %s\n", n, string); //error message formatted as shown
   }
   printf("After trying word %d: \"%s\"\n", n, string); //prints new, manipulated string
}

