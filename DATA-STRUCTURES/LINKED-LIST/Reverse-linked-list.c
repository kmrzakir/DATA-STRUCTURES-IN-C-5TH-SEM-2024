#include<stdio.h>
#include<stdlib.h>

struct Node* cretaeNode(int data);
void inserNodeAtFront(int data);
void insertNodeAtEnd(int data);
void displayLl();
void reverse();

// NODE DECLERATION HERE
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;


int main(){

    insertNodeAtEnd(20);
    insertNodeAtEnd(40);
    inserNodeAtFront(50);
    inserNodeAtFront(10);
    inserNodeAtFront(5);

    displayLl();

    reverse();

    printf("\nReverse linked-list is : \n");
    displayLl();

    return 0;
}

// THIS WILL REVERSE LINKED-LIST
void reverse(){
    if(head == NULL){
        printf("Linked-List is empty can not reverse : ");
        return;
    }
    struct Node *preNode, *currentNode, *nextNode;
    preNode = NULL;
    currentNode = nextNode = head;
    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    }
    head = preNode;
}

// DISPLAY LINKED LIST
void displayLl(){
    if(head == NULL){
        printf("Linked list is empty can not display : \n");
        return;
    }
    struct Node *temp = head;
    printf("Linked-list data is : ");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

// THIS WILL INSERT NODE AT THE END
void insertNodeAtEnd(int data){
    struct Node *newNode = cretaeNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// THIS WILL INSERT NODE AT THE BEGGINING
void inserNodeAtFront(int data){
    struct Node *newNode = cretaeNode(data);
    newNode->next = head;
    head = newNode;
}

// THIS WILL CREATE NODE
struct Node* cretaeNode(int data){
    struct Node *currentNode = (struct Node*)malloc(sizeof(struct Node));
    if(currentNode == NULL){
        printf("Memory allocation failed : \n");
        return NULL;
    }
    currentNode->data = data;
    currentNode->next = NULL;
    return currentNode;
}