#include<stdio.h>
#define MAX 100
int deleatAnElm(int *arr,int elm,int size);

int main()
{
    int arr[MAX];
    int n;

    // enter the size of an array
    printf("ENTER THE SIZE FO AN ARRAY : ");
    scanf("%d",&n);

    // enter the array elemets
    printf("ENTER THE %d ELEEMNTS IN AN ARRAY : ",n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    // print array before deleating an element
    printf("ARRAY BEFORE DELEATRING AN ELEMENT : ");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
   
    // call delelat element function
    int elm = 10;
   int newLength = deleatAnElm(arr,elm,n);

    // printf function after deleat an aeleemnt
   if(newLength != -1){
     printf("ARRAY AFTER DELEEAT AN ELEMET IS : ");
    for(int i = 0;i<newLength;i++){
        printf("%d ",arr[i]);
    }
   }

    return 0;
}

int deleatAnElm(int *arr,int elm,int size){

    int index = -1;

    for(int i = 0;i<size;i++){
        if(arr[i] == elm){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("ELEEMT WHICH YOU WANT TO DELEATE IS NOT PRESENT IN AN ARRYA : \n");
        return -1;
    }

    for(int i = index;i<size-1;i++){
        arr[i] = arr[i+1];
    }

}