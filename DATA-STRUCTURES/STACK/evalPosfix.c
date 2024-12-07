#include<stdio.h>
#define MAX 100
int top = -1;
int stack[MAX];
char solve(char operand1, char operand2, char operator);
int evalPosfix(char* posfix);
int isOperator(char ch);
void push(int ch);
int pop();

// Here is how to eval a posfix exp
// 1. loop from left to right in a posfix exp.
// 2. if we find operand then push it in the stack.
// 3.  if we find any operator then pop the top 2 elemnts of a stack
     // int A =  pop();
     // int B = pop();
// perform the operaton as 
     // int result =  B operator A;
// 4. push he resuilt in the stack.
// after completing the loop return the top eleemnt of the stack which is the result of the posfix exp.

int main(){

    char posfix[MAX];

    printf("Enter the posfix expression : ");
    gets(posfix);

   int result = evalPosfix("23*54*+");

    printf("The result of the posfix expression %s is %d",posfix,result);
   

    return 0;
}

// This will evalvate the posfix expression
int evalPosfix(char* posfix){

    for(int i= 0;posfix[i] != '\0';i++){                  
        if(isOperator(posfix[i])){
            int operand2 = pop();
            int operand1 = pop();                  // 231*+9-
            char operator = posfix[i];
            int result = solve(operand1,operand2,operator);
            push(result);
        }else{
            int n = posfix[i] - '0'; // -'0' will convert char into int
            push(n);
        }
    }
    return pop();
}

// This will solve the opetrator and will return the result
char solve(char operand1, char operand2, char operator){
    switch (operator)
    {
    case '*':
        return operand1 * operand2;
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '%':
        return operand1 % operand2;
    case '/':
        return operand1 / operand2;
    default:
    return -1;
    }
}

// This will check is operator or not
int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/';
}

// Pop function
int pop(){
    if(top == -1){
        printf("Stack is empty can not pop : \n");
        return -1;
    }
    char popelm = stack[top];
    top--;
    return popelm;
}

// Push function
void push(int ch){
    if(top == MAX-1){
        printf("Stack is full can not insret elemnt : \n");
        return;
    }
    stack[++top] = ch;
}