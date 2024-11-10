#include<stdio.h>
#include<string.h>

#define MAX 100
int top = -1;
char stack[MAX][MAX];

void posfixToInfix(char* posfix);
int isOperator(char ch);
char* pop();
void push(char *str);

int main(){ 
    char posfix[MAX];

    printf("Enter the posfix expression : \n");
    gets(posfix);

    posfixToInfix(posfix);

    printf("The infix of posfix exp %s is %s : ",posfix,stack);

    return 0;
}

// this will conver posfix to infix
void posfixToInfix(char* posfix){

        char op1[MAX], op2[MAX], exp[MAX];

    for(int i = 0;posfix[i] != '\0';i++){
        if(isOperator(posfix[i])){
            // if it is operator
            strcpy(op1,pop());
            strcpy(op2,pop());
            snprintf(exp,sizeof(exp),"(%s%c%s)",op1,posfix[i],op2);
            push(exp);
        }else{
            // if it is operand then push in stack
            char operand[2] = {posfix[i],'\0'};
            push(operand);
        }
    }
}

// This will check is operator or not
int isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/';
}

void push(char *str){
    if(top< MAX-1){
        top++;
        strcpy(stack[top], str);
    }
}

char* pop(){
    if(top == -1){
        return NULL;
    }
    return stack[top--];
}

