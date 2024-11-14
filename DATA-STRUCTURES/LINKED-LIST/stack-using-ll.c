#include<stdio.h>
#include<stdlib.h>

struct Node* createNode(int data);
void display();
void push(int data);
void pop();

struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

int main(){

    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();

    return 0;
}

void push(int data){

    struct Node *newNode = createNode(data);
    if(newNode == NULL){
        printf("Memory full can not push new node: \n");
        return;
    }
    newNode->next = top;
    top = newNode;
    printf("Data %d pushed onto the stack : \n",data);
}

void pop(){

    if(top == NULL){
        printf("Stack is empty can not pop a node : \n");
        return;
    }

    struct Node *temp = top;
     top = top->next;
     printf("Poped %d data from the stack : \n",temp->data);
     free(temp);
     return;
}

void display(){
    if(top == NULL){
        printf("Stack is empty cna not display : \n");
        return;
    }
    struct Node *temp = top;
    printf("Stack data is : ");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

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