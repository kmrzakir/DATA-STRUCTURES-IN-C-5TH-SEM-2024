// Here is how to convert an posfix expression into infix.
// 1. scan from left to write.
// 2. if we find an operand then simply push it in the satck.
// 3. if we find an operator then pop top two elements of a stack like this :
// char operand1 = pop();
// char operand2 = pop();
//  and then insert operator in between these two operators like this
// char newVale = operand2 operator operand1
// push this newvalue in the stack.
//  do this untill the posfix expression gets scan complete


#include<stdio.h>
#include<string.h>

#define MAX 100
char posfix[MAX];
char stack[MAX][MAX];
int top = -1;

int isOperator(char symbol)
{
    return symbol == '*' || symbol == '%' || symbol == '-' || symbol == '/' || symbol == '+';
}

void push(char *str)
{
    if (top == MAX-1)
    {
        printf("STACK IS FULL CNA NOT INSERT DATA : \n");
    }else
    {
        top++;
        strcpy(stack[top],str);
    }
}
char* pop()
{
    if(top == -1)
    {
        printf("STACK IS EMPTY CNA NOT DELEAT AN ELEMENT : \n");
        return NULL;
    }
    return stack[top--];
}

void posfixToInfix(char *infix)
{
    char operand1[MAX],operand2[MAX],exp[MAX];
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char symbol = infix[i];
        if(isOperator(symbol))
        {
            strcpy(operand1,pop());
            strcpy(operand2,pop());
            snprintf(exp,sizeof(exp),"(%s%c%s)",operand2,symbol,operand1);
            push(exp);
        }
        else
        {
            char operand[2] = {symbol,'\0'};
            push(operand);
        }
    }
    
}

int main()
{
    posfixToInfix("23*4+");
    printf("THE INFIX OF THIS {23*54*+} POSFIX EXP IS %s : ",stack);
}