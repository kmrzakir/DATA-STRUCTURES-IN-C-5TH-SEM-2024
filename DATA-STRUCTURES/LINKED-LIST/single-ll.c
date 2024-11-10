#include <stdio.h>
#include <stdlib.h>
struct Node* createNode(int data);
void insertNodeAtBiggning(int data);
void insertNodeAtEnd(int data);
void display();
// Implementation of singly linked list

// Defining Node here
struct Node
{
    int data;
    struct Node *next;
};

// Defining head here
struct Node *head = NULL;


int main(){
    
     insertNodeAtBiggning(20);
     insertNodeAtBiggning(40);
     insertNodeAtBiggning(60);
     insertNodeAtBiggning(80);
     insertNodeAtEnd(100);
     insertNodeAtEnd(200);

     display();

    return 0;
}

// Will cretae Node and will return it refrence
struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed : \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert node at the biggening
void insertNodeAtBiggning(int data){
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
// insert node at the end
void insertNodeAtEnd(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
}
// this will display link list
void display(){
    printf("The link-list is : \n");
    struct Node *temp = head;
    if(temp == NULL){
        printf("Link-list is empty can not : \n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
