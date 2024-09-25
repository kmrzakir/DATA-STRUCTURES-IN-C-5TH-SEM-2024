#include<stdio.h>
void selectionSort(int *arr, int size);
int main(){
    
    int arr[7] = {4,7,3,1,8,6,2};

    selectionSort(arr,7);
    return 0;
}
    // int arr[7] = {4,7,3,1,8,6,2};
void selectionSort(int *arr, int size){
    int temp;
    for(int i=0;i<size-1;i++){
        int ind = i;
        for(int j=i+1;j<size;j++){
            if(arr[j] < arr[ind]){
              ind = j;
            }
        }
        if(ind != i){
        temp = arr[ind];
        arr[ind] = arr[i];
        arr[i] = temp;
        }
    }
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
} 