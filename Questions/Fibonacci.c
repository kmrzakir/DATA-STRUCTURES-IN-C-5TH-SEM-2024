#include <stdio.h>
int sumOfFirstNFiboNumbers(int n);
int main()
{

   int n = 1;
   //this function will return the sum of first n fibo number's using for loop
   int sumOfFirstNFiboNo = sumOfFirstNFiboNumbers(n);
   printf("THE SUM OF FIRST %d FIBO NUMBERS IS %d and  ",n,sumOfFirstNFiboNo);
     
     return 1;
}

int sumOfFirstNFiboNumbers(int n){

    int first = 0,second = 1,sum = 0,ss=0;
    
    for(int i = 1;i<=n;i++){
        ss += first;
        sum = first + second;
        first = second;
        second = sum;
    }
    return ss;
}