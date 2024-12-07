#include<stdio.h>
#define MAX 100
char stack[MAX],posfix[MAX],infix[MAX];
int top = -1;

void infix_to_posfix();
void push(char ch);
char pop();
int isOperator(char ch);
int presidence(char ch);

int main()
{

 printf("ENTER THE INFIX EXPRESSION : \n");
 gets(infix);

 printf("THE INFIX EXPRESSION IS : %s \n",infix);

 infix_to_posfix();

 printf("THE POSFIX EXPRESSION IS : %s",posfix);

  return 0;
}

void infix_to_posfix(){

    char symbol;
    int p = -1;

  for (int i = 0; infix[i] != '\0'; i++)
  {
    symbol = infix[i];
    if(symbol == '(')
    {
      push(symbol);
    }else if (symbol == ')')
    {
      char popelm;
      while ((popelm = pop()) != '(')
      {
        p++;
        posfix[p] = popelm;
      }
    }else if (isOperator(symbol))
    {
      while (top != -1 && presidence(symbol) <= presidence(stack[top]) && stack[top] != '(' && stack[top] != ')')
      {
        char popelm = pop();
        p++;
        posfix[p] = popelm;
      }
      push(symbol);
    }else{
      p++;
      posfix[p] = symbol;
    }
    
    
  }

  while (top != -1)
  {
    p++;
    posfix[p] = pop();
  }
    
}

int isOperator(char ch)
{
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

int presidence(char ch)
{
  if(ch == '^')
  {
    return 3;
  }else if (ch == '*' || ch == '/' || ch == '%')
  {
    return 2;
  }else{
    return 1;
  }
  
}

void push(char ch){

  if(top == MAX-1)
  {
    printf("STACK IS FULL CAN NOT PUSH : \n");
    return;
  }
  top++;
  stack[top] = ch;
  
}

char pop()
{
  if(top == -1){
    printf("CAN NOT POP BECAUSE STACK IS EMPTY : \n");
    return -1;
  }
  char popelm  = stack[top];
  top--;
  return popelm;
}