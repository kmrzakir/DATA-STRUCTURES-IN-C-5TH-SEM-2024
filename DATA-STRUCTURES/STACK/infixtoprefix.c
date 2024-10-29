#include<stdio.h>
#include<string.h>
#define MAX 100
int top = -1;
char  stack[MAX];
int infixSize(char* infix);
char* reverse(char* infix, int size);
void push(char operator);
char pop();
void infixToPrefix(char* infix, char* prefix,int size);
int isEmpty();
int isOperator(char ch);
int presidence(char operator);

// solve a+b*(a-h)-u prefix should be "-+a*b-ahu" not "+a-*b-ahu"
 

int main(){

   char infix[MAX], prefix[MAX], revInfix[MAX];


  printf("Enter the infix expression : ");
  gets(infix);
  printf("The entered expression is %s : \n",infix);
  
  int size = infixSize(infix);
  printf("The size of infix exp is %d : \n",size);

  strcpy(revInfix, reverse(infix,size));
  printf("The reverse string is %s : \n",revInfix);

   infixToPrefix(revInfix,prefix, size);
  printf("The prefix exp is %s : \n",prefix);

    return 0;
}

// Thsi will convert infix into prefix
void infixToPrefix(char* infix, char* prefix,int size){

    int p = -1;

    for(int i = 0;i<size;i++){
        if(infix[i] == '('){
            push('(');
        }else if (infix[i] == ')')
        {
            while (isEmpty() == 1 && stack[top] != '(')  
            {
                char popElm = pop();
                prefix[++p] = popElm;
            }
            pop();
        }else if (isOperator(infix[i]))
        {
            while(isEmpty() && presidence(stack[top]) >= presidence(infix[i]) && stack[top] != '(' && stack[top] != ')'){
                char popElm = pop();
                prefix[++p] = popElm;
            }
            push(infix[i]);

        }else{
            prefix[++p] = infix[i];
        }    
    }
    while (isEmpty())
    {
        char popElm = pop();
        prefix[++p] = popElm;
    }

    prefix[++p] = '\0';


    // Finally reverse the exp
    int sizeofPrefix = infixSize(prefix);
    strcpy(prefix,reverse(prefix, sizeofPrefix));
    return;
}

// This will reverse the infix expression
char* reverse(char* infix, int size){
    char temp;
   for (int i = 0;i < size/2;i++){
    temp = infix[i];
    infix[i] = infix[size-1-i];
    infix[size-1-i] = temp;
   }

   // swap '(' with ')' and vice versa
   for(int i = 0;i < size; i++){
    if(infix[i] == '('){
        infix[i] = ')';
    }else if (infix[i] == ')')
    {
        infix[i] = '(';
    }
   }
   return infix;
}

// This will return the size of an infix expression
int infixSize(char* infix){
    
    int size =  0;
    for(int i=0; infix[i] != '\0';i++){
        ++size;
    }
    return size;
}

// Push function 
void push(char operator){
    if(top == MAX){
        printf("Stack is full can not push : \n");
    }
    stack[++top] = operator;
}

// Pop function
char pop(){
    if(top == -1){
        printf("Stack is empty cna not pop : \n");
        return '\0';
    }
    return stack[top--];
}

// checks is stack empty or not
int isEmpty(){
    return top >= 0;
}

// Checks is operator or not
int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

// Set operator presedence 
int presidence(char operator){
    switch (operator)
    {
    case '^':{
          return 3;
    }
    case '*' :
    case '/' :
    case '%' :{
        return 2;
    }
    case '+' :
    case '-' :{
        return 1;
    }
    default:
        return 4;
    }
}

