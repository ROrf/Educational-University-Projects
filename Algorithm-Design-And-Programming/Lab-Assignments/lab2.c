//Ryan Orf
//rconzc
#include<stdio.h> /*standard input/output pack imported so we can use statements such as printf and scanf*/

int main(void) /*main method, which does not accept parameters (void)*/
{
    int A, B, C; /*declares integers A, B, and C to be implemented*/
    printf("Enter 2 integers separated by spaces: ");
    scanf("%d", &A); /*scanner that takes in an integer assigned to the int variable A*/
    scanf("%d", &B); /*similar scanner to line 9, with the only difference being that now the integer parameter passed in is assigned to int B*/
    printf("Enter another integer that is not zero: ");
    scanf("%d", &C); /*...and again with int C*/
    while(C == 0) /*while loop that will only be initiated if the user inputs the value of 0 for int variable C, which would create an error since we divide by C. The loop will only initiate if C = 0, and will continue to loop through until the user inputs a nonzero integer*/
    {
        printf("Error! Enter another integer that is not zero: ");
        scanf("%d", &C); /*reassigns int variable C to a new input (hopefully nonzero integer) number*/
    }
    printf("A = %d\n", A); /*displays the value of A. Starting on this line of code, 18, and included throughout the rest of this program, we add a new line after each print statement. This is so the output is formatted neatly and in the same fashion as the samples, and it was not implemented earlier as we were using a scanner for input, and in adding this command, that being \n, we would create a line of dead space that may confuse the user, as the user must input anything to continue however that input was void and did not contribute to the program by any means whatsoever other than to further progress. This is the one problem I encountered while fooling around with the prelab*/
    printf("B = %d\n", B);
    printf("C = %d\n", C);
    printf("A plus B plus C = %d\n", A+B+C); /*outputs the value of the arithmetic operation requested without changing values of the previously instantiated int variables, or creating new int variables. This will be prevalent throughout the next 6 lines of code*/
    printf("A minus B = %d\n", A-B);
    printf("A minus B plus C = %d\n", (A-B)+C); /*while not necessary, since the order of operations for adding and subtracting is the same (and on line 26 multiplication and division,) I encapsulated the first half of the operation so as to guarantee the answer the user is seeking efficiently*/
    printf("A times B times C = %d\n", A*B*C);
    printf("A divided by C = %d\n", A/C);
    printf("A times B divided by C = %d\n", (A*B)/C);
    printf("A divided by C remainder = %d\n", A%C); /*nothing new on this line other than the implementation of the MOD operator, denoted %*/
    int largest; /*new int variable which will be used to output the largest value of the absolute values of the pre-established int variables A,B, and C*/
    if(A<0)
    {
        largest = A * -1;
    }
    else 
    {
        largest = A; /*instantiates largest to the value of A regardless, as largest requires a value in order to be compared to the other ints*/
    }
    if(B<0) /*since I do not yet know of an absolute value function in C, and it is not the same as in Java, unfortunately I have to first check if int variables B and C are negative before multiplying them by -1 to find the absolute value. I am sure there is a much more efficient way in C*/
    {
        if((B*-1)>largest) /*nested if statements, so that I can test the absolute value of variable B (and later C) compared to the variable largest. I also probably could have compressed both statements into one if block if C is similar to Java in the sense that I can test multiple ifs simultaneously with the and operator, &&*/
        {
            largest = B * -1;
        }
    }
    else /*else statement to test B (and later C) even if the int variable is already positive, since the absolute value of a positive number is that positive number*/
    {
        if(B>largest)
        {
            largest = B;
        } 
    }
    if(C<0)
    {
        if((C*-1)>largest)
        {
            largest = C * -1;
        }
    }
    else
    {
        if(C>largest)
        {
            largest = C;
        }
    }
    printf("The greatest absolute value is %d.\n", largest); /*outputs the greatest absolute value, in this case variable largest, in stylistic fashion*/
}
