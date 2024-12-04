#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;

void main()
{



}

void insertNodeAtEnd(int data)
{
    
}

void insertNodeAtFront(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void display()
{
    if(head == NULL)
    {
        printf("LL IS EMPTY CNA NOT DISPLAY : \n");
        return;
    }
    struct Node *temp = head;
    printf("LL DATA IS : ");
    while (temp != NULL)
    {
        temp = temp->next;
    }
}

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("MEMEORY NOT ALLOCATED : \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}