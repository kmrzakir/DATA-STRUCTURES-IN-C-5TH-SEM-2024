//Here we are implemeting a stack using array
#include <stdio.h>
#define MAX 10 //Maximum size of the satck
int stack[MAX]; //Declearing an array here with size MAX and we will use this array to implement stack
int top = -1; //This is the top of a satck we initilize it with -1 that indicates stack is empty for now

//function to push/insert an elements in a stck at the top
void push(int value){
     
    //check over flow condition
    if(top < MAX){
        top++;
        stack[top] = value;
        printf("value %d pushed in satck \n",value);
    }else{
        printf("Stact over flow occured : \n");
    }
}

//Function to pop the last eleemnt of a satck
void pop(){
    //check under flow condition
    if(top == -1){
        printf("Stack does not exists : \n");
        return;
    }
    top--;
    printf("removed %d element form the stack",stack[top+1]);
}

//Function to display all elements of an array
void display(){
    if(top == -1){
        printf("Stack does not exists : \n");
        return;
    }
    printf("Stack eleemnts are : \n");
    for(int i = top; i >= 0 ; i--){
     printf("%d ",stack[i]);
    }
}

int main(){
  
  push(10);
  push(20);
  push(30);
  push(40);
  pop();
  push(50);
  push(60);
  display();
int i=0,n=0,j=0,total;
  return 0;
}