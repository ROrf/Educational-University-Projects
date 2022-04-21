//Ryan Orf
//rconzc
#include<stdio.h> //going to lay back on the comments
#include<math.h> //implemented for pow function
#define LIMIT 8 //symbolic constant used in all functions for array size
void arrayCubed(int array[]); //function prototypes
void arrayDoubled(int array[]);
void printArray(int array[]);
void sumArrays(int array1[], int array2[], int arrayOut[]);
void multArrays(int array1[], int array2[], int arrayOut[]);

int main(void) //main
{
    int array1[LIMIT] = {0}, array2[LIMIT] = {0}, arraySum[LIMIT] = {0}, arrayProd[LIMIT] = {0}; //int arrays declared and initialized wiht size LIMIT and with all elements = 0
    arrayCubed(array1); //calls functions with appropriate array
    arrayDoubled(array2);
    printf("\nArray 1\n"); //printed for formatting sakes
    printArray(array1);
    printf("\nArray 2\n");
    printArray(array2);
    sumArrays(array1, array2, arraySum);
    multArrays(array1, array2, arrayProd);
    printf("\nSum of array1 and array2\n");
    printArray(arraySum);
    printf("\nProduct of array1 and array2\n");
    printArray(arrayProd);
}

void arrayCubed(int array[]) //cube function
{
    for(int i = 0; i < LIMIT; i++) //for loop loops through array
    {
        array[i] = pow(i,3); //cubes element's subscript
    }
}

void arrayDoubled(int array[]) //double function
{
    for(int i = 0; i < LIMIT; i++)
    {
        array[i] = i * 2; //doubles element's subscript
    }
}

void printArray(int array[]) //print function
{
    for(int i = 0; i < LIMIT; i++)
    {
        printf("%d\n", array[i]); //prints subscript
    }
}

void sumArrays(int array1[], int array2[], int arrayOut[]) //sum function
{
    for(int i = 0; i < LIMIT; i++)
    {
        arrayOut[i] = array1[i] + array2[i]; //adds elements of two arrays and passes the value of  the sum to the element of the third array
    }
}

void multArrays(int array1[], int array2[], int arrayOut[]) //multiplication function
{
    for(int i = 0; i < LIMIT; i++)
    {
        arrayOut[i] = array1[i] * array2[i]; //multiplies elements of two arrays and passes the value of the product to the element of the third array
    }
}
