/*
	Name: Ryan Orf
    Name: Romelo Seals
*/

#include<stdio.h> //headers included
#include<stdlib.h>

void maxHeapify(int* array, int* size, int i); //function prototypes
void buildMaxHeap(int* array, int* size);
void increaseKey(int* array, int* size, int i, int key);
int extractMax(int* array, int* size);
void insertKey(int* array, int* size, int key);
void changeKey(int* array, int* size, int i, int key);
void deleteKey(int* array, int* size, int i);
void printHeap(int* array, int* size);

/* main will open the provided file, either through the command line or when prompted, and if such a file exists, main will do the following: the first number, the size of the array, is read into the size
variable. For the number of elements, the next integer is scanned into the next element of the array. In this case, the array will act as our max heap. If the end of the file is reached, we break out of
the loop so as to avoid issues. buildMaxHeap is called to build our max heap. Then, since we know operation calls are all that is left, while we have not reached the end of the file, we scan in and compare
the next character. Depending on which character is scanned in, corresponding integers will be scanned in and certain functions will be called to perform such operations. There is also an error check for
if the desired operation is not one known to the program. Finally, printHeap is called to print our max heap, the array and size pointers are freed, and a message is printed to indicate success. The 
points of focus here are that the array is allocated 1000 integers, as this was a requirement later provided, and size is an allocated pointer, since the size of the array changes dynamically with certain
operations. We also "hid" the size in array element 0 and started the root element of the max heap at array element 1 so as to make the code make more logical sense*/
int main(int argc, char *argv[])
{
	FILE *fp;
	int* array = malloc(sizeof(int) * 1000);
	int* size = malloc(sizeof(int));
	*size = 0;
	if(argc == 2)
	{
		fp = fopen(argv[1], "r");
	}
	else
	{
		char filename[100];
		printf("Enter the file name: \n");
		scanf("%s", filename);
		fp = fopen(filename, "r");
	}
	if(fp == NULL)
	{
		printf("*** Error: File could not be located ***\n");
	}
	else
	{
		if(!feof(fp))
		{
			fscanf(fp, "%d ", size);
			array[0] = *size;
			for(int i = 1; i <= *size; i++)
			{
				if(feof(fp))
				{
					printf("*** Error: The end of file has been reached! ***\n");
					*size = i;
					break;
				}
				fscanf(fp, "%d ", &(array[i]));
			}
			buildMaxHeap(array, size);
		}
		while(!feof(fp))
		{
			char operation;
			fscanf(fp, "%c ", &operation);
			if(operation == 'E' || operation == 'e')
			{
				int max = extractMax(array, size);
				printf("Extracted max = %d\n", max);
			}
			else if(operation == 'I' || operation == 'i')
			{
				int key = 0;
				fscanf(fp, "%d ", &key);
				insertKey(array, size, key);
			}
			else if(operation == 'C' || operation == 'c')
			{
				int i = 0, key = 0;
				fscanf(fp, "%d %d ", &i, &key);
				changeKey(array, size, i, key);
			}
			else if(operation == 'D' || operation == 'd')
			{
				int i = 0;
				fscanf(fp, "%d ", &i);
				deleteKey(array, size, i);
			}
			else
			{
				printf("*** Error: Operation is unrecognized! ***\n");
			}
			
		}
		fclose(fp);
		printHeap(array, size);
		free(size);
		free(array);
		printf("Malloc succeeded!\n");
	}
	
}

/* maxHeapify first creates two variables, one for the left child and one for the right child. Next, a variable representing the largest key is initialized to the input i. If there is a left child and
the value at the left element is greater than the value at the given i element (which is currently the largest), largest is set equal to left. Similarly, if there is a right child and the value at the
right element is greater than the value at the largest element, largest is set equal to right. If largest is not i, then the values at elements i and largest are exchanged, and maxHeapify is recursively
called with the largest value in place of i. This will correctly order keys in a max heap*/
void maxHeapify(int* array, int* size, int i)
{
	int left = 2 * i;
	int right = left + 1;
	int largest = i;
	if(left <= *size && array[left] > array[i])
	{
		largest = left;
	}
	if(right <= *size && array[right] > array[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		maxHeapify(array, size, largest);
	}
}

/* buildMaxHeap goes through the values from half the size down to the root element 1 and calls maxHeapify. This will start on the element before the leaf nodes, and will call maxHeapify to build a max 
heap*/
void buildMaxHeap(int* array, int* size)
{
	for(int i = (*size / 2); i >= 1; i--)
	{
		maxHeapify(array, size, i);
	}
}

/* increaseKey first checks to see if the key is less than the current value at the given element. If it is, an error is printed, since the key value cannot be increased. Then, while the element is 
greater than the root element 1 and the array value at the element half of i is less than the given key, array element i is set equal to the array element at half of i, and i is set equal to half of i.
Finally, array element i is set equal to the key. This will ensure keys from the element you are changing up to the root are ordered properly in a max heap*/
void increaseKey(int* array, int* size, int i, int key)
{
	if(key < array[i])
	{
		printf("*** Error: New key is smaller than current key! ***\n");
	}
	while(i>1 && array[i/2] < key)
	{
		array[i] = array[i/2];
		i = i/2;
	}
	array[i] = key;
}

/* extractMax will set the max equal to the root element 1, the root element 1 equal to the last element (the array element size), the size will be decremented, and maxHeapify is called with the root 
element 1 in place of i. Then, the max is returned to the user. This will ensure that the max element is removed from the array by exchanging the max value with the last value and then decrementing the 
size, in essence removing that element from the array as it will no longer be obtainable. Although the sample output does not show any max values printed, we still returned and printed them since this
function is supposed to extract the max, not just merely remove it*/
int extractMax(int* array, int* size)
{	
	int max = array[1];
	array[1] = array[*size];
	*size = *size - 1;
	maxHeapify(array, size, 1);
	return max;
}

/* insertKey increments the size, sets i equal to the size, and loops through while i is greater than the root element 1 and while the array elemnent at half of i is less than the given key. In the while
loop, array element i is set equal to array element half of i, and i is set equal to half of i. Finally, array element i is set equal to the key value. This will move up the existing numbers, which will
be greater than the key, and insert the key in its rightful place in the max heap. increaseKey was not called, even though code is repeated, because we do not want to print an error in the case that
the key is less than the current array value at element i for this instance*/
void insertKey(int* array, int* size, int key)
{
	*size = *size + 1;
	int i = *size;
	while(i>1 && array[i/2] < key)
	{
		array[i] = array[i/2];
		i = i/2;
	}
	array[i] = key;
}

/* changeKey will change the element at array element i to the given key and call increaseKey to correctly order the max heap (to avoid repeating code)*/
void changeKey(int* array, int* size, int i, int key)
{
	array[i] = key;
	increaseKey(array, size, i, key);
}

/* deleteKey will set the key equal to the last element of the array (the size), decrement the size, and call changeKey. changeKey will end up changing the key value and calling increasKey to correctly
insert the key and reorder the max heap. Through decrementing the size, this will make that last value (which will be the deleted key) unobtainable, essentially deleting the key from the max heap*/
void deleteKey(int* array, int* size, int i)
{
	int key = array[*size];
	*size = *size - 1;
	changeKey(array, size, i, key);
}

/* printHeap loops through the elements of the array and prints all of the values of the max heap onto one line*/
void printHeap(int* array, int* size)
{
	for(int i = 1; i <= *size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

