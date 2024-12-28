#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *rare = NULL,*front = NULL;

struct Node* createNode(int data)
{
    struct Node  *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(int data)
{
    struct Node *temp = createNode(data);
    if(rare == NULL && front == NULL)
    {
        rare = temp;
        front = temp;
        return;
    }
    rare->next = temp;
    rare = temp;
}

void dqueue()
{
    if(rare == NULL)
    {
        printf("QUEUE IS EMPTY CNA NOT DELEAT : \n");
        return;
    }
    if(rare == front)
    {
        free(rare);
        rare = NULL;
        front = NULL;
        return;
    }
    struct Node *temp = front;
    front = front->next;
    free(temp);
}
void display()
{
    if(front == NULL && rare == NULL)
    {
        printf("CNA NOT DISPLAY BECAUSE  QUEUE IS EMPTY : \n");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    // dqueue();

    // display();
}