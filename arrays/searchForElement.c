#include <stdio.h>
int searchForElement(int arr[],int element,int size);
int main(){

  int element=0,size;
  printf("ENTER THE SIZE OF AN ARRAY : \n");
  scanf("%d",&size);
  int arr[size];
  printf("ENTER THE %d ELEMENT'S IN AN ARRAY : \n",size);
  for(int i = 0;i<size;i++){
    scanf("%d",&arr[i]);
  }
  printf("ENTER THE ELEEMNT WHICH YOU WANT TO FIND : \n");
  scanf("%d",&element);

 int isPresent = searchForElement(arr,element,size);

 if(isPresent == 1){
    printf("THE ELEMENT IS PRESENT IN AN ARRAY : \n");
 }else{
    printf("THE ELEMENT IS NOT PRESENT IN AN ARRAY : \n");
 }

    return 0;
}


int searchForElement(int arr[],int element,int size){

 for(int i = 0;i<size;i++){
    if(arr[i] == element){
        return 1;
    }
 }

return -1;
}