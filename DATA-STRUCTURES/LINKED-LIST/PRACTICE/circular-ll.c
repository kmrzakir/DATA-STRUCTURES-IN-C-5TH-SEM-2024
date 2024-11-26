#include<stdio.h>
#include<stdlib.h>

void insertNodeAtEnd(int data);
struct Node* createNode(int data);
void insertNodeAtFront(int data);
void deleatFrontNode();
void deleatEndNode();
void inserNodeAt(int data,int position);
void deleatNodeAt(int position);
int getLength();
void display();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL; // KEEP THE ADDRESS OF END NODE


int main(){

    insertNodeAtEnd(10);
    insertNodeAtEnd(20);
    insertNodeAtEnd(30);
    insertNodeAtEnd(40);
    insertNodeAtEnd(50);
    insertNodeAtEnd(60);
    insertNodeAtFront(5);
    insertNodeAtFront(2);
    printf("lengthe is %d ",getLength());
    inserNodeAt(99,2);
    deleatNodeAt(4);
    display();

    return 0;
}

void deleatNodeAt(int position){
    int length = getLength();
    if(position <= 0 || position > length)
    {
       printf("positin is not valid : "); 
    }else if(position == 1)
    {
        deleatFrontNode();
    }else if(position == length)
    {
        deleatEndNode();
    }else{
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

void inserNodeAt(int data,int position){
   
   int length = getLength();
   if(position <= 0 || position > length)
   {
    printf("positin is not valid : ");
   }else if(position == 1)
   {
    insertNodeAtFront(data);
   }else if(position == length)
   {
    insertNodeAtEnd(data);
   }else{
    struct Node *temp = head;
    for(int i = 1;i<position-1;i++)
    {
        temp = temp->next;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
   }
    
}

int getLength(){
    if(head == NULL){
        return 0;
    }
    int length = 1;
    struct Node *temp = head;
    while(temp->next != tail->next){
        length++;
        temp = temp->next;
    }
    return length;
}

void deleatEndNode(){
    if(head == tail){
        printf("CIRCULAR LINKED LIST IS HAVING ONLY ONE NODE SO DO NOT DELEAT IT : ");
        return;
    }
    struct Node *deleatNode = tail;
    struct Node *temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    tail->next = head;
}

void deleatFrontNode(){
    if(head == tail){
        printf("CIRCULAR LINKED LIST IS HAVING ONLY ONE NODE SO DO NOT DELEAT IT : ");
        return;
    }
    struct Node *deleteNode = head;
    head = head->next;
    tail->next = head;
    free(deleteNode);
}

void display(){
    if(head == NULL){
        printf("CIRCULAR LINKED LIST IS EMPTY CAN NOT PRINT : \n");
        return;
    }
    struct Node *temp = head;
    printf("CIRCULAR LL DATA IS : ");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != head);
    
}

struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("MEMOTY ALLOCATION FAILED : \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtFront(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        return;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head;
}

void insertNodeAtEnd(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

