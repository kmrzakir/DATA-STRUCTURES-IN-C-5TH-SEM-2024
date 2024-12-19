#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int data);
struct Node* insertNode(struct Node* root,int data);
void display(struct Node *root);
struct Node* createNode(int data);

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root;

int main()
{

    root = insertNode(root,50);
    root = insertNode(root,30);
    root = insertNode(root,35);
    root = insertNode(root,70);
    root = insertNode(root,20);
    root = insertNode(root,60);

    display(root);


    return 0;
}

void display(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}

struct Node* insertNode(struct Node* root,int data)
{
    if(root == NULL)
    {
        struct Node *temp = createNode(data);
        return temp;
    }
    if(data < root->data)
    {
        root->left = insertNode(root->left,data);
    }else
    {
        root->right = insertNode(root->right,data);
    }
    return root;
}

struct Node* createNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
    {
        printf("MEMORY ALLOCATION FAILED : \n");
        return NULL;
    }
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}