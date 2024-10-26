#include <stdio.h>
#define MAX 100
char infix[MAX],posfix[MAX],stack[MAX];
int top = -1;
void infoxToPosfix();
void push(char operator);
char pop();
int isEmpty();
int presidence(char operator);

int main(){

   printf("Enter an expression : ");
//    fgets(infix,99,stdin);
     gets(infix);
     printf("The infix expression is %s ",infix);
     
     // This will convert infix exp into posfix
   infoxToPosfix();
   printf("Posfix expression is %s  ",posfix);
    return 0;
}

//Convert's an infix exp into posfix
void infoxToPosfix(){
    char symbol,popelm;
    int p = 0;
    // Run the loop for the length of an infix  exp
    for(int i = 0;infix[i] != '\0';i++){
     symbol = infix[i];
     
     // If '(' comes then push in stack
     if(symbol == '('){
        push(symbol);
     }
     
     // If '(' comes then pop all operators from stack until we find '('
     else if (symbol == ')')
     {
        while ((popelm = pop()) != '(')
        {
            posfix[p++] = popelm;
        }
        
     }
     
     // If we find any operator
     else if (symbol == '*' || symbol == '+' || symbol == '/' || symbol == '-' || symbol == '^')
     {
        // Check the presedence of an operator
        while (isEmpty() == 1 && presidence(symbol) <= presidence(stack[top]) && stack[top] != '(' && stack[top] != ')')
        {
            char tt = 
            popelm = pop();
            posfix[p++] = popelm;
        }
        push(symbol);
     }

     // This default will handle operand's and will put into the posfix expression
     else{
        posfix[p++] = symbol;
     }
    }

    // After scanning entire infix expression this will pop all the remaning operator's in the stack and will put in posfix exp
    while (top != -1)
    {
        popelm = pop();
        posfix[p++] = popelm;
    }
    
    // This will add '\0' at bthen the end of posfix expression which if help full for various perpose's
    posfix[p] = '\0';
}


// Push operator in stack
void push(char operator){
    if(top == MAX){
        printf("Stack is full can't push further operator's : \n");
        return;
    }
    top++;
    stack[top] = operator;
}

// Pop operator from the satck
char pop(){
    if(top == -1){
        printf("Stack is empty can't pop operator : \n");
        return '0';
    }else{
        char elm = stack[top];
        top--;
        return elm;
    }
   
}

// Check is stack empty or not
int isEmpty(){
    if(top == -1){
        return 0;
    }else{
        return 1;
    }
}

// This will set the presedence of operators
int presidence(char operator){
 switch (operator)
  {
    case '(':
    case ')':
    return 4;
  case '^':
    return 3;
  case '*':
  case '/':
  return 2;
  default:
    return 1;
  }
}
