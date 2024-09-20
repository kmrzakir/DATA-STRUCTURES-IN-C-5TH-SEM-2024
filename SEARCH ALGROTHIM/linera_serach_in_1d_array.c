#include<stdio.h>
int linearSearch();
int main(){

   int isPresent = linearSearch();

   if(isPresent == 1){
    printf("ELEMENT IS PRESENT : \n");
   }else{
     printf("ELEMENT IS NOT PRESENT : \n");
   }

    return 0;
}

//THIS METHOD WHILL CHECK FOR THE ELEMENT AND IF FIND'S IT WILL THEN RETURN 1(TRUE) ELSE -1(FALSE)
int linearSearch(){
    int arr[] = {2,3,4,5,6,7,8,9,10},elm;
    int size = sizeof(arr)/sizeof(int);
    printf("ENTER THE ELEMENT WHICH YOU WANT TO FIND IN AN ARRAY : \n");
    scanf("%d",&elm);
    for(int i =0;i<size;i++)
    {
        if(arr[i] == elm){
            return 1;
        }
    }
    return -1;
}