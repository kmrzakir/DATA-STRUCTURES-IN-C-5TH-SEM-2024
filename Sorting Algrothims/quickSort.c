#include <stdio.h>
void printArray(int *arr,int size,char str[]);
int partition(int *arr,int ist, int last);
void quickSort(int *arr,int ist,int last);
void swap(int *arr,int *ist,int *last);
int main(){
   
   int arr[] = {2,5,4,1,7,9,10};
   int size = sizeof(arr)/sizeof(int);
   //print priginal array
   printArray(arr,size,"Array before sorts");
   //sort an array using quick sort
   quickSort(arr,0,size-1);
   //print an array after sort
   printArray(arr,size,"Array after sort");
    return 0;
}
//here is a quick sort alorithm
void quickSort(int *arr,int ist,int last){
    if(ist >= last){
        return;
    }
    //this function will divite the array into two parts and will place the pivoted element at the correct place
    //the correct place of pivote is the place where the eleemnets before pivote is less that it and after pivote is greate than it
   int pi = partition(arr,ist,last);
    //this will sort the left array
    quickSort(arr,ist,pi-1);
    quickSort(arr,pi,last);
}
//this function will put the pivote element at the correct place
int partition(int *arr,int ist, int last){
 //here we will consder the pivot as the middle element of an array
    int mid = ist + (last - ist)/2;
    int pivot = arr[mid];
    while (ist <= last)
    {
        while (arr[ist] < pivot)
        {
            ist++;
        }
        while (arr[last] > pivot)
        {
            last--;
        }
        if(ist <= last){
            swap(arr,&ist,&last);
        }
    }
    return ist;
}
//this function will print an array
void printArray(int *arr,int size,char str[]){
printf("%s is : ",str);
for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
}
}
void swap(int *arr,int *ist,int *last){
    int temp = arr[*ist];
    arr[*ist] = arr[*last];
    arr[*last] = temp;

}
