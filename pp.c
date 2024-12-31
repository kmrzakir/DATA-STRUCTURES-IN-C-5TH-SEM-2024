#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* binaryTree()
{
    int x;
    scanf("%d",&x);
    if(x == -1)
    {
        return NULL;
    }
    struct Node *temp = createNode(x);
    printf("ENTER THE LEFT OF %d IF NOT ENTER -1 : \n",temp->data);
    temp->left = binaryTree();
    printf("ENTER THE RIGHT OF %d IF NOT ENTER -1 : \n",temp->data);
    temp->right = binaryTree();

    return temp;

}

struct Node* insertNode(struct Node *root,int data)
{
    if(root == NULL)
    {
        struct Node *temp = createNode(data);
        return temp;
    }
    if(data < root->data)
    {
      root->left = insertNode(root->left,data);
    }
    if(data > root->data)
    {
      root->right = insertNode(root->right,data);
    }
    return root;
}

void in_order(struct Node *root)
{
    if(root == NULL) return;
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

int main()
{
    struct Node *root = binaryTree();
    in_order(root);
}

// void selectionSort(int *arr,int size)
// {
//     for(int i = 0;i < size-1;i++)
//     {
//         int small = i;
//         for(int j = i+1;j < size;j++)
//         {
//             if(arr[small] > arr[j])
//             {
//                 small = j;
//             }
//         }
//         if(small != i)
//         {
//             int temp = arr[small];
//             arr[small] = arr[i];
//             arr[i] = temp;
//         }
//     }
// }

// void insertionSort(int *arr,int size)
// {
//     for(int i = 0;i < size-1;i++)
//     {
//         int j = i + 1;
//         while (j >= 0 && arr[j] < arr[j-1])
//         {
//             int temp = arr[j];
//             arr[j] = arr[j-1];
//             arr[j-1] = temp;
//             j--;
//         }
        
//     }
// }

// void bubbleSort(int *arr,int size)
// {
//     for(int i = 0; i < size;i++)
//     {
//         for(int j = 0; j < size-1-i;j++)
//         {
//             if(arr[j] > arr[j+1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// int partition(int *arr,int start,int end)
// {
//     int j = start;
//     for(int i = start;i <= end;i++)
//     {
//         if(arr[i] <= arr[end])
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             j++;
//         }
//     }
//     return j - 1;
// }

// void quickSort(int *arr,int start,int end)
// {
//     if(start >= end) return;
//     int pivot = partition(arr,start,end);
//     quickSort(arr,start,pivot-1);
//     quickSort(arr,pivot+1,end);
// }

// void displya(int *arr,int size)
// {
//     for(int i = 0;i < size;i++)
//     {
//         printf("%d ",arr[i]);
//     }
// }

// int main()
// {
//     int arr[] = {5,1,2,9,10,5,6};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     quickSort(arr,0,size-1);
//     displya(arr,size);
//     return 0;
// }

// // struct Node
// // {
// //     int data;
// //     struct Node *left;
// //     struct Node *right;
// // };
// // struct Node *roo = NULL;

// // struct Node* cretaeNode(int data)
// // {
// //     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
// //     temp->data = data;
// //     temp->left = NULL;
// //     temp->right = NULL;
// //     return temp;
// // }

// // struct Node* bst(struct Node *root,int data)
// // {
// //     if(root == NULL)
// //     {
// //         struct Node *temp = cretaeNode(data);
// //         return temp;
// //     }
// //     if(data <= root->data)
// //     {
// //         root->left = bst(root->left,data);
// //     }else if (data > root->data)
// //     {
// //         root->right = bst(root->right,data);
// //     }
// //     return root;
// // }

// // // struct Node* createBt()
// // // {
// // //     int x;
// // //     scanf("%d",&x);
// // //     if(x == -1)
// // //     {
// // //         return NULL;
// // //     }
// // //     struct Node *temp = cretaeNode(x);
// // //     printf("ENTER THE LEFT NODE OF %d : \n",temp->data);
// // //     temp->left = createBt();
// // //     printf("ENTER THE LEFT NODE OF %d : \n",temp->data);
// // //     temp->right = createBt();
// // //     return temp;
// // // }

// // void in_order(struct Node *root)
// // {
// //     if(root == NULL) return;
// //     in_order(root->left);
// //     printf("%d ",root->data);
// //     in_order(root->right);
// // }

// // void pre_order(struct Node *root)
// // {
// //     if(root == NULL) return;
// //     printf("%d ",root->data);
// //     pre_order(root->left);
// //     pre_order(root->right);
// // }

// // void post_order(struct Node *root)
// // {
// //     if(root == NULL) return;
// //     post_order(root->left);
// //     post_order(root->right);
// //     printf("%d ",root->data);
// // }

// // int main()
// // {
// //    roo = bst(roo,10);
// //    roo = bst(roo,20);
// //    roo = bst(roo,5);
// //    roo = bst(roo,2);
// //    roo = bst(roo,30);
// //    roo = bst(roo,4);

// //     in_order(roo);
// //     post_order(roo);
// //     pre_order(roo);

// //     return 0;
// // }


// // struct vertex
// // {
// //     int data;
// //     struct vertex *next;
// // };

// // struct adjencyList
// // {
// //     struct vertex *head;
// // };

// // struct Graph
// // {
// //     int vertices;
// //     struct adjencyList *array;
// // };

// // struct vertex* createVertex(int data)
// // {
// //     struct vertex *temp = (struct vertex*)malloc(sizeof(struct vertex));
// //     temp->data = data;
// //     temp->next = NULL;
// //     return temp;
// // }

// // struct Graph* createGraph(int vertices)
// // {
// //     struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
// //     graph->vertices = vertices;
// //     graph->array = (struct adjencyList*)malloc(vertices * sizeof(struct adjencyList));

// //     for (int i = 0; i < vertices; i++)
// //     {
// //         graph->array[i].head = NULL;
// //     }
// //     return graph;
// // }

// // void addEdge(struct Graph *graph, int src, int dest)
// // {
// //     struct vertex *vertex = createVertex(dest);
// //     vertex->next = graph->array[src].head;
// //     graph->array[src].head = vertex;

// //     vertex = createVertex(src);
// //     vertex->next = graph->array[dest].head;
// //     graph->array[dest].head = vertex;
    
// // }

// // void displayGraph(struct Graph *graph)
// // {
// //     for(int i = 0;i < graph->vertices;i++)
// //     {
// //         struct vertex *hedd = graph->array[i].head;
// //         while(hedd != NULL)
// //         {
// //             printf("%d -> %d \n",i,hedd->data);
// //             hedd = hedd->next;
// //         }
// //     }
// // }

// // struct Node
// // {
// //     int data;
// //     struct Node *left;
// //     struct Node *right;
// // };
// // struct Node *root;

// // struct Node * cretaeNode(int data)
// // {
// //     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
// //     temp->data = data;
// //     temp->right = NULL;
// //     temp->left = NULL;
// //     return temp;
// // }

// // void pre_order(struct Node *root)
// // {
// //     if(root == NULL) return;
// //     printf("%d",root->data);
// //     pre_order(root->left);
// //     pre_order(root->right);
// // }

// // struct Node* bst(struct Node *root,int data)
// // {
// //     if(root == NULL)
// //     {
// //         struct Node *temp = cretaeNode(data);
// //         return temp;
// //     }
// //     if(data < root->data)
// //     {
// //         root->left = bst(root->left,data);
// //     }else if (data > root->data)
// //     {
// //         root->right = bst(root->right,data);
// //     }
// //     return root;
// // }

// // void in_order(struct Node *root)
// // {
// //     if(root == NULL) return;
// //     in_order(root->right);
// //     printf("%d ",root->data);
// //     in_order(root->left);
// // }

// // struct Node*  bt()
// // {
// //     int x;
// //     scanf("%d",&x);
// //     if(x == -1)
// //     {
// //         return NULL;
// //     }
// //     struct Node *temp = cretaeNode(x);
// //     printf("ENTER THE LEFT NOFE OF %d IF NOT ENTER -1 : \n",temp->data);
// //     temp->left = bt();
// //     printf("ENTER THE RIGHT NOFE OF %d IF NOT ENTER -1 : \n",temp->data);
// //     temp->right = bt();

// //     return temp;
// // }

// // int main()
// // {
// //     // root = bt();
// //     // pre_order(root);

// //     // root = bst(root,50);
// //     // root = bst(root,30);
// //     // root = bst(root,35);
// //     // root = bst(root,70);
// //     // root = bst(root,20);
// //     // root = bst(root,60);

// //     // in_order(root);

// //     struct Graph *graph = createGraph(5);

// //     addEdge(graph,0,1);
// //     addEdge(graph,0,2);
// //     addEdge(graph,0,3);
// //     addEdge(graph,0,4);
// //     addEdge(graph,2,3);
// //     addEdge(graph,2,4);
// //     addEdge(graph,3,3);
// //     addEdge(graph,3,4);
// //     addEdge(graph,4,2);

// //     displayGraph(graph);

// // }