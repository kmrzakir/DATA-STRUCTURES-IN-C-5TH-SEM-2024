#include<stdio.h>

#define MAX 100
char stack[MAX],infix[MAX],prefix[MAX];
int top = -1;

int sizeOf(char *infix);
void infix_to_prefix(int size);
int reverseInfix(int size);

int main()
{

printf("ENTER THE INFIX EXPRESSION : \n");
 gets(infix);

 printf("THE INFIX EXPRESSION IS : %s \n",infix);

 int size = sizeOf(infix);
 printf("THE SIZE OF AN INFIX EXP IS %d :\n",size);
 reverseInfix(size);
 printf("THE REVERSE OF INFIX EXPRESSION IS %s : \n",infix);

//  infix_to_prefix(size);

//  printf("THE POSFIX EXPRESSION IS : %s",posfix);

    return 0;
}

// void infix_to_prefix(int size)
// {
//     reverseInfix(size);
// }

int reverseInfix(int size)
{
 char temp;
 for (int i = 0; i <= size/2; i++)
 {
    temp = infix[i];
    infix[i] = infix[size-1-i];
    infix[size-i] = temp;
 }
    
}



int sizeOf(char *infix)
{
    int size = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        size = size + 1;
    }
    return size;
    
}