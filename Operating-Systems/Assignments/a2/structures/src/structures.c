#include "../include/structures.h"
#include <stdio.h>

int compare_structs(sample_t* a, sample_t* b) /* Function returns 1 if the structs are the same, or 0 otherwise */
{
    if(a && b) // NULL checks
    {
        if(a->a == b->a && a->b == b->b && a->c == b->c) // compares each corresponding member of both struct to see if they are the same
        { 
            return 1; // successful return
        }
    }
	return 0; // default return
}

void print_alignments() /* Function prints alignments of different bytes (this function was already written */
{
	printf("Alignment of int is %zu bytes\n",__alignof__(int));
	printf("Alignment of double is %zu bytes\n",__alignof__(double));
	printf("Alignment of float is %zu bytes\n",__alignof__(float));
	printf("Alignment of char is %zu bytes\n",__alignof__(char));
	printf("Alignment of long long is %zu bytes\n",__alignof__(long long));
	printf("Alignment of short is %zu bytes\n",__alignof__(short));
	printf("Alignment of structs are %zu bytes\n",__alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a,int* apples,int* oranges, const size_t size) /* Function returns the total size if fruits are successfully sorted, or -1 otherwise */
{
    if(a && apples && oranges && size > 0) // NULL checks and size check
    {
        for(size_t i = 0; i < size; i++) 
        {
            if((a+i)->type == ORANGE) // check to see if the "current" fruit is an orange (using the symbolic constant ORANGE. There is a symbolic constant IS_ORANGE(a), however that cannot be used because a can't be moved since the parameter is const)
            {
                *oranges += 1; // increment the number of oranges
            }
            else if((a+i)->type == APPLE) // check to see if the "current" fruit is an apple (using the symbolic constant APPLE. There is a symbolic constant IS_APPLE(a), however that cannot be used because a can't be moved since the parameter is const)
            {
                *apples += 1; // increment the number of apples
            }
        }
        return size; // successful return
    }
	return -1; // default return
}

int initialize_array(fruit_t* a, int apples, int oranges) /* Function returns 0 if an array of fruit is successfully initialized, or 0 otherwise */
{
    int fruit_size = apples + oranges; // need to obtain the total number of fruits in the fruit array a
    if(a && fruit_size > 0) // NULL check and size check
    {
        fruit_t *fruitArray; // declare a new fruit_t array and set it equal to the memory location of the parameter a
        fruitArray = a;
        int initialized = 0; // variable to check the return of our initialization calls
        int numApples = 0; // variable to monitor the number of apples, as I use pointer arithmetic instead of moving the pointer
        int numOranges = 0; // variable to monitor the number of oranges, as I use pointer arithmetic instead of moving the pointer
        while(numApples < apples) // initializes the apples first to practice polymorphism
        {
            initialized = initialize_apple(((apple_t *)fruitArray)+numApples); // call function to initialize an apple (using pointer arithmetic and casting in the parameter)
            if(initialized == -1) // check if initialization failed
            {
                free(a); // need to free the array if any initialization failed as the test function does not
                return -1; // failed return
            }
            numApples++;
        }
        while(numOranges < oranges)
        {
            initialized = initialize_orange((orange_t *)(((apple_t *)fruitArray)+numApples)+numOranges); // call function to initialize an orange (using pointer arithemtic and casting in the parameter)
            if(initialized == -1) // check if initialization failed
            {
                free(a); // need to free the array if any initialization failed as the test function does not
                return -1; // failed return
            }
            numOranges++;
        }
        return 0; // successful return
    }
	return -1; // default return
}

int initialize_orange(orange_t* a) /* Function returns 0 if an orange_t struct a is correctly initialized, or -1 otherwise */
{ 
    if(a) // NULL check
    {
        a->type = ORANGE; // use symbolic constant to set the type to an orange
        a->weight = 0; // initialized weight and peeled to 0 as that is the normal initialization and nothing was provided to indicate otherwise
        a->peeled = 0;
        return 0; // successful return
    }
	return -1; // default return
}

int initialize_apple(apple_t* a) /* Function returns 0 if an apple_t struct a is correctly initialized, or -1 otherwise */
{
    if(a) // NULL check
    {
        a->type = APPLE; // use symbolic constant to set the type to an apple
        a->weight = 0; // initialized weight and worms to 0 as that is the normal initialization and nothing was provided to indicate otherwise
        a->worms = 0;
        return 0; // successful return 
    }
	return -1; // default return
}
