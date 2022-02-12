/* Name: Ryan Orf
   Name: Romelo Seals
   
   The efficiency of this algorithm is O(V+E). The program will go through the number of edges, which is the number of lines in the file, to find the number of vertices, which takes O(E) time. Next, the 
   program again traverses through the number of edges, and each time calls addToList which will take a constant amoutn of time, therefore the complexity of this loop is again O(E). A for loop loops through
   the number of vertices to initialize array values, which takes O(V) time. Another for loop will go through the number of vertices, and if the vertex has not been visited yet, Depth First Search (DFS) is
   called. DFS is a recursive function that will go through the edges leaving each vertex in the graph, so the complexity of DFS is O(E), the complexity of the for loop is O(V), and therefore the overall
   complexity of the nestled loop is O(V+E). The next for loop goes through the number of vertices in the graph, goes through all of the edges that the current vertex points to, and adds the correlating
   components to the graph of the Strongly Connected Components (gSCC). This entire embedded loop will again take O(V+E) time. The following for loop is another initialization for an array of out degrees,
   which will take O(V) time. Then, another for loop loops through the number of vertices of gSCC, equal to the number of components of the original graph, and calls a function to obtain the out degree.
   The getOutDegree function will go through the number of edges for that given vertex in gSCC, and will increment the corresponding element in the array outDegree if and only if the vertex points to
   another vertex, and that vertex has not been pointed to already from this exact vertex. Since the while loop takes O(E) time (for gSCC), and we are looping through the number of vertices in gSCC,
   this loop will have a complexity of O(V+E) in relation to gSCC (not the original graph, which is larger or at the very least the same size). A sorting algorithm, sortOutDegree, will sort the out degrees
   in the array using a sorting algorithm with O(V) complexity, as most of the values are already in sorted order so it follows the best case. Finally, all data is freed, and free functions are called that
   have a complexity of O(V). Therefore, the overall time complexity for the program will be O(V+E). (Many things that take constant time, such as allocating memory, conditional loops, and initializing were
   not recorded due to redundancy).
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
void DFS(Graph* adjList, int v, int visited[], int start[], int end[], int comp[], int *time, int *component, int *until);
void getOutDegree(Graph* gSCC, int v, int outDegree[], int size);
void sortOutDegree(int outDegree[], int size);
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
		int *visited = malloc(numOfV * sizeof(int));
		int *start = malloc(numOfV * sizeof(int));
		int *end = malloc(numOfV * sizeof(int));
		int *comp = malloc(numOfV * sizeof(int));
		int *time = malloc(sizeof(int));
		int *component = malloc(sizeof(int));
		int *until = malloc(sizeof(int));
		int timeVar = 1, compVar = 1;
		if(visited == NULL || start == NULL || end == NULL || comp == NULL || time == NULL || component == NULL || until == NULL)
		{
			printf("*** Error: Allocation failed!\n");
			free(until);
			free(component);
			free(time);
			free(comp);
			free(end);
			free(start);
			free(visited);
			freeAdjList(adjList);
			return -1;
		}
		time = &timeVar;
		component = &compVar;
		int i = 0;
		until = &i;
		for(i = 0; i < numOfV; i++)
		{
			visited[i] = 0;
			start[i] = 0;
			end[i] = 0;
			comp[i] = 0;
		}
		for(i = 0; i < numOfV; i++)
		{
			if(visited[i] == 0)
			{
				DFS(adjList, i, visited, start, end, comp, time, component, until);
			}
		}
		for(int i = 0; i < numOfV; i++)
		{
			printf("V: %d, S: %d, E: %d, C:%d\n", i+1, start[i], end[i], comp[i]);
		}
		Graph* gSCC = initializeAdjList(*comp);
		for(int i = 0; i < numOfV; i++)
		{
			Node* temp = adjList->adjLists[i];
			while(temp != NULL)
			{
				if(comp[i] != comp[temp->vertex-1])
				{
					addToList(gSCC, comp[i], comp[temp->vertex-1]);
				}
				temp = temp->next;
			}
		}
		int *outDegree = malloc((*comp) * sizeof(int));
		if(outDegree == NULL)
		{
			printf("*** Error: Allocation failed!\n");
			free(outDegree);
			freeAdjList(gSCC);
			free(until);
			free(component);
			free(time);
			free(comp);
			free(end);
			free(start);
			free(visited);
			freeAdjList(adjList);
			return -1;
		}
		for(int i = 0; i < *comp; i++)
		{
			outDegree[i] = 0;
		}
		for(int i = 0; i < *comp; i++)
		{
			getOutDegree(gSCC, i, outDegree, *comp);
		}
		sortOutDegree(outDegree, *comp);
		for(int i = 0; i < *comp; i++)
		{
			printf("%d ", outDegree[i]);
		}
		printf("\n");
		free(outDegree);
		freeAdjList(gSCC);
		free(until);
		free(component);
		free(time);
		free(comp);
		free(end);
		free(start);
		free(visited);
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
		temp->next = tempNode;
		tempNode = temp;
		adjList->adjLists[v1-1] = temp;
	}
}

void DFS(Graph* adjList, int v, int visited[], int start[], int end[], int comp[], int *time, int *component, int* until)
{
	visited[v] = 1;
	start[v] = *time;
	*time = *time + 1;
	Node* temp = adjList->adjLists[v];
	*until = -1;
	if(!temp)
	{
		comp[v] = *component;
		*component = *component + 1;
	}
	while(temp != NULL)
	{
		if(visited[temp->vertex-1] == 0)
		{
			DFS(adjList, temp->vertex-1, visited, start, end, comp, time, component, until);
		}
		if(visited[temp->vertex-1] == 1 && end[temp->vertex-1] == 0)
		{
			*until = temp->vertex-1;
		}
		if(temp->next == NULL && *until == -1)
		{
			*until = v;
		}
		temp = temp->next;
	}
	end[v] = *time;
	*time = *time + 1;
	if(comp[v] == 0)
	{
		comp[v] = *component;
	}
	if(v == *until)
	{
		*component = *component + 1;
		*until = -1;
	}
}

void getOutDegree(Graph* gSCC, int v, int outDegree[], int size)
{
	int *visited = malloc(size * sizeof(int));
	if(visited == NULL)
	{
		printf("*** Error: Allocation failed!\n");
		free(visited);
		return;
	}
	for(int i = 0; i < size; i++)
	{
		visited[i] = 0;
	}
	Node* temp = gSCC->adjLists[v];
	while(temp != NULL)
	{
		if(visited[temp->vertex-1] == 0)
		{
			visited[temp->vertex-1] = 1;
			outDegree[v]++;
		}
		temp = temp->next;
	}
	free(visited);
}

void sortOutDegree(int outDegree[], int size)
{
	for(int i = 1; i < size; i++)
	{
		int temp = outDegree[i];
		int j = i - 1;
		while(temp<outDegree[j] && j>= 0)
		{
			outDegree[j+1] = outDegree[j];
			j--;
		}
		outDegree[j+1] = temp;
	}
}

void freeAdjList(Graph* adjList)
{
	for(int i = 0; i < adjList->numOfV; i++)
	{
		Node* temp = adjList->adjLists[i];
		if(temp == NULL)
		{
			break;
		}
		adjList->adjLists[i] = adjList->adjLists[i]->next;
		free(temp);
		temp = NULL;
	}
	free(adjList->adjLists);
	adjList->adjLists = NULL;
	free(adjList);
	adjList = NULL;
}