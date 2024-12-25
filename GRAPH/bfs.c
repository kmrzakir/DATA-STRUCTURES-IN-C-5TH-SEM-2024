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
    front++;
    return temp;
}

void enQueu(int data)
{
    if(rare == MAX-1)
    {
        printf("QUEUE IS FULL CNA NOT INSERT : \n");
        return;
    }
    if(rare == -1)
    {
        rare++;
        front++;
        queue[rare] = data;
    }else
    {
        rare++;
        queue[rare] = data;
    }
    
}



// here we wil do BFT
void bft(struct Graph *graph,int startVertex)
{
    int ansArray[MAX],visitedArray[MAX] = {0},indx = 0;
    enQueu(startVertex);
    visitedArray[startVertex] = 1;
    while (front != -1)
    {
        int elm = dQueue();
        ansArray[indx] = elm;
        indx++;
        struct vertext *temp = graph->array[elm].head;
        while (temp != NULL)
        {
            int data = temp->data;
            if(visitedArray[data] == 0)
            {
                enQueu(data);
                visitedArray[data] = 1;
            }
            temp = temp->next;
        }
        
    }

    // printing BFS array

    printf("THE BFS OF THE GRAPH IS THIS : ");
    for(int i = 0;i < indx;i++)
    {
        printf("%d  :  ",ansArray[i]);
    }
    
}

int main()
{
    struct Graph *graph = createGraph(5);

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,2,4);
    addEdge(graph,2,1);
    addEdge(graph,3,2);

    // displyGraph(graph);

    bft(graph,0);

    return 0;
}