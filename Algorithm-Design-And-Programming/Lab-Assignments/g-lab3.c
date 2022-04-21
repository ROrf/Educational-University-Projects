//Ryan Orf
//rconzc
#include<stdio.h> //standard input/output pack imported for printf and scanf

int countX, countY, countXY, countNotXY; //public variables for bonus. These will count how many integers between 1 and 25 are divisible by only X, only Y, X and Y, or nether X  nor Y
int divisibleX(int intNumber, int x); //header for divisibleX method (or module) that tests whether that int is divisible by X
int divisibleY(int intNumber, int y); //header for divisibleY method (or module) that tests whether that int is divisible by Y;

int main(void) //main method, does not require parameters or a return
{
    int x, y; //variables X and Y, as requested (only lowercase)
    do{ //do while loop since while loops were not permitted. X and Y do not have to be instantiated (?) to any value as do while loops will go through the loop at least once (unless there is a break)
        printf("Enter an integer between 1 and 10:: \n");
        scanf("%d", &x);
        printf("Enter another integer beetween 1 and 10:: \n");
        scanf("%d", &y);
        (x < 1 || x > 10) ? printf("Error! X must be >=1 and X must be <= 10\n") : x; //ternary operator since if conditionals were prohibited. The first statement tests whether x is inclusively between 1 and 10, not taking any action if x is (the condition is false)
        (y < 1 || y > 10) ? printf("Error! Y must be >= 1 and Y must be <= 10\n") : y; //another ternary, substituting Y for X
    } while(x < 1 || x > 10 || y < 1 || y > 10); //do while loop will continue until the user enters values for X and Y between, and including, 1 to 10
    for(int i = 1; i < 26; i++) //for loop that runs 25 times, as once 26 is obtained the user will fall out of the loop
    {
        int isDivisibleX, isDivisibleY; //local variables that set the values of the returns to int variables because it made it easier for me in accord with the bonus (I encountered the problem of running the method 8 too many times)
        isDivisibleX = divisibleX(i, x); //tests if the number is divisible by x by calling divisibleX with i and x
        isDivisibleY = divisibleY(i, y); //tests if the number is divisible by y by calling divisibleY with i and y
        (isDivisibleX != 0 && isDivisibleY == 0) ? countX++ : countX; //increments countX if the number was only divisble by X
        (isDivisibleX == 0 && isDivisibleY != 0) ? countY++ : countY; //increments countY if the number was only divisible by Y
        (isDivisibleX != 0 && isDivisibleY != 0) ? countXY++ : countXY; //increments countXY if the number was divisible by X and Y
        (isDivisibleX == 0 && isDivisibleY == 0) ? countNotXY++ : countNotXY; //increments countNotXY if the number was not divisible by X or Y
    }
    printf("%d were divisible by only X\n", countX); //bonus, prints how many were only divisible by X
    printf("%d were divisible by only Y\n", countY); //bonus
    printf("%d were divisible by both X and Y\n", countXY); //bonus
    printf("%d were divisible by neither X nor Y\n", countNotXY); //bonus (I have stopped detailing every step as it is repetitive when I do the same thing four times merely changing the variables or whether it is divisible or not)
}

int divisibleX(int intNumber, int x) //method that tests whether the given number is divisible by X
{
    int yes = 1; //int variable yes, declared and instantiated for convenience. Yes is already set to 1 (nonzero therefore true)
    (intNumber%x) ? yes-- : yes++; //ternary that tests whether the number is divisible by X. If it is, the statement will actually be false, since 0 is false in C. Problems with errors had me increment yes, which ultimately does nothing since nonzero is true. However, if it is not divisible by X, yes is decremented to 0, which means false
    printf("%d ", intNumber); //prints number alone for formatting (will not produce any deadspace)
    (yes != 0) ? printf("is divisible by %d\n", x) : printf("is not divisible by %d\n", x); //ternary that prints whether it was divisible or not by testing whether yes == 0, or rather yes != 0. If yes is nonzero, that means the number was divisible by X, and will print likewise. If yes is zero, the MOD had a remainder and was not divisible by X, printing the result
    return yes; //returns an int, which is crucial for the bonus as this will determine whether it was divisible or not as shown and documented above
}

int divisibleY(int intNumber, int y) //method that tests whether the given number is divisible by Y
{ //method does the same thing as divisibleX, merely substituting Y for X. I chose not to comment all that out again to avoid redundancy
    int yes = 1; 
    (intNumber%y) ? yes-- : yes++;
    printf("%d ", intNumber);
    (yes != 0) ? printf("is divisible by %d\n", y) : printf("is not divisible by %d\n", y);
    return yes;
}
