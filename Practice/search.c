#include<stdio.h>
int linear_search(int *arr,int size,int elm);
int binary_serach(int *arr,int size,int elm);

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int bool = binary_serach(arr,size,9);
    if(bool != -1)
    {
        printf("ELEMENT FOUND AT %d INDEX : ",bool);
    }else
    {
        printf("ELEMENT DID NOT FOUND : ");
    }
    return 0;
}

int binary_serach(int *arr,int size,int elm)
{
    int start = 0;
    int end = size-1;
    int mid;
    while (start < end)
    {
        mid = (start + end)/2;
        if(arr[mid] == elm)
        {
            return mid;
        }else if(elm < arr[mid])
        {
            end  = mid -1;
        }else if (elm > arr[mid])
        {
            start = mid + 1;
        }   
    }
    return -1;
}

int linear_search(int *arr,int size,int elm)
{
    for(int i = 0;i<size;i++)
    {
        if(arr[i] == elm)
        {
            return i;
        }
    }
    return -1;
}