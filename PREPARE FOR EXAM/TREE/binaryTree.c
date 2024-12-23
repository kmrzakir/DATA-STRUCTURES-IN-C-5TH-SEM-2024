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
    printf("ENTER THE LEFT OF %d AND IF YOU  DO NOT WANT TO ENTER THEN ENTER -1 : ",x);
    temp->left = binaryTree();
    printf("ENTER THE RIGHT OF %d AND IF YOU  DO NOT WANT TO ENTER THEN ENTER -1 : ",x);
    temp->right = binaryTree();
    return temp;
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

void in_order(struct Node *root)
{
    if(root == NULL) return;
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

int main()
{

    printf("ENTER THE ROOT NODE OF A BINARY TREE : ");

    struct Node *root = binaryTree();
    
    pre_order(root);

    return 0;
}