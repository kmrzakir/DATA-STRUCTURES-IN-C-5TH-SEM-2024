#include<stdio.h>
#define MAX 100
char prefix[MAX];
char stack[MAX];
char infix[MAX];
int top = -1;



// this will display any array
void display(char *arr)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c ",arr[i]);
    }
    
}

// this will set the presedence on operators
int presedence(char symbol)
{
    if(symbol == '(' || symbol == ')')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/' || symbol == '%')
    {
        return 2;
    }else{
        return 1;
    }
    
}

// this will check is symbol an operator ot not
int isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%';
}

// this will pop symbol in stack
char pop()
{
    if(top == -1)
    {
        printf("STACK IS EMPTY CNA NOT POP : \n");
        return 0;
    }
    char popElm = stack[top];
    top--;
    return popElm;
}

// this will push symbol in stack
void push(char symbol)
{
    if(top == MAX-1)
    {
        printf("STACK IS FULL CNA NOT PUSH SYMBOL : \n");
        return;
    }
    top++;
    stack[top] = symbol;
}

// this will convert an infix to posfix
void infix_to_Posfix(char *infix)
{
    char popElm;
    int p = -1;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];
        if(symbol == '(')
        {
            push(symbol);
        }else if (symbol == ')')
        {
            while (top != -1 && (popElm = pop()) != '(')
            {
                p++;
                prefix[p] = popElm;
            }
        }
        else if (isOperator(symbol))
        {
            while(top != -1 && presedence(symbol) <= presedence(stack[top]) && stack[top] != '(' && stack[top] != ')')
            {
                popElm = pop();
                p++;
                prefix[p] = popElm;
            }
            push(symbol);
        }else
        {
            p++;
            prefix[p] = infix[i];
        }  
    }
    while (top != -1)
    {
        popElm = pop();
        p++;
        prefix[p] = popElm;
    }
    p++;
    prefix[p] = '\0'; 
}

int main()
{
    printf("ENTER THE INFIX EXPRESSION : \n");
    // fgets(infix,MAX,stdin);
    gets(infix);

    printf("THE INFIX EXPRESSION IS : ");
    display(infix);
    
    infix_to_Posfix(infix);

    printf("THE POSFIX EXPRESSION IS : ");
    display(prefix);

}