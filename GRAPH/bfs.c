#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int rare = -1, front = -1;

struct vertext
{
    int data;
    struct vertext *next;
};

struct adjencyList
{
    struct vertext *head;
};

struct Graph
{
    int vertices;
    struct adjencyList *array;
};

struct vertext* createVertex(int data)
{
    struct vertext *temp = (struct vertext*)malloc(sizeof(struct vertext));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Graph* createGraph(int vertices)
{
    struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct adjencyList*)malloc(vertices * sizeof(struct adjencyList));
    for(int i = 0;i < graph->vertices;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph *grap,int src,int dest)
{
    struct vertext *vertx = createVertex(dest);
    vertx->next = grap->array[src].head;
    grap->array[src].head = vertx;

    vertx = createVertex(src);
    vertx->next = grap->array[dest].head;
    grap->array[dest].head = vertx;
}

void displyGraph(struct Graph *grap)
{
    for(int i = 0;i < grap->vertices;i++)
    {
        struct vertext *vertx = grap->array[i].head;
        while (vertx)
        {
           printf("%d -> %d ",i,vertx->data);
           vertx = vertx->next;
        }
    }
}

int dQueue()
{
    if(rare == -1)
    {
        printf("QUEUE IS EMPTY CNA NOT DELEAT : \n");
        return -1;
    }
    if(rare == front)
    {
        int temp = queue[rare];
        rare = -1;
        front = -1;
        return temp;
    }
    int temp = queue[front];
    front--;
    return temp;
}

void enQueu(int data)
{
    if(rare == MAX-1)
    {
        printf("QUEUE IS FULL CNA NOT INSERT : \n");
        return;
    }
    if(rare == front && rare == -1)
    {
        rare++;
        front++;
        queue[rare] = data;
    }else
    {
        rare++;
        queue[rare];
    }
    
}


// here we wil do BFT
void bft(struct Graph *graph,int startVertex)
{
    int arnwer[MAX],indx = 0;
    enQueu(startVertex);
    int visitedVertexes[MAX] = {0};
    visitedVertexes[startVertex] = 1;
    while (front != -1)
    {
        int currentVertex  = dQueue();
        arnwer[indx] = currentVertex;
        indx++;
        struct vertext *temp = graph->array[currentVertex ].head;
        while(temp != NULL)
        {
            int adjVertex = temp->data;
            if(visitedVertexes[adjVertex] == 0)
            {
                enQueu(adjVertex);
                visitedVertexes[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }

    // printf answer array which stores the BFS answer of the graph
    printf("THE BSF OF THE GRAPH IS : %d ",indx);
    for(int j = 0;j  < indx;j++)
    {
        printf("%d",arnwer[j]);
    }
}

int main()
{
    struct Graph *graph = createGraph(5);

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,2,4);
    addEdge(graph,2,2);
    addEdge(graph,3,2);

    displyGraph(graph);

    bft(graph,0);

    return 0;
}