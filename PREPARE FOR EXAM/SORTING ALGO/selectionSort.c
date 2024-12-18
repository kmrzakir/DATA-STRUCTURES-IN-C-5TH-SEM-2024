// Selection sort is a simple sorting algorithm that works by repeatedly selecting the smallest (or largest, depending on the order) element from an unsorted part of the list and swapping it with the first element of the unsorted part. It divides the list into two parts: the sorted part and the unsorted part.

// Here’s how it works:

// Steps of Selection Sort:
// Start with the first element:

// Assume it is the smallest (for ascending order sorting).
// Find the smallest element:

// Compare this element with every other element in the unsorted part of the array to find the smallest.
// Swap:

// Swap the smallest element found with the first element of the unsorted part.
// Move to the next position:

// Treat the first element as sorted and repeat the process for the remaining unsorted elements.
// Repeat until the array is sorted:

// The process continues until the entire array is sorted.
// Characteristics:
// Time complexity: Best, Worst, and Average: 𝑂(𝑛2), where n is the number of elements.
// Space complexity:𝑂(1) (In-place sorting, no extra space required).

#include<stdio.h>
void selectionSort(int *arr,int size);

int main()
{

    int arr[] = {3,5,2,10,6,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    printf("ARRAY AFTER SORT IS : ");
    for (int i = 0; i < size; i++)
    {
       printf("%d ",arr[i]);
    }
    
    return 0;
}

void selectionSort(int *arr,int size)
{
    for(int i = 0;i<size-1;i++)
    {
        int small = i;
        for (int j = i+1; j < size; j++)
        {
           if(arr[small] > arr[j])
           {
            small = j;
           }
        }
        if(small != i)
        {
            int temp = arr[small];
            arr[small] = arr[i];
            arr[i] = temp;
        }
    }
}