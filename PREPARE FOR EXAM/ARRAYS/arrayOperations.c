#include<stdio.h>
#define MAX 100

//Operation	Time Complexity (Best Case)	Time Complexity (Worst Case)	Space Complexity
//Insertion	O(1) (at the end)	O(n) (beginning/middle)	O(1)
//Deletion	O(1) (at the end)	O(n) (beginning/middle)	O(1)
//Printing	O(n)	O(n)	O(1)
//Searching	O(1) (if the element is at the start)	O(n) (linear), O(log n) (binary)	O(1)

int search(int *arr,int size,int elm)
{
    for (int i = 0; i < size; i++)
    {
     if(arr[i] == elm) return 1;   
    }
    return 0;
}

void printArray(int *arr,int size)
{
    for(int i = 0;i < size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int deleat(int *arr,int size, int position)
{
    if(position < 0 || position >= size)
    {
        printf("POSITION IS OUT OF BOUND CNA NOT DELEAT ELEEMNET : \n");
        return 0;
    }
    for (int i = position; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return --size;
}

int insert(int *arr,int size,int elm, int position)
{
    if(position < 0 || position > size)
    {
        printf("POSITION IS OUT OF BOUND : \n");
        return -1;
    }
    if(position == size+1)
    {
        arr[size + 1] = elm;
        return ++size;
    }
    for(int i = size-1; i >= position; i--)
    {
       arr[i + 1] = arr[i];
    }
    arr[position] = elm;
    return ++size;
}



int main()
{
    int arr[] = {2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    // printf("%d | ",size);
    // int n = insert(arr,size,44,5);
    // printf("%d ",n);

    int n = deleat(arr,size,4);
    
    printArray(arr,n);

}