//  HERE IS HOW TO CONVERT A PREFIX EXPRESSION INTO POSFIX.
// 1. scan from right to left.
// 2. if we find an operand then push it in stack
// 3. if we find the operator then pop top two of stack and do this :
// p1 = pop();
// p2 = pop();
// write exp = p1 operator p2
// put this exp in stack and repeate this process untill we will sacn entire prefix expression.

#include<stdio.h>
#include<string.h>

#define MAX 100
char prefix[MAX];
char stack[MAX][MAX];
int top = -1;

int isOPerator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '%' || symbol == '/';
}
void push(char *str)
{
    if(top == MAX-1)
    {
        printf("STACK IS FULL CNA NOT PUSH FURTTHER DATA : \n");
        return;
    }
    top++;
    strcpy(stack[top],str);
}
char* pop()
{
    if(top == -1)
    {
        printf("STACK IS EMPTY CNA NOT POP DATA ELEMENT : \n");
        return NULL;
    }
    return stack[top--];
}
int sizeOfArray(char *arr)
{
    int size = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}
void prefix_to_posfix(char *prefix)
{
    char operand1[MAX],operand2[MAX],exp[MAX];
    int size = sizeOfArray(prefix);
    for(int i = size-1;i >= 0; i--)
    {
        char symbol = prefix[i];
        if(isOPerator(symbol))
        {
            strcpy(operand1,pop());
            strcpy(operand2,pop());
            snprintf(exp,sizeof(exp),"(%s%c%s)",operand1,symbol,operand2);
            push(exp);
        }else
        {
            char operand[2] = {symbol,'\0'};
            push(operand);
        }
        
    }
}
int main()
{
    
    prefix_to_posfix("-+346");

    printf("THE INFIX EXP IS : %s ",stack);
    
    return 0;
}