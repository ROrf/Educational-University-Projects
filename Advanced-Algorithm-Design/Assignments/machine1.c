/* Name: Ryan Orf
   Name: Romelo Seals
   
   The efficiency of this algorithm is O(V+E). The first while loop in main has a complexity of
   O(E) as it reads one line at a time from the input file, and each line represents an edge. 
   Similarly, the second while loop in main will have a complexity of O(E). For the initialization
   of the Graph, memory allocation calls take a constant amount of time. Given that there is a for
   loop that traverses through the number of vertices, the initialization function has a complexity
   of O(V). The createNode function takes a constant amount of time. The addToList function uses two 
   while loops to insert the new vertex into its proper place numerically among the other neighboring
   vertices, while the insertion itself takes a constant amount of time. This means that each while 
   loop will only traverse the number of edges corresponding to that particular vertex, which is to say
   that the addToList function will at most have a complexity of O(E). The print function has a for loop
   conditioned on the number of vertices, and each while loop iteration traverses the number of edges,
   represented by the number of neighboring  vertices in each row. Therefore, the printList function has
   a complexity of O(V+E). Finally, freeAdjList also has a complexity of O(V+E). Therefore, the total
   complexity for this entire algorithm is O(V+E).
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
	int vertex;
	struct _node *next;
}Node;

typedef struct _graph {
	int numOfV;
	Node** adjLists;
}Graph;

Graph* initializeAdjList(int size);
Node* createNode(int v);
void addToList(Graph* adjList, int v1, int v2);
void printList(Graph* adjList);
void freeAdjList(Graph* adjList);

int main(int argc, char *argv[])
{
	FILE *fp;
	int numOfV = 0;
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
		while(!feof(fp))
		{
			int v1;
			int v2;
			fscanf(fp, "%d %d\n", &v1, &v2);
			if(v1 >= v2 && v1 > numOfV)
			{
				numOfV = v1;
			}
			else if (v2 >= v1 && v2 > numOfV)
			{
				numOfV = v2;
			}
		}
		Graph* adjList = initializeAdjList(numOfV);
		rewind(fp);
		while(!feof(fp))
		{
			int v1;
			int v2;
			fscanf(fp, "%d %d\n", &v1, &v2);
			addToList(adjList, v1, v2);
		}
		fclose(fp);
		printList(adjList);
		freeAdjList(adjList);
		printf("Malloc succeeded!\n");
	}
	return 0;
}

Graph* initializeAdjList(int size)
{
	Graph* adjList = (Graph*)malloc(sizeof(Graph));
	if(adjList==NULL)
	{
		printf("*** Error: Allocation of Graph failed! ***\n");
		return NULL;
	}
	adjList->numOfV = size;
	adjList->adjLists = malloc(size * sizeof(Node*));
	for(int i = 0; i < adjList->numOfV; i++)
	{
		adjList->adjLists[i] = NULL;
	}
	return adjList;
}	

Node* createNode(int v)
{
	Node* vert = (Node*)malloc(sizeof(Node));
	if(vert==NULL)
	{
		printf("*** Error: Allocation failed! %d***\n", v);
		return NULL;
	}
	vert->vertex = v;
	vert->next = NULL;
	return vert;
}

void addToList(Graph* adjList, int v1, int v2)
{
	Node* temp = createNode(v2);
	if(temp == NULL)
	{
		printf("*** Error: Allocation of a neighboring vertex failed! ***\n");
		return;
	}
	Node* tempNode = adjList->adjLists[v1-1];
	if(adjList->adjLists[v1-1] == NULL)
	{
		adjList->adjLists[v1-1] = temp;
	}
	else
	{
		while(tempNode->next != NULL)
		{
			if(temp->vertex < tempNode->vertex)
			{
				temp->next = tempNode;
				tempNode = temp;
				adjList->adjLists[v1-1] = temp;
			}
			tempNode = tempNode->next;
		}
		if(tempNode->next == NULL)
		{
			if(temp->vertex < tempNode->vertex)
			{
				temp->next = tempNode;
				tempNode = temp;
				adjList->adjLists[v1-1] = temp;
			}
			else
			{
				tempNode->next = temp;
			}
		}
	}
	temp = createNode(v1);
	if(temp == NULL)
	{
		printf("*** Error: Allocation of a neighboring vertex failed! ***\n");
		return;
	}
	tempNode = adjList->adjLists[v2-1];
	if(adjList->adjLists[v2-1] == NULL)
	{
		adjList->adjLists[v2-1] = temp;
	}
	else
	{
		while(tempNode->next != NULL)
		{
			if(temp->vertex < tempNode->vertex)
			{
				temp->next = tempNode;
				tempNode = temp;
				adjList->adjLists[v2-1] = temp;
			}
			tempNode = tempNode->next;
		}
		if(tempNode->next == NULL)
		{
			if(temp->vertex < tempNode->vertex)
			{
				temp->next = tempNode;
				tempNode = temp;
				adjList->adjLists[v2-1] = temp;
			}
			else
			{
				tempNode->next = temp;
			}
		}
	}
}

void printList(Graph* adjList)
{
	for(int i = 0; i < adjList->numOfV; i++)
	{
		Node* temp = adjList->adjLists[i];
		while(temp != NULL)
		{
			printf("%d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void freeAdjList(Graph* adjList)
{
	for(int i = 0; i < adjList->numOfV; i++)
	{
		Node* temp = adjList->adjLists[i];
		adjList->adjLists[i] = adjList->adjLists[i]->next;
		free(temp);
		temp = NULL;
	}
	free(adjList->adjLists);
	adjList->adjLists = NULL;
	free(adjList);
	adjList = NULL;
}