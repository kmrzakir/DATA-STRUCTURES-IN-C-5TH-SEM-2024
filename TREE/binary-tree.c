#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int data);
struct Node* binary_tree();
void pre_order_traverse(struct Node *root);

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;

int main()
{
    printf("ENTER THE ROOT NODE : ");
    root = binary_tree();
    printf("BINARY TREE PRE ORDER TRAVERSER : ");
    pre_order_traverse(root);
    return 0;
}



void pre_order_traverse(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    pre_order_traverse(root->left);
    pre_order_traverse(root->right);
}

struct Node* binary_tree()
{
    int x;
    scanf("%d",&x);
    if(x == -1)
    {
        return NULL;
    }
    struct Node *temp = createNode(x);
    printf("ENTER THE RIGHT NODE OF %d : ",temp->data);
    temp->left = binary_tree();
    printf("ENTER THE LEFT NODE OF %d : ",temp->data);
    temp->right = binary_tree();

    return temp;

    // int x;
    // struct Node *temp;
    // if(root == NULL)
    // {
    //     printf("Enter the root node : ");
    //     scanf("%d",&x);
    //     temp = createNode(x);
    //     root = temp;

    // }else{
    //     scanf("%d",x);
    //     temp = createNode(x);
    // }
    // if(x == -1)
    // {
    //     return NULL;
    // }
    // printf("ENTER THE LEFT NODE : ");
    // temp->left = binary_tree();
    // printf("ENTER THE RIGHT NODE : ");
    // temp->right = binary_tree();
    // return temp;
}

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("MEMORY ALLOCATION FAILED : \n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

