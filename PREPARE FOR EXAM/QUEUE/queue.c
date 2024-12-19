#include<stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rare = -1;

int dQueu();
void displayQueue();
void enque(int data);


int main()
{
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50);
    enque(60);
    enque(70);

    dQueu();

    displayQueue();

    return 0;
}

void displayQueue()
{
    if(rare == front && rare == -1)
    {
        printf("QUEUE IS EMPTY CNA'T DISPLAY : \n");
        return;
    }
    int temp = front;
    do
    {
        printf("%d ",queue[temp]);
        temp++;
    } while (temp <= rare);
    
}

int dQueu()
{
    if(rare == front && rare == -1)
    {
        printf("QUEUE IS EMPTY CAN'T DEQUEUE : \n");
        return -1;
    }
    if(rare == front)
    {
        int elem = queue[rare];
        front = -1;
        rare = -1;
        return elem;
    }
    int elem = queue[front];
    front++;
    return elem;
}

void enque(int data)
{
    if(rare == front && rare == -1)
    {
        rare++;
        front++;
        queue[rare] = data;
        return;
    }
    if(rare == MAX-1)
    {
        printf("QUEUE IS FULL CNA'N ENQUEUE DATA : \n");
        return;
    }
    rare++;
    queue[rare] = data;
}


