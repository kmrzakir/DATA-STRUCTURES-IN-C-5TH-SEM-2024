#include<stdio.h>

#define MAX  100
int stack[MAX];
char prefix[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX-1)
    {
        printf("STACK IS FULL CNA NOT INSERT VALUE : \n");
        return;
    }
    top++;
    stack[top] = value;
}
int pop()
{
    if(top == -1)
    {
        printf("STACK IS EMPTY CNA NOT POP : \n");
        return 0;
    }
    int popElm = stack[top];
    top--;
    return popElm;
}

// this will solve two operands
int evalvate(int a, int b, char operator)
{
    if(operator == '+')
    {
        return a + b;
    } if(operator == '-')
    {
        return a - b;
    } if(operator == '*')
    {
        return a * b;
    } if(operator == '/')
    {
        return a / b;
    } if(operator == '%')
    {
        return a % b;
    }
    return -1;
}

// this will check is operator or not
int isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%';
}

void diaplyArray(char *arr)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c ",arr[i]);
    }
    
}

int sizeOfArray(char *arr)
{
    int size = 0;
    for(int i = 0;arr[i] != '\0';i++)
    {
        size++;
    }
    return size;
}

// this will evalvate the posfix exp
int evalPrefix(char *posfix)
{
    int size = sizeOfArray(posfix);
    for(int i = size-1; i >= 0; i--)
    {
        char symbol = posfix[i];
        if(isOperator(symbol))
        {
            int operand1 = pop();
            int operand2 = pop();
            int value = evalvate(operand1,operand2,symbol);
            push(value);
        }else
        {
            int n = symbol - '0'; // convert char into int
            push(n);
        }
    }
    return pop();
}

int main()
{

    printf("ENTER THE POSFIX EXPRESSION : ");
    fgets(prefix,MAX,stdin);

    printf("THE POSFIX EXPRESSION IS : ");
    diaplyArray(prefix);

   int result = evalPrefix("+45");

    printf("THE VALUE OF POSFIX EXPRESSION %d : ",result);

    return 0;
}