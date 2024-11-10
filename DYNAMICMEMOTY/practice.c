#include<stdio.h>
#include <stdlib.h>

int main(){

   // 
   
   int n;
   printf("Enter the size of n : ",n);
   scanf("%d",&n);

   int *ptr = (int*) malloc(n * sizeof(int));  // Allocates memory for n  integers

    printf("Enter the %d elements : ",n);
   for(int i= 0 ;i<n;i++){
    scanf("%d",&ptr[i]);
   }
   
   printf("The entered values are : ");
 for(int i= 0 ;i<n;i++){
    printf("%d ",ptr[i]);
   }


    return 0;
}