#include<stdio.h>
#include<stdlib.h>

// this will represent the vertext of a graph
struct vertex
{
    int data;
    struct vertex *next;
};

// this will represent the vertext list
struct adjencyList
{
    struct vertex *head;
};

// this will represent the grapg
struct Graph
{
    int vertices; // the number of vertices
    struct adjencyList *array; //  this will represent the vertex list
};

// create a vertex
struct vertex* createVertex(int data)
{
    struct vertex *temp = (struct vertex*)malloc(sizeof(struct vertex));
    temp->data = data;
    temp->next = NULL;
    return temp;   
}
struct Graph* createGraph(int vertices)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct adjencyList*)malloc(vertices * sizeof(struct adjencyList));

    //  initializing five vertex with null
    for(int i = 0;i<vertices;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

// add an edge from sorce vertex to destination vertx
void addEdge(struct Graph *graph,int src,int des)
{
    // adding edge from des to scr
    struct vertex *vrtx = createVertex(des);
    vrtx->next = graph->array[src].head;
    graph->array[src].head = vrtx;

    // since we are creating here an undirected graph so we will add edge fron src ro des also
    vrtx = createVertex(src);
    vrtx->next = graph->array[des].head;
    graph->array[des].head = vrtx;

}

// displaying graph here
void displyGraph(struct Graph *grap)
{
    for (int i = 0; i < grap->vertices; i++)
    {
        struct vertex *list = grap->array[i].head;
        while (list)
        {
            printf("%d -> %d |",i,list->data);
            list = list->next;
        }
        
    }
    
}


int main()
{

    
    struct Graph *graph = createGraph(5);

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,0,4);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    addEdge(graph,4,3);
    addEdge(graph,3,1);
    addEdge(graph,3,2);

    displyGraph(graph);
    return 0;
}