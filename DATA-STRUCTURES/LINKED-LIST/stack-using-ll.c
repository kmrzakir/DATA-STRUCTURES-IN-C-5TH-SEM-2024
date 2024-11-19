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












// wait() function implemetation
 wait(s){ // wait() is also represented by P()
    // It will wait if s <= 0
    while(s <= 0);
    // Other wise it will decremnt s
    s--;
 }
// signal() function implemetation
signal(s){// also represented by V()
    // This will increment s by 1
    s = s + 1;
}

// Producers side code
producer(){
    do
    {
    // It will track how many
    // slots are empty if 
    // empty = 0 that menas 
    // buffer is full so it
    // wil wait until buffer
    // slot will get empty
    wait(empty);

    // This will set lock
    // ifmitux = 1 to it will
    // enter in critical section
    // other wise it will wait 
    wait(mitux);

    // CRITICAL SECTION WILL BE HERE
    // AND HERE IT WILL PRODUCE THE ITEM

    // Here it will releas the lock
    signal(mitux);

    // this will increment the full
    // to indicate that buffer is having 
    // some slots filled
    signal(full);

    } while (1);  
}

// Connsumer side code
    consumer(){
        do
        {
        // First it will check
        // is any flot filled
        // in buffer or not
        wait(full);

        // Then it will check
        // is critical section availabe
        // or not
        wait(mitux);

        // CRITICAL SECTION WILL BE HERE
        // AND HERE IT WILL CONSUME THE ITEM
        // OR WE CAN SAY DATA FROM THE BUFFER

        // Then it will release lock
        // critical section
        signal(mitux);

        // This will incremet empty
        // to indicate how many slots
        // in buffer are empty
        signal(empty);

        } while (1);
        
    }