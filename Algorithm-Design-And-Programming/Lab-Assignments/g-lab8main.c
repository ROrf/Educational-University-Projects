//Ryan Orf
//rconzc
#include<stdio.h> //header

#define TEST1 "Jim Ries...Is1234Cool" //symbolic constants
#define TEST2 "cs1050is great"
#define TEST3 ""
#define TEST4 "!!!#123Once\tThere_was a way\nto^get((back))homeward.123\n"
#define NTH1 0
#define NTH2 3
#define NTH3 5
#define NTH4 7 

void toUpperWord(char *string, int n); //prototype for function in other file

int main(void) //main
{
    char test1[] = TEST1, test2[] = TEST2, test3[] = TEST3, test4[] = TEST4;
    //must be able to change strings, but I still used symbolic constants in case any of the test should be changed while grading since it is more convenient
    printf("\n\n****Original test string #1: %s\n", test1); //original string output formatted as shown
    toUpperWord(test1, NTH1); //first of 16 call functions
    toUpperWord(test1, NTH2);
    toUpperWord(test1, NTH3);
    toUpperWord(test1, NTH4);
    printf("\n\n****Original test string #2: %s\n", test2);
    toUpperWord(test2, NTH1);
    toUpperWord(test2, NTH2);
    toUpperWord(test2, NTH3);
    toUpperWord(test2, NTH4);
    printf("\n\n****Original test string #3: %s\n", test3);
    toUpperWord(test3, NTH1);
    toUpperWord(test3, NTH2);
    toUpperWord(test3, NTH3);
    toUpperWord(test3, NTH4);
    printf("\n\n****Original test string #4: %s\n", test4);
    toUpperWord(test4, NTH1);
    toUpperWord(test4, NTH2);
    toUpperWord(test4, NTH3);
    toUpperWord(test4, NTH4);
}
