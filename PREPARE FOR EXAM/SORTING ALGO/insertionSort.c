// Insertion Sort is a simple and intuitive sorting algorithm used to arrange elements of an array or list in a particular order (ascending or descending). It works similarly to how people sort playing cards in their hands: by gradually building a sorted section of cards (or elements) and inserting new cards (or elements) into their correct position.

// How it works:
// Start with the second element in the array (since the first element is already "sorted").
// Compare this element with the elements in the "sorted" part of the array (elements before it).
// Shift the elements of the sorted part that are greater than the current element to the right, creating space for the current element.
// Insert the current element into its correct position in the sorted part.
// Repeat this process for all elements in the array.
// Time Complexity:
// Best case: 𝑂(𝑛) — When the array is already sorted.
// Worst case: O(n 2 ) — When the array is sorted in reverse order.
// Average case: O(n 2 )
// Space Complexity:O(1) — Insertion Sort is an in-place algorithm, meaning it requires only a small constant amount of extra memory.
// Advantages:
// Simple and easy to implement.
// Works well for small datasets.
// Efficient for nearly sorted data.
// Disadvantages:
// Inefficient for large datasets due to its O(n 2 ) time complexity.

#include<stdio.h>
void insertionSOrt(int *arr,int size);

int main()
{
    int arr[] = {2,3,1,8,5,10,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSOrt(arr,size);
    printf("ARRAY AFTER SOER IS : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}

void insertionSOrt(int *arr,int size)
{
    for(int i = 0;i<size-1;i++)
    {
        int j = i+1;
        while (j > 0 && arr[j] < arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        
    }
}