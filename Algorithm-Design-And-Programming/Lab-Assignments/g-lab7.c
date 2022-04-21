//Ryan Orf
//rconzc
#include<stdio.h> //header

void getString(char *string); //prototypes
void stringReplace(char *original, char *pattern, char *replacement);

int main(void) //main
{
    char original[256], pattern[32], replacement[32]; //defined as char arrays with size
    printf("*** Welcome to Lab 7 ***\n");
    printf("Please enter the original string: ");
    getString(original);
    printf("Original string = %s\n", original);
    printf("Please enter the pattern: ");
    getString(pattern);
    printf("Pattern string = %s\n", pattern);
    printf("Please enter the replacement: ");
    getString(replacement);
    printf("Replacement string = %s\n", replacement);
    stringReplace(original, pattern, replacement);
    printf("\nThe resultant string is %s\n", original);
    printf("*** Thanks for doing Lab 7 ***\n");
}

void getString(char *string) //method for obtaining user input strings
{
    scanf("%s", string); //scanf not in main
}
//method to replace pattern
void stringReplace(char *original, char *pattern, char *replacement)
{
    int patternLength = 0, replacementLength = 0; //need lengths, they can differ
    while(*pattern != '\0') //while moves pattern and will increment length
    {
        patternLength++;
        pattern++;
    }
    pattern -= patternLength; //have to ensure pattern is pointing back to the start of the string
    while(*replacement != '\0')
    {
        replacementLength++;
        replacement++;
    }
    replacement -= replacementLength; //same as before
    int true = 0; //true condition to be used later
    int i = 0; //i intialized to 0 so original starts at beginning
    while(*(original+i) != '\0') //end of string
    {
        if(*(original+i) == *pattern) //only if equal to first letter
        {
            for(int j = 0; j < patternLength; j++) //checks if equal
            {
                if(*(original+i+j) != *(pattern+j)) //not equal
                {
                    true = 0; //sets true=0 before break so no replacement occurs
                    break; //exits for
                }
                true = 1; //true is true
            }
            if(true == 1) //aka if pattern is found in original
            {
                for(int j = 0; j < replacementLength; j++)
                {
                    *(original+i+j) = *(replacement+j); //replaces original with replacement
                }
            }
        }
        i++; //increments i
    }
}
