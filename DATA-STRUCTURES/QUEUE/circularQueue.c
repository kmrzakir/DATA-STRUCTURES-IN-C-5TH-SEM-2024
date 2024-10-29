#include<stdio.h>

void enqueue(char ch);
char dQueue();

#define MAX 100
char cQueue[MAX]; // cQueue means circular queue
int front = -1, rare = -1;

int main(){

    enqueue('a');
    enqueue('b');
    enqueue('c');
    enqueue('d');
    dQueue();

    printQ();

    return 0;
}

// This will print queue
// void printQ(){
//     if(front == -1){
//         printf("Queue is empty  can not print: \n")
//     }else{
//         int i = front;
//         printf("Queue is : ");
//         while ((i % MAX <= rare % MAX))
//         {
//             printf("%c",cQueue[i]);
//             i++;
//         }
//         printf("\n");
//     }
// }

// Dqueue function
char dQueue(){
    if(front == -1){
        printf("Queue is empty can not dque : \n");
        return -1;
    }else{
        char rElm  = cQueue[front];
        if(front == rare){
            front = rare = -1;
        }else{
            front = (front + 1) % MAX;
        }
        return rElm;
    } 
}

// enque function to insert element in queue
void enqueue(char ch){
    if((rare + 1)%MAX == front){
        printf("Queue is full cna not insert elements : ");
    }else if (rare == -1 && front == -1){
       front = rare = 0;
       cQueue[rare] = ch;
    }else{
        rare = (rare + 1) % MAX;
        cQueue[rare] = ch;
    }
}