#include<stdio.h>
#include<stdlib.h>

// for singly LL
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

//  for doubly LL
struct Node2
{
    int data;
    struct Node2 *next;
    struct Node2 *previous;
};

// ============== FOR DOUBLY LINKED-LIST ===================
struct Node2 *head2 = NULL;

struct Node2* createNode2(int data)
{
    struct Node2 *temp = (struct Node2*)malloc(sizeof(struct Node2));
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}

void insertNodeAtBiggning2(int data)
{
    struct Node2 *temp = createNode2(data);
    temp->next = head2;
    head2 = temp;
}

void insertNodeAtEnd2(int data)
{
    struct Node2 *node = createNode2(data);
    struct Node2 *temp = head2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->previous = temp;
}

void displyDll()
{
    if(head2 == NULL)
    {
        printf("LINKED LIST IS EMPTY CAN NOT DISPLYA : \n");
        return;
    }
    struct Node2 *temp = head2;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


// =============== FOR SINGLY LINKED-LIST ======================
struct Node* createNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNodeAtBiggning(int data)
{
    struct Node *temp = createNode(data);
    temp->next = head;
    head = temp;
}
void insertNodeAtEnd(int data)
{
    struct  Node  *node = createNode(data);
    if(head == NULL)
    {
        head = node;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

void display()
{
    if(head == NULL)
    {
        printf("LL IS EMPTY CNA NOT PRINT : \n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void deleatNode(int data)
{
    struct Node *temp = head;
    if(head->data == data)
    {
        head = head->next;
        printf("DATA %d DELEATED SUCCEFULLY : \n",data);
        return;
    }
    while(temp != NULL)
    {
        if(temp->next->data == data)
        {
            if(temp->next->next == NULL)
            {
                temp->next = NULL;
            }else
            {
                temp->next = temp->next->next;
            }
            printf("DATA %d DELEATED SUCCEFULLY : \n",data);
            return;
        }
        temp = temp->next;
    }
    printf("DATA %d IS NOT IN LL : \n");
}

int main()
{
    // ======== FOR SINGLY LL ===========

    // insertNodeAtBiggning(20);
    // insertNodeAtBiggning(10);
    // insertNodeAtBiggning(6);
    // insertNodeAtEnd(99);
    // insertNodeAtEnd(100);
    // insertNodeAtEnd(200);
    // insertNodeAtBiggning(18);

    // deleatNode(99);
    // deleatNode(18);

    // display();

    // ========== FOR DOUBLY LL ===========

    insertNodeAtBiggning2(10);
    insertNodeAtBiggning2(20);
    insertNodeAtEnd2(33);
    insertNodeAtBiggning2(15);
    insertNodeAtEnd2(10000);
    
    // displyDll();
}