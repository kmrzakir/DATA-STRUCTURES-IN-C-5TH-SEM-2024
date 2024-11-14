#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int data);
void insertNodeAtBiggning(int data);
void insertNodeAtEnd(int data);
void displayFromBiggning();


// implementation of doubly linked-list

// declearing node here
struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
};

// declearing head here
struct Node *head = NULL;

int main(){

    insertNodeAtEnd(20);
    insertNodeAtEnd(40);
    insertNodeAtBiggning(60);
    insertNodeAtBiggning(80);



    displayFromBiggning();

    return 0;
}

void inserNodeAfter(int data,int position){
    struct Node *newNode = createNode(data);
    struct Node *temp = NULL;
    for(int i = 0;i<position;i++){
        if(i == 0){
            temp = head;
        }else{
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Size of linke list is smaller than %d :",position);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// cretaing node here
struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed : \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

// insert node at the biggning
void insertNodeAtBiggning(int data){
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    head->previous = newNode;
    newNode->next = head;
    head = newNode;
    
}

// insert node at the end
void insertNodeAtEnd(int data){
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->previous = temp;
    temp->next = newNode;
}

// display doubly linked list
void displayFromBiggning(){
    struct Node *temp = head;
    if(temp == NULL){
          printf("Doubly linked-list does not exists : \n");
        return;
    }
    printf("Data in doubly linked list is : \n");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
      
}