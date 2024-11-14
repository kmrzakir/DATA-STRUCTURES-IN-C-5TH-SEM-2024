#include <stdio.h>
#include <stdlib.h>
struct Node* createNode(int data);
void insertNodeAtBiggning(int data);
void insertNodeAtEnd(int data);
void display();
void inserNodeAfter(int data,int position);
void deleatFrontNode();
void deleatEndNode();
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
     // inserNodeAfter(444,1);
     // deleatFrontNode();
     deleatEndNode();
     display();

    return 0;
}

// void deleatNodeAt(int position){
//     if(head == NULL){
//         printf("Can not deleat Node Link list is empty : ");
//         return;
//     }
//     // the position is 1
//     if(position == 1){
//         free(head);
//         head = head->next;
//         return;
//     }
//     struct Node *temp = NULL;
//     for(int i = 1;i<position;i++){
//         if(i == 1) temp = head;
//         temp = temp->next;
//     }
//     if(temp->next == NULL){
//         printf("Link list has less size than %d ",position);
//     }
//     if(temp->next->next == NULL){
//         free(temp->next);
//         temp->next = NULL;
//         return;
//     }
//     temp->next = temp->next->next;
// }

// This will deleat the front node of linked list
void deleatFrontNode(){
    if(head == NULL){
        printf("Node does't exists : ");
        return;
    }
    head = head->next;
}

// This will delate the last node of the linked list
void deleatEndNode(){
    if(head == NULL){
        printf("Linked list is empty can not deleat the end node : ");
        return;
    }
   if(head->next == NULL){
    free(head);
    head = NULL;
   }
   struct Node *temp = head;
  while(temp->next->next){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
   
}

// Insert node in linked list at any position form 1 to the size of Linked list
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
