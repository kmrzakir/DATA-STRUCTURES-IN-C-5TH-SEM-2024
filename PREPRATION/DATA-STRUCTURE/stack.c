#include<stdio.h>
#define MAX 100
int isEmpty();
int isFull();
void push(int data);
int pop();
void display();


int stack[MAX];
int top = -1;

int main()
{
    push(20);
    push(40);
    push(60);
    push(80);
    push(100);

    display();
}

void push(int data)
{
if(isFull())
{
    printf("STACK IS FULL CNA NOT PUSH : \n");
    return;
}
top++;
stack[top] = data;
}

int pop()
{
    if(isEmpty())
    {
        printf("STACK IS EMPTY CAN NOT POP : \n");
        return -1;
    }
    int popElm= stack[top];
    top--;
    return popElm;
}

void display()
{
if(isEmpty())
{
    printf("STACK IS EMPTY CNA NOT DISPLAY : ");
    return;
}
int temp = top;
printf("STACK ELEMENTS ARE : ");
for(int i = 0;i<=top;i++)
{
printf("%d ",stack[i]);
}
}

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX-1;
}

