#include <stdio.h>
#include <stdlib.h>

//cretae an array using malloc

int main(){

  int n,*arr;
  printf("ENTER THE SIZE OF AN ARRAY : \n");
  scanf("%d",&n);
  arr = (int *)malloc(n * sizeof(int));

  if(arr == NULL){
    printf("ARRAY IS NOT INITILIZED : \n");
    return 0;
  }

  printf("ENTER %d ELEMENTS IN AN ARRAY : \n",n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  printf("ENTERED ARRYA IS : \n");
  for(int j=0;j<n;j++){
    printf("%d ",arr[j]);
  }
  free(arr);
  return 0;
}