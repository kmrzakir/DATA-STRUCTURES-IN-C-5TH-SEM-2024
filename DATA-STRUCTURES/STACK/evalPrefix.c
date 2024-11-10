#include<stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int size = 0;
int prefixEval(char* prefix);
int isOperator(char ch);
int solve(int operand1, int operand2, char operator);
void push(int elm);
int pop();
int sizeofexp(char* perfix);

// How to eval prefix exp
// 1. scan prefix expression from right to left (in case of posfix val we scan from left to right). And this the only difference
// 2. if we find operand then simply push it in the stack.
// 3.  if we find the operator pop top two elements of the stack and perform the operaton as
    // int A = pop();
    // int B = pop();
    // int result = A operator B;
// 4.  push the result in the stack.
// 5.  after completing the entire prefix exp return the top of the stack which is the result of the prefix exp.


int main(){
    char prefix[MAX];

    printf("Enter the prefix expression : ");
    gets(prefix);
    
    sizeofexp(prefix);

    int result = prefixEval(prefix);

    printf("The reslult of %s prefx exp is %d ",prefix,result);

    return 0;
}

// This will find the size of prefix exp
int sizeofexp(char* perfix){
    for(int i = 0;perfix[i] != '\0';i++){
        size = size + 1;
    }
    return size;
}

// This will eval the perfix expp
int prefixEval(char* prefix){

    for(int i = size-1;i >= 0;i--){
        if(isOperator(prefix[i])){
            int A = pop();
            int B = pop();
            int result = solve(A, B, prefix[i]);
            push(result);
        }else{
            int operand = prefix[i] - '0';
            push(operand);
        }
    }
    return pop();
}

// This will check is operator or not
int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/' || ch == '^';
}

int solve(int operand1, int operand2, char operator){
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

int pop(){
    if(top == -1){
        printf("Stack is empty cna not pop");
        return -1;
    }
    int popelm = stack[top];
    top--;
    return popelm;
}

void push(int elm){
    if(top == MAX-1){
        printf("Stack is full cna not push : \n");
        return;
    }
    stack[++top] = elm;
}