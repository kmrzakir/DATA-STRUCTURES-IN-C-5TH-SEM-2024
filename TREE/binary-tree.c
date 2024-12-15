#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int data);
struct Node* binary_tree();
void preorder_traverse(struct Node *root);

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;

int main()
{
    root = binary_tree();
    preorder_traverse(root);
    return 0;
}

void preorder_traverse(struct Node *root)
{
    printf("%d ",root->data);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

struct Node* binary_tree()
{
    int x;
    struct Node *temp;
    if(root == NULL)
    {
        printf("Enter the root node : ");
        scanf("%d",&x);
        temp = createNode(x);
        root = temp;

    }else{
        scanf("%d",x);
        temp = createNode(x);
    }
    if(x == -1)
    {
        return NULL;
    }
    printf("ENTER THE LEFT NODE : ");
    temp->left = binary_tree();
    printf("ENTER THE RIGHT NODE : ");
    temp->right = binary_tree();
    return temp;
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

