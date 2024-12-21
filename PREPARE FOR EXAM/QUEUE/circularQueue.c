#include<stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rare = -1;
void enQueue(int data);
void deQueue();
void displyQueue();

int main()
{

    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    deQueue();

    displyQueue();

    return 0;
}

void displyQueue()
{
    if(rare == front && rare == -1)
    {
        printf("QUEUE IS EMPTY CNA NOT DISPLY : \n");
        return;
    }
    int temp = front;
    do
    {
        printf("%d ",queue[temp]);
        temp = (temp + 1) % MAX;
    } while (temp != rare);
    printf("%d ",queue[temp]); 
}

void deQueue()
{
    if(rare == front && rare == -1)
    {
        printf("QUEUE IS EMPTY CNA NOT DEQUEUE : \n");
        return;
    }
    if(rare == front)
    {
        rare = -1;
        front = -1;
    }else
    {
        front = (front + 1) % MAX;
    }
    printf("DELEATED DATA SUCCEFULLY : \n");
}

void enQueue(int data)
{
 if(((rare+1)%MAX) == front)
 {
    printf("QUEUE IS FULL CNA NOT INSERT DATA : \n");
    return;
 }
 if(front == rare && rare == -1)
 {
    front = 0;
    rare = 0;
    queue[rare] = data;
    return;
 }
 rare = (rare + 1) % MAX;
 queue[rare] = data;
}

