#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertNodeAtStart(char data[]);
struct Node *createNode(char data[]);
void insertNodeAtStart(char data[]);
void insertNodeAt(char data[],int position);
void insertNodeAtEnd(char data[]);
void dispaly();

struct Node
{
    char data[100];
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;


int main(){

    insertNodeAtStart("zkair");
    insertNodeAtStart("aamar");
    insertNodeAtStart("danish");
    insertNodeAtStart("sahil");
    insertNodeAtEnd("kk");
    insertNodeAtEnd("ssss");
    insertNodeAtEnd("kkrrr");
    insertNodeAtEnd("ssssttt");
    // insertNodeAt("ooo",2);

    dispaly();

    return 0;
}

// void insertNodeAt(char data[],int position){
//     struct Node *newNode = createNode(data);
//     if(head == NULL && position == 1){
//         head = newNode;
//         return;
//     }
//     struct Node *temp = head;
//     for(int i = 1;i < position;i++){
//         temp = temp->next;
//         if(temp == NULL && i < position){
//             printf("position is out of bound");
//             return;
//         }
//     }
//     newNode->next = temp;
//     newNode->prev = temp->prev;
//     temp->prev->next = newNode;
//     temp->next = newNode;
// }

// DISPLAY LINKED LIST
void dispaly(){
    if(head == NULL){
        printf("CAN NOT PRINT LINKED LIST IS EMPTY : \n");
        return;
    }
    struct Node *temp = head;
    printf("DOUBLY LINKED LIST DATA IS : ");
    while (temp != NULL)
    {
        printf("%s ",temp->data);
        temp = temp->next;
    }
    
}

// INSERT NODE AT THE END
void insertNodeAtEnd(char data[]){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// INSERT NORD AT THE BIGGNING
void insertNodeAtStart(char data[]){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// CREATE NOTE HERE
struct Node *createNode(char data[]){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("DATA ALLOCATION FAILE D : \n");
        return NULL;
    }
    strcpy(newNode->data,data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}