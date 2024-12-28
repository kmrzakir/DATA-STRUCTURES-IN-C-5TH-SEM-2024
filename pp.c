#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *roo = NULL;

struct Node* cretaeNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* bst(struct Node *root,int data)
{
    if(root == NULL)
    {
        struct Node *temp = cretaeNode(data);
        return temp;
    }
    if(data <= root->data)
    {
        root->left = bst(root->left,data);
    }else if (data > root->data)
    {
        root->right = bst(root->right,data);
    }
    return root;
}

// struct Node* createBt()
// {
//     int x;
//     scanf("%d",&x);
//     if(x == -1)
//     {
//         return NULL;
//     }
//     struct Node *temp = cretaeNode(x);
//     printf("ENTER THE LEFT NODE OF %d : \n",temp->data);
//     temp->left = createBt();
//     printf("ENTER THE LEFT NODE OF %d : \n",temp->data);
//     temp->right = createBt();
//     return temp;
// }

void in_order(struct Node *root)
{
    if(root == NULL) return;
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

void pre_order(struct Node *root)
{
    if(root == NULL) return;
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(struct Node *root)
{
    if(root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

int main()
{
   roo = bst(roo,10);
   roo = bst(roo,20);
   roo = bst(roo,5);
   roo = bst(roo,2);
   roo = bst(roo,30);
   roo = bst(roo,4);

    in_order(roo);
    post_order(roo);
    pre_order(roo);

    return 0;
}


// struct vertex
// {
//     int data;
//     struct vertex *next;
// };

// struct adjencyList
// {
//     struct vertex *head;
// };

// struct Graph
// {
//     int vertices;
//     struct adjencyList *array;
// };

// struct vertex* createVertex(int data)
// {
//     struct vertex *temp = (struct vertex*)malloc(sizeof(struct vertex));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }

// struct Graph* createGraph(int vertices)
// {
//     struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->vertices = vertices;
//     graph->array = (struct adjencyList*)malloc(vertices * sizeof(struct adjencyList));

//     for (int i = 0; i < vertices; i++)
//     {
//         graph->array[i].head = NULL;
//     }
//     return graph;
// }

// void addEdge(struct Graph *graph, int src, int dest)
// {
//     struct vertex *vertex = createVertex(dest);
//     vertex->next = graph->array[src].head;
//     graph->array[src].head = vertex;

//     vertex = createVertex(src);
//     vertex->next = graph->array[dest].head;
//     graph->array[dest].head = vertex;
    
// }

// void displayGraph(struct Graph *graph)
// {
//     for(int i = 0;i < graph->vertices;i++)
//     {
//         struct vertex *hedd = graph->array[i].head;
//         while(hedd != NULL)
//         {
//             printf("%d -> %d \n",i,hedd->data);
//             hedd = hedd->next;
//         }
//     }
// }

// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
// };
// struct Node *root;

// struct Node * cretaeNode(int data)
// {
//     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->right = NULL;
//     temp->left = NULL;
//     return temp;
// }

// void pre_order(struct Node *root)
// {
//     if(root == NULL) return;
//     printf("%d",root->data);
//     pre_order(root->left);
//     pre_order(root->right);
// }

// struct Node* bst(struct Node *root,int data)
// {
//     if(root == NULL)
//     {
//         struct Node *temp = cretaeNode(data);
//         return temp;
//     }
//     if(data < root->data)
//     {
//         root->left = bst(root->left,data);
//     }else if (data > root->data)
//     {
//         root->right = bst(root->right,data);
//     }
//     return root;
// }

// void in_order(struct Node *root)
// {
//     if(root == NULL) return;
//     in_order(root->right);
//     printf("%d ",root->data);
//     in_order(root->left);
// }

// struct Node*  bt()
// {
//     int x;
//     scanf("%d",&x);
//     if(x == -1)
//     {
//         return NULL;
//     }
//     struct Node *temp = cretaeNode(x);
//     printf("ENTER THE LEFT NOFE OF %d IF NOT ENTER -1 : \n",temp->data);
//     temp->left = bt();
//     printf("ENTER THE RIGHT NOFE OF %d IF NOT ENTER -1 : \n",temp->data);
//     temp->right = bt();

//     return temp;
// }

// int main()
// {
//     // root = bt();
//     // pre_order(root);

//     // root = bst(root,50);
//     // root = bst(root,30);
//     // root = bst(root,35);
//     // root = bst(root,70);
//     // root = bst(root,20);
//     // root = bst(root,60);

//     // in_order(root);

//     struct Graph *graph = createGraph(5);

//     addEdge(graph,0,1);
//     addEdge(graph,0,2);
//     addEdge(graph,0,3);
//     addEdge(graph,0,4);
//     addEdge(graph,2,3);
//     addEdge(graph,2,4);
//     addEdge(graph,3,3);
//     addEdge(graph,3,4);
//     addEdge(graph,4,2);

//     displayGraph(graph);

// }