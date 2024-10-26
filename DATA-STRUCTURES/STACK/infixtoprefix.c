#include<stdio.h>
#define MAX 100
int top = -1;
char  stack[MAX];
char prefix[MAX];
char* infixToPrefix(char* infix, int size);
char* reverse(char* infix, int size);
int sizeOfInfix(char* infix);
int isOperator(char charr);
char pop();
void push(char elm);
int operatorPresedence(char operator);
int main(){

char infix[MAX];
int size = 0;
    printf("Enter the infix expression : ");
    gets(infix);
    size = sizeOfInfix(infix);
    char* prefix = infixToPrefix(reverse(infix,size),size);
    printf("The prefix expression is %s  : \n",prefix);

    return 0;
}

// This will convert infix to prefix exp
char* infixToPrefix(char* infix, int size){
    int p=0;
    for(int i = 0;i < size; i++){
      if(infix[i] == '('){
        push('(');
      }else if (infix[i] == ')')
      {
       while (top != -1 && stack[top] != '(')
       {
        char popElm = pop();
        prefix[p] = popElm;
        p++;
       }
       
      }else if (isOperator(infix[i]))
      {
       
       while(top != -1 && operatorPresedence(stack[top]) >= operatorPresedence(infix[i])){
           char popelm = pop();
           prefix[p] = popelm;
           p++;
       }
       push(infix[i]);
      }else{
        prefix[p] = infix[i];
        p++;
      }
    }

    while (top != -1)
    {
        char popElm = pop();
        prefix[p] = popElm;
        p++;
    }
    prefix[p] = '\0';

return prefix;
}

// This will set operator presedence

int operatorPresedence(char operator){
    if (operator == '(' || operator == ')' )
    {
       return 4;
    }else if (operator == '*' || operator == '%' || operator == '/')
    {
        return 2;
    }else if (operator == '^')
    {
      return 3;
    }else{
        return 1;
    }
}

// This will check is operator or not
int isOperator(char charr){
    if(charr == '+' || charr == '-' || charr == '*' || charr == '/' || charr == '^' || charr == '%'){
        return 1;
    }
    return 0;
}

// This will reverse the infix exp to prefix exp
char* reverse(char* infix, int size){
  char temp;
  for(int i = 0;i<size/2;i++){
    temp = infix[i];
    infix[i] = infix[size-1-i];
    infix[size-1-i] = temp;
  }

  // Replace '(' with ')' and vice versa
   for(int i=0;i<size;i++){
     if(infix[i] == '('){
        infix[i] = ')';
    }else if (infix[i] == ')')
    {
        infix[i] = '(';
    }
   }
 return infix;
}

// This will give the size of an infix exp
int sizeOfInfix(char* infix){
 int size = 0;
 for(int i=0;infix[i] != '\0';i++){
    size = size + 1;
 }
 return size;
}

// Pop function 
char pop(){
    if(top == -1){
        printf("Stack is empty can't pop element : \n");
        return '0';
    }
    char popElm = stack[top];
    top--;
    return popElm;
}

// Push function
void push(char elm){
    if(top == MAX){
        printf("Can not push element from the stack : \n");
        return;
    }
    top++;
    stack[top] = elm;
}