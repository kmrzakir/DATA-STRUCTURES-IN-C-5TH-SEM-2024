#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int rare = -1, front = -1;

// ============= BFS ===================
// Breadth First Search (BFS) is an algorithm used to traverse or search a graph or tree data structure. It explores all neighbors at the current depth before moving to nodes at the next depth level, making it a "wide exploration" strategy.

// How BFS Works:
// Start: Begin at a chosen node (source node).
// Visit: Visit the starting node and mark it as visited.
// Queue Neighbors: Add all unvisited neighbors of the current node to a queue.
// Process: Dequeue a node, visit it, and enqueue its unvisited neighbors.
// Repeat: Continue the process until the queue is empty.
// Key Characteristics:
// BFS uses a queue data structure to keep track of the nodes to visit next (First In, First Out).
// It explores nodes level by level.
// BFS guarantees finding the shortest path in an unweighted graph from the source node to all other nodes.

// ================= DFS ===================
// Depth First Search (DFS) is an algorithm used to traverse or search through a graph or tree data structure. It explores as far as possible along a branch before backtracking, making it a deep exploration strategy.
// How DFS Works:
// Start: Begin at a chosen node (source node).
// Explore: Visit the starting node and mark it as visited.
// Go Deeper: Move to an adjacent unvisited node and repeat the process.
// Backtrack: If there are no unvisited adjacent nodes, backtrack to the previous node and check for unvisited neighbors.
// Repeat: Continue the process until all nodes in the graph are visited.
// Key Characteristics:
// DFS uses a stack data structure to keep track of the nodes to visit. This can be implemented using recursion (implicitly uses the call stack) or explicitly with a manual stack.
// The order of traversal depends on the adjacency list/order of neighbors.
// DFS can be applied to both directed and undirected graphs.
// Applications of DFS:
// Path Finding: To find a path between two nodes.
// Detecting Cycles: In a graph.
// Topological Sorting: For directed acyclic graphs (DAGs).
// Connected Components: To determine if a graph is connected.
// Solving Puzzles: Such as mazes or Sudoku.


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
    for(int i = 0;i < vertices;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph,int src,int dest)
{
    struct vertext *node = createVertex(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    node = createVertex(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

void displyGraph(struct Graph *graph)
{
    for(int i = 0;i < graph->vertices;i++)
    {
        struct vertext *temp = graph->array[i].head;
        while (temp)
        {
            printf("%d -> %d  ",i,temp->data);
            temp = temp->next;
        }
        
    }
}

void enqueue(int data)
{
    if(rare == front && rare == -1)
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

int dequeue()
{
    if(rare == -1)
    {
        printf("QUEUE IS EMPTY CNA NOT DQUEUE : \n");
        return -1;
    }
    int temp = queue[front];
    front++;
    return temp;
}

void bfs(struct Graph *graph, int startVertex)
{
    int answerArray[MAX],visitedArray[MAX] = {0},index = 0;
    enqueue(startVertex);
    visitedArray[startVertex] = 1;
    while(front <= rare)
    {
        int temp = dequeue();
        answerArray[index] = temp;
        index++;
        struct vertext *vrtx = graph->array[temp].head;
        while (vrtx)
        {
            int da = vrtx->data;
            if(visitedArray[da] == 0)
            {
                visitedArray[da] = 1;
                enqueue(da);
            }
            vrtx = vrtx->next;
        } 
    }

    printf("BFS OR THE GRAPH IS : \n");
    for(int i = 0; i < index;i++)
    {
        printf("%d ",answerArray[i]);
    }
}

void fun(struct Graph *graph,int *visitedVetex,int startVertx)
{
    visitedVetex[startVertx] = 1;
    printf("%d ",startVertx);
    struct vertext *node = graph->array[startVertx].head;
    while (node)
    {
        if(visitedVetex[node->data] == 0)
        {
            fun(graph,visitedVetex,node->data);
        }
        node = node->next;
    }
    
}

void dfs(struct Graph *graph,int startVertx)
{
    int visitedVetex[MAX] = {0},answerArray[MAX],index = 0;
    printf("DFS OF THE GRAPH IS : \n");
    fun(graph,visitedVetex,startVertx);

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

    bfs(graph,0);

    dfs(graph,0);

    return 0;
}


// struct vertext
// {
//     int data;
//     struct vertext *next;
// };

// struct adjencyList
// {
//     struct vertext *head;
// };

// struct Graph
// {
//     int vertices;
//     struct adjencyList *array;
// };

// struct vertext* createVertex(int data)
// {
//     struct vertext *temp = (struct vertext*)malloc(sizeof(struct vertext));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }

// struct Graph* createGraph(int vertices)
// {
//     struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->vertices = vertices;
//     graph->array = (struct adjencyList*)malloc(vertices * sizeof(struct adjencyList));
//     for(int i = 0;i < graph->vertices;i++)
//     {
//         graph->array[i].head = NULL;
//     }
//     return graph;
// }

// void addEdge(struct Graph *grap,int src,int dest)
// {
//     struct vertext *vertx = createVertex(dest);
//     vertx->next = grap->array[src].head;
//     grap->array[src].head = vertx;

//     vertx = createVertex(src);
//     vertx->next = grap->array[dest].head;
//     grap->array[dest].head = vertx;
// }

// void displyGraph(struct Graph *grap)
// {
//     for(int i = 0;i < grap->vertices;i++)
//     {
//         struct vertext *vertx = grap->array[i].head;
//         while (vertx)
//         {
//            printf("%d -> %d ",i,vertx->data);
//            vertx = vertx->next;
//         }
//     }
// }

// int dQueue()
// {
//     if(rare == -1)
//     {
//         printf("QUEUE IS EMPTY CNA NOT DELEAT : \n");
//         return -1;
//     }
//     if(rare == front)
//     {
//         int temp = queue[rare];
//         rare = -1;
//         front = -1;
//         return temp;
//     }
//     int temp = queue[front];
//     front++;
//     return temp;
// }

// void enQueu(int data)
// {
//     if(rare == MAX-1)
//     {
//         printf("QUEUE IS FULL CNA NOT INSERT : \n");
//         return;
//     }
//     if(rare == -1)
//     {
//         rare++;
//         front++;
//         queue[rare] = data;
//     }else
//     {
//         rare++;
//         queue[rare] = data;
//     }
    
// }



// // here we wil do BFT
// void bft(struct Graph *graph,int startVertex)
// {
//     int ansArray[MAX],visitedArray[MAX] = {0},indx = 0;
//     enQueu(startVertex);
//     visitedArray[startVertex] = 1;
//     while (front != -1)
//     {
//         int elm = dQueue();
//         ansArray[indx] = elm;
//         indx++;
//         struct vertext *temp = graph->array[elm].head;
//         while (temp != NULL)
//         {
//             int data = temp->data;
//             if(visitedArray[data] == 0)
//             {
//                 enQueu(data);
//                 visitedArray[data] = 1;
//             }
//             temp = temp->next;
//         }
        
//     }

//     // printing BFS array

//     printf("THE BFS OF THE GRAPH IS THIS : ");
//     for(int i = 0;i < indx;i++)
//     {
//         printf("%d  :  ",ansArray[i]);
//     }
    
// }

// // void dfs(struct Graph *graph, int node,int *answer,int *visited)
// // {
// //     visited[node] = 1;
// //     enQueu(node);

// // }


// void bfs2(struct Graph *graph, int startVertex)
// {
//     int ansArray[MAX],visitedArray[MAX] = {0},index = 0;
//     enQueu(startVertex);
//     visitedArray[startVertex] = 1;
//     while (front != -1)
//     {
//         int data = dQueue();
//         ansArray[index] = data;
//         index++;
//         struct vertext *node = graph->array[data].head;
//         while (node != NULL)
//         {
//             int temp = node->data;
//             if(visitedArray[temp] == 0)
//             {
//                 enQueu(temp);
//                 visitedArray[temp] = 1;
//             }
//             node = node->next;
//         }
//     }

//     printf("THE BFS OG THE GRAPH IS : ");
//     for(int i = 0;i < index;i++)
//     {
//         printf("%d ",ansArray[i]);
//     }

// }

// void fun(struct Graph *graph,int startIndex,int *visistedArray)
// {
//     visistedArray[startIndex] = 1;
//     printf("%d ",startIndex);
//     struct vertext *node = graph->array[startIndex].head;
//     while (node != NULL)
//     {
//         if(visistedArray[node->data] == 0)
//         {
//             fun(graph,node->data,visistedArray);
//         }
//         node = node->next;
//     }
    
// }
// void dfs(struct Graph *graph, int startVertex)
// {
//     int visitedArray[MAX] = {0};

//     printf("THE DFS OF THE GRAPH IS : ");
//     fun(graph,startVertex,visitedArray);

// }

// int main()
// {
//     struct Graph *graph = createGraph(5);

//     // addEdge(graph,0,1);
//     // addEdge(graph,0,2);
//     // addEdge(graph,0,3);
//     // addEdge(graph,2,4);
//     // addEdge(graph,2,1);
//     // addEdge(graph,3,2);

//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 0, 3);
//     addEdge(graph, 1, 4);
//     addEdge(graph, 2, 4);


//     // displyGraph(graph);

//     bft(graph,0);
//     bfs2(graph,0);
//     dfs(graph,0);

//     return 0;
// }