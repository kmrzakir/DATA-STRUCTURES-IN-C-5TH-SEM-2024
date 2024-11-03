#include<stdio.h>

// Pointer is a special type of variable used to store the address of some variable.

int main(){

    int a = 10;

    // Decleration of a pointer
    int *p;

    // Assignment of a pointer
    p = &a;

    // Derefrencing : To access the value stored
    // at the memory address the pointer holds, you use the * operator again (called dereferencing).
    printf("Vlaue is %d : \n",*p);

    // Accessing the address of pointer p
    printf("Address of ptr is %p : \n",&p);

    // printing the address of a stored by pointer p
    // NOTE : p == &a
    printf("The address stored by pointer p is %p : \n",p);
    

    return 0;
}