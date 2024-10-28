#include<stdio.h>

void enque(char ch);
char dqueue();
int isEmpty();
void printQ();

#define MAX 100
int rare = -1, front = -1;
char queue[MAX];
int main(){

    enque('c');
    enque('b');
    enque('d');
    enque('t');
    enque('n');
    // printf("Dqueue element is %c \n", dqueue());
    dqueue();
    printQ();
    return 0;
}

// This function will print the queue
void printQ(){
    if(front == -1 && rare == -1){
        printf("Queue is empty cna not print : \n");
    }else{
        printf("Queue is : ");
        for(int i = front; i <= rare; i++){
            printf("%c",queue[i]);
        }
        printf("\n");
    }
}

// This function will insert eleemnts in quee
void enque(char ch){
    if(front == -1 && rare == -1){
        ++front;
        queue[++rare] = ch;
    }else if(rare == MAX-1){
        printf("Queue is full cna not insert : \n");
    }else{
        queue[++rare] = ch;
    }
}

// This function will remove the front element of the queue
char dqueue(){
    if(front == -1){
        printf("Queue is empty can not deleat element : \n");
        return -1;
    }else if (front == rare)
    {
        char rElm = queue[front];
        front = -1;
        rare = -1;
        return rElm; 
    }
    else{
        char rElm = queue[front];
        front++;
        return rElm;
    }
}


// will check is queue empty or not
int isEmpty(){
    return front == -1;
}