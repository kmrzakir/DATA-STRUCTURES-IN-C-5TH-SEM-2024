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
}
// struct Node* bst_tree(struct Node *root,int data)
// {
//     if(root == NULL)
//     {
//         struct Node *temp = createNode(data);
//         return temp;
//     }if(data < root->data)
//     {
//         root->left = bst_tree(root->left,data);
//     }else
// }