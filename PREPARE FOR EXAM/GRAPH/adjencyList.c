#include<stdio.h>
#include<stdlib.h>

// this will represent vertix
struct vertext
{
    int data;
    struct vertext *next;
};

// this will represent adjencyList
struct adjencyList
{
    struct vertext *head;
};

// this will represent a graph
struct Graph
{
    int vertices; // this will represent number of vertices
    struct adjencyList *array; // this will represent list of connected vertices
};

// this will cretae a vertext
struct vertext* createVertext(int data)
{
    struct vertext *temp = (struct vertext*)malloc(sizeof(struct vertext));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// this will cretae a graph
struct Graph* createGraph(int vertices)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->array = (struct adjencyList*)malloc(vertices * sizeof(struct adjencyList));
    for(int i = 0;i < vertices;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

// this will add an edge from scr to dest and dest to src because graph is undirected
void addEdge(struct Graph *graph,int src,int dest)
{
    // edge from dest to src
    struct vertext *temp = createVertext(dest);
    temp->next = graph->array[src].head;
    graph->array[src].head = temp;

    // edge from src to dest
    temp = createVertext(src);
    temp->next = graph->array[dest].head;
    graph->array[dest].head = temp;
}

// display graph
void displayGraph(struct Graph *graph)
{
    for(int i = 0;i < graph->vertices;i++)
    {
        struct vertext *temp = graph->array[i].head;
        while (temp)
        {
            printf("%d -> %d ",i,temp->data);
            temp = temp->next;
        }
        
    }
}

void main()
{

    struct Graph *graph = createGraph(6);

    addEdge(graph,0,1);
    addEdge(graph,2,1);
    addEdge(graph,3,1);
    addEdge(graph,4,1);
    addEdge(graph,5,1);
    addEdge(graph,3,3);

    displayGraph(graph);

    return;
}