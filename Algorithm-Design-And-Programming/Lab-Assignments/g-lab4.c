//Ryan Orf
//rconzc
#include<stdio.h> //imports standard input/output header for printf 
#include<math.h> //imports math header for pow function

double myPower(double base, int exp); //function prototypes
void checkTestIsEqual(double expected, double result);
void doTest(double base, int exp);

int main(void) //main
{
    doTest(4.5, 3); //calls doTest function with test cases. I did not include scanf/input because the instructions said to copy the main
    doTest(4.5, -3);
    doTest(-1, 11);
    doTest(1, -11);
    doTest(-20, 11);
    doTest(2.0d, 3);
    doTest(2.0d, -1);
    doTest(5.0d, -2);
    doTest(1.0d, 0);
    doTest(4, 0);
    doTest(-1, 3);
    doTest(-2, -2);
    doTest(-20, -1);
    doTest(-20, -11);
}

void doTest(double base, int exp) //void function so no return, accepts the base and exponents as parameters
{
    printf("\nTesting %lf to the %d power\n", base, exp); //prints testing message as instructed
    checkTestIsEqual(pow(base, exp), myPower(base, exp)); //calls checkTestIsEqual, another void function, with double parameters expected and result, with the expected value being the return of calling the pow function imported using math.h, and the result being the return of calling my function, myPower. Both are doubles
}

double myPower(double base, int exp) //myPower function, double return type which is the answer, accepts the base and exponent as parameters
{
    if(exp > 10 || exp < -10) //checks condition that the exponent must be greater than or equal to -10 and less than or equal to 10
    {
        return 0; //returns 0 as instructed, subsequently ignoring the rest of the function as well
    }
    double result = 1; //instantiates result to 1, because raising a number to a power is the same as multiplying by the base that many times, so result as 1 makes sense (also any number to the zero power is 1). Also a double because the user is seeking a double return
    if(exp>0) //checks to see if the exponent is positive
    {
        for(int i = 0; i < exp; i++) //loops through the exponent so that we multiply by the number of times equal to the exponent
        {
            result = result * base; //multiplies the result by the base since the exponent is positive
        }
    }
    if(exp<0) //checks to see if the exponent is negative
    {
        for(int i = 0; i > exp; i--) //loops through the exponent so that we divide by the number of times equal to the exponent
        {
            result = result / base; //divides the result by the base since the exponent is negative
        }
    }
    if(exp==0) //checks if case is 0
    {
        result = 1; //anything to the zero is 1. This was a bit redundant, not necessary since result was already 1, however I included it to show I know what I am talking about
    }
    return result; //returns the result, aka the answer, which is type double
}

void checkTestIsEqual(double expected, double result) //void function, takes in the results of pow and myPower as double parameters
{
    if(expected==result) //conditional to check if the expected and result values are equal
    {
        printf("\tSuccess: %lf==%lf!\n", expected, result); //prints desired success message as instructed
    }
    else //if the if is false, then expected must not equal result, which is why I can use an if else, since it is either one or the other
    {
        printf("\tError: expected %lf, result was %lf!\n", expected, result); //prints desired error message as instructed
    }
}
