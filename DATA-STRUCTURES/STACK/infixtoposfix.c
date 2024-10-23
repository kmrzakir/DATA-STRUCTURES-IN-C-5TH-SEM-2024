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
   fgets(infix,99,stdin);
   printf("The infix expression is %s : ",infix);
     
   infoxToPosfix();
   printf("Posfix expression is %s : ",posfix);
    return 0;
}

//Convert's an infix exp into posfix
void infoxToPosfix(){
    char symbol,popelm;
    int p = 0;
    for(int i = 0;infix[i] != '\0';i++){
     symbol = infix[i];
     if(symbol == '('){
        push(symbol);
     }else if (symbol == ')')
     {
        while ((popelm = pop()) != '(')
        {
            posfix[p++] = popelm;
        }
        
     }else if (symbol == '*' || symbol == '+' || symbol == '/' || symbol == '-' || symbol == '^')
     {
        while (isEmpty() == 1 && presidence(symbol) <= presidence(stack[top]) && stack[top] != '(' && stack[top] != ')')
        {
            char tt = 
            popelm = pop();
            posfix[p++] = popelm;
        }
        push(symbol);
     }
     else{
        posfix[p++] = symbol;
     }
    }
    while (top != -1)
    {
        popelm = pop();
        posfix[p++] = popelm;
    }
    
    posfix[p] = '\0';
}

void push(char operator){
    if(top == MAX){
        printf("Stack is full can't push further operator's : \n");
        return;
    }
    top++;
    stack[top] = operator;
}

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
int isEmpty(){
    if(top == -1){
        return 0;
    }else{
        return 1;
    }
}

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

// If the incoming operator has the higher Precedence  then operator present in stack then simply push the operator in the stack.

// void infixToPosfix();
// int presidence(char symbol);
// int isEmpty();
// void push(char operator);
// char pop();
// int main(){

// printf("Enter the posfix expression : ");
// fgets(infix, MAX-1,stdin);
// printf("The infix expression is %s ",infix);

// infixToPosfix();

//     return 0;
// }

// void infixToPosfix(){
//   int p = 0;
//        for(int i = 0; infix[i] != '\0';i++){
//         char symbol = infix[i],next;
//               switch (symbol)
//               {
//               case  '(':
//                 push(symbol);
//                 break;
//               case ')' : {
//                 next = pop();
//                 while (!isEmpty() && next != '('){
//                        posfix[p++] = next; 
//                        next = pop();
//                 }
//               }
//               case '*':
//               case '^':
//               case '+':
//               case '-':
//               case '/':{
//                 while (!isEmpty() && presidence(symbol) <= presidence(stack[top]))
//                 {
//                    next = pop();
//                    posfix[p++] = next;
//                    break;
//                 }
//                push(symbol);
//                 break;
//               }
//               default:
//               posfix[p++] = symbol;
//                 break;
//               }
//        }
//        printf("Postfix expression is : \n");
//        for(int i = 0;i<=p;i++){
//         printf("%c",posfix[i]);
//        }
// }
// // This function will set the presidence to the operator's
// int presidence(char symbol){
//   switch (symbol)
//   {
//   case '^':
//     return 3;
//   case '*':
//   case '/':
//   return 2;
//   default:
//     return 1;
//   }
// }

// int isEmpty(){
//   if(top == -1){
//     return 0;
//   }else{
//     return 1;
//   }
// }

// void push(char operator){
//   if(top == MAX){
//     printf("Stack is full can't push further operator's");
//   }else{
//       top++;
//       stack[top] = operator;
//   }
// }

// char pop(){
//   if(top == -1){
//     printf("Stack is empty can't pop operator");
//   }else{
//     int operator = stack[top];
//     top--;
//     return operator;
//   }
// }