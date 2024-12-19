// Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted. The name "bubble sort" comes from the way larger elements "bubble up" to the top of the list with each pass.

// How it works:
// Start at the beginning of the list.
// Compare the first element with the next one.
// If the first element is greater than the next one, swap them.
// Otherwise, leave them as they are.
// Move to the next pair of adjacent elements and repeat the comparison and swap if necessary.
// Continue this process for all pairs in the list.
// After one pass, the largest element will be at the end of the list.
// Repeat the process for the remaining unsorted elements until the entire list is sorted.
// Steps for an example:
// Given: [5, 3, 8, 6]

// Pass 1:

// Compare 5 and 3 → Swap → [3, 5, 8, 6]
// Compare 5 and 8 → No swap → [3, 5, 8, 6]
// Compare 8 and 6 → Swap → [3, 5, 6, 8]
// Pass 2:

// Compare 3 and 5 → No swap → [3, 5, 6, 8]
// Compare 5 and 6 → No swap → [3, 5, 6, 8]
// Compare 6 and 8 → No swap → [3, 5, 6, 8]
// Pass 3:

// Compare 3 and 5 → No swap → [3, 5, 6, 8]
// Compare 5 and 6 → No swap → [3, 5, 6, 8]
// Sorted list: [3, 5, 6, 8]

// Key Points:
// The algorithm stops early if no swaps are made in a pass, as the list is already sorted.
// After each pass, the largest unsorted element is placed in its correct position.
// Time Complexity:
// Best case: O(n) — When the list is already sorted (optimized with early stopping).
// Worst case: O(n 2 ) — When the list is sorted in reverse order.
// Average case:O(n 2 ).
// Space Complexity:𝑂(1) It is an in-place algorithm (no extra space required for sorting).
// Advantages:
// Simple to understand and implement.
// Works well for small datasets or lists that are nearly sorted.
// Disadvantages:
// Inefficient for large datasets due to its O(n 2 ) time complexity.


#include<stdio.h>
void bubbleSort(int *arr,int size);

int main()
{
    int arr[] = {4,2,1,10,6,7,99};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,size);

    printf("ARRAY AFTER SORT IS : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}
void bubbleSort(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}