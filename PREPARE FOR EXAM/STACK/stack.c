#include<stdio.h>
#define MAx 100
int top = -1;
int stack[MAx];


void printStack();
void push(int data);
int pop();
int isEmpty();
int size();

int main()
{

    push(2);
    push(2);
    push(2);
    push(2);
    push(2);
    push(2);

    printStack();

    return 0;
}
void push(int data)
{
    if(top == MAx-1)
    {
        printf("STACK IS FULL CAN'T PUSH DATA : \n");
        return;
    }
    top++;
    stack[top] = data;
}
int pop()
{
    if(top == -1)
    {
        printf("STACK IS EMPTY CNA NOT POP : \n");
        return -1;
    }
    int popElm = stack[top];
    top--;
    return popElm;
}
void printStack()
{
    if(top == -1)
    {
        printf("STACK IS RMPTY CNA NOT DISPALY : \n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
     printf("%d ",stack[i]);   
    }  
}

int isEmpty()
{
    return top;
}

int size()
{
    return top;
}