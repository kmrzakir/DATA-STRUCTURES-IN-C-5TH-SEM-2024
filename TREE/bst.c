#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int data);
struct Node* insertNode(struct Node* root,int data);
void display(struct Node *root);
struct Node* createNode(int data);
int searchData(struct Node *root,int data);

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

    int bool = searchData(root,700);
    if(bool == 0)
    {
        printf("ELEMENT NOT SOUND : \n");
    }else
    {
        printf("ELEMNET IS FOUND : \n");
    }


    return 0;
}

// display BST
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

// insert node in BST
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

// serach a particular data in a BST
int searchData(struct Node *root,int data)
{
    if(root == NULL)
    {
        printf("%d ELEMENT IS NOT PRESENT IN BST",data);
        return 0;
    }
    if(root->data == data)
    {
        return 1;
    }
    if(data < root->data)
    {
       return searchData(root->left,data);
    }else
    {
       return searchData(root->right,data);
    }
}

// create a node
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