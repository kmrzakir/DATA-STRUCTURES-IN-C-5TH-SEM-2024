#include <stdio.h>
void insertionSort(int *arr,int size);
int main(){


int arr[6] = {6,4,5,1,3,2};
//this function will sort an arrya using insertion sort
insertionSort(arr,6);
    return 0;
}

void insertionSort(int *arr,int size){

int temp;
  for(int i=;i<size;i++){
  temp = arr[i];
  int j = i-1;
  while (j>=0 && temp < arr[j]){
    arr[j+1] = arr[j]; 
    j--;
  }
  arr[j+1] = temp;
  }

    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }

}