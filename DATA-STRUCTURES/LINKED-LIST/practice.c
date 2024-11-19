#include<stdio.h>
#include<stdlib.h>

void dispaly();
void addNodeAtFront(int data);
struct Node *createNode(int data);
void addNodeAtEnd(int data);

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;


int main(){

    addNodeAtEnd(11);
    addNodeAtFront(10);
    addNodeAtFront(20);
    addNodeAtFront(30);
    addNodeAtFront(40);
    addNodeAtEnd(22);
    addNodeAtEnd(33);

    dispaly();

    return 0;
}

// REVERSE LINKED LIST
void reverse(){

    if(head == NULL){
        printf("LINKED-LIST IS EMPTY CAN NOT REVERSE IT : ");
        return;
    }
    struct Node *currNode, *preNode, *nextNode;
    preNode = NULL;
    while (nextNode != NULL)
    {
        
    }
    

}


// CREATE A NODE
struct Node* createNode(int data){
    struct Node *currentNode = (struct Node*)malloc(sizeof(struct Node));
    if(currentNode == NULL){
        printf("Memoty allocation failed : ");
        return NULL;
    }
    currentNode->data = data;
    currentNode->next = NULL;
    return currentNode;
}

// ADD NODE AT THE FRONT
void addNodeAtFront(int data){
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// ADD NODE AT THE END
void addNodeAtEnd(int data){
    struct Node *temp = head;
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }else{
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    }
}

// DISPLAY LINKED LIST
void dispaly(){
    if(head == NULL){
        printf("LINKED LIST IS EMPTY : \n");
        return;
    }
    printf("LINKED LIST IS : ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d => ",temp->data);
        temp = temp->next;
    }
}