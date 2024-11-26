#include<stdio.h>
#include<stdlib.h>
struct Node* createNode(int data);
void insertNodeAtEnd(int data);
void insertNodeAt(int data,int position);
void insertNodeAtStart(int data);
void deleatNodeAt(int position);
void deleatFrontNode();
void deleatEndNode();
int getLength();
void display();

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

int main(){

    insertNodeAtStart(20);
    insertNodeAtStart(40);
    insertNodeAtStart(60);
    insertNodeAtStart(80);
    insertNodeAtStart(100);

    deleatNodeAt(3);

    display();

    return 0;
}

void deleatNodeAt(int position)
{
    if(head == NULL)
    {
        printf("CAN NOT DELEAT %d NODE BECAUSE LINKED LIST IS EMPTY : \n",position);
        return;
    }
    int length = getLength();
    if(position <= 0 || position > length)
    {
        printf("POSITION %d IS NOT VALID SO CAN NOT DELEAT : \n",position);
        return;
    }else if(position == 1)
    {
        deleatFrontNode();
    }else if(position == length)
    {
        deleatEndNode();
    }else
    {
        struct Node *temp = head;
        for(int i = 1;i<position-1;i++)
        {
            temp = temp->next;
        }
        struct Node *deleatNode = temp->next;
        temp->next = deleatNode->next;
        free(deleatNode);
    }
}

void deleatEndNode()
{
    if(head == NULL)
    {
        printf("CAN NOT DELEAT END NOT BECAUSE LINKED-LIST IS EMPTY : \n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleatFrontNode()
{
    if(head == NULL)
    {
        printf("CAN NOT DELEAT FRONT NOT BECAUSE LINKED LIST IS EMPTY : \n");
        return;
    }
    struct Node *deleateNode = head;
    head = deleateNode->next;
    free(deleateNode);
}

void insertNodeAt(int data,int position)
{
    struct Node *newNode = createNode(data);
    int length = getLength();
    if(position <= 0 || position > length)
    {
        printf("NOT VALID POSITION : \n");
        return;
    }
    if(position == 1)
    {
        insertNodeAtStart(data);
    }else if(position == length)
    {
        insertNodeAtEnd(data);
    }else
    {
        struct Node *temp  = head;
        for(int i = 1; i < position-1;i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertNodeAtStart(int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertNodeAtEnd(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp = newNode;
}

void display()
{
    if(head == NULL)
    {
        printf("LINKED LIST IS EMPTY CAN NOT DISPLAY : \n");
        return;
    }
    struct Node *temp = head;
    printf("LINKED LIST DATA IS :  ");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

int getLength()
{
    if(head == NULL)
    {
        printf("SIZE IS 0 BECAUSE LINKED LIST IS EMPTY : \n");
        return 0;
    }
    struct Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("DATA ALLOCATION FAILED : \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}