//Ryan Orf
//rconzc
#include<stdio.h> 
#define SIZE 31 //symbolic constant to set size of char arrays (strings)

void getPromptString(char* output); //prototypes
void promptAndGetFloat(char* prompt, float* output, float upperLimit, float lowerLimit);
void getQuotient(float divisor, float dividend, float* quotient);

int main(void) //main
{
    char string1[SIZE], string2[SIZE];
    float *dividend, *divisor, *quotient, upperLimit = 71.400002, lowerLimit = -123.199997, ex1 = 1, ex2 = 1, ex3 = 1; //upper and lower limit instantiated to that of the 'first variable', and the ex variables are used to allocate dividend, divisor, and quotient to memory locations
    dividend = &ex1;
    divisor = &ex2;
    quotient = &ex3;
    printf("\nEnter a prompt for the first variable:: ");
    getPromptString(string1);
    printf("Enter a prompt for the second variable:: ");
    getPromptString(string2);
    if(string1[4] == 'd' || string1[4] == 'D') //error checking to see if first variable was "Dividend" or "Divisor"
    {
        promptAndGetFloat(string1, dividend, upperLimit, lowerLimit);
        upperLimit = 6.100000; //changes limits for divisor
        lowerLimit = -5.500000;
        promptAndGetFloat(string2, divisor, upperLimit, lowerLimit);
    }
    else
    {
        promptAndGetFloat(string2, dividend, upperLimit, lowerLimit);
        upperLimit = 6.100000;
        lowerLimit = -5.500000;
        promptAndGetFloat(string1, divisor, upperLimit, lowerLimit);
    }
    getQuotient(*divisor, *dividend, quotient);
    printf("The quotient of %f and %f is %f\n", *dividend, *divisor, *quotient);
}

void getPromptString(char* output) //prompt function
{
    scanf("%s", output);
}

void promptAndGetFloat(char* prompt, float* output, float upperLimit, float lowerLimit) //using prompt to get dividend and divisor function
{
    float out = -9999999.999999; //definitely outside of bounds
    while(out < lowerLimit || out > upperLimit) //ensures output (dividend/divisor) is inclusively between bounds
    {
        printf("%s (range %f to %f):: ", prompt, lowerLimit, upperLimit);
        scanf("%f", &out);
        if(out < lowerLimit || out > upperLimit) //conditional to print error message, a bit redundant but oh well
        {
            printf("***Error: you must enter a value between %f and %f ***\n\n", lowerLimit, upperLimit);
        }
    }
    *output = out;
}

void getQuotient(float divisor, float dividend, float* quotient) //get quotient
{
    float answer = dividend / divisor;
    *quotient = answer;
}
