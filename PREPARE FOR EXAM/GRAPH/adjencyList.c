#include<stdio.h>
#include<stdlib.h>

// this will represent vertix
struct Node
{
    int v_data;
    struct Node *next;
};

// this will represent the adjencyList
struct AdjList
{
    struct Node *head;
};

// this will represent the graph
struct Graph
{
    int v; // No of vertices
    struct AdjList *array;
};

// this will cretae  a node or we can say a vertix
struct Node* creatVertexeNode(int v_data)
{
    struct Node *vertix = (struct Node*)malloc(sizeof(struct Node));
    vertix->v_data = v_data;
    vertix->next = NULL;
    return vertix;
}

// this will cretae a graph
struct Graph* createGraph(int v)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->array  = (struct AdjList*)malloc(v * sizeof(struct AdjList));
    for(int i = 0;i < v;i++)
    {
        graph->array->head = NULL;
    }
   return graph;
}

// this function wlll add an edge from src vertext to dest vertext and also
// from dest vertext to src vertex because here we are creating an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // edge from dest to src vertex
    struct Node *temp = creatVertexeNode(dest);
    temp->next = graph->array[src].head;
    graph->array[src].head = temp;

    // since the graph is undirected we will add an edge from dest to src vertext also
    temp = creatVertexeNode(src);
    temp->next = graph->array[dest].head;
    graph->array[dest].head = temp;
}

void displayGrap(struct Graph *grap)
{
    for(int i = 0;i < grap->v;i++)
    {
        struct Node *mainNode = grap->array[i].head;
        printf("THE ADJENC LIST VERTIX OF %d VERTEXT IS : ",i);
        while(mainNode != NULL)
        {
            printf("uu%d --- %d ",i,mainNode->v_data);
            mainNode = mainNode->next;
        }
        printf("\n");
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

    displayGrap(graph);

    return 0;
}
