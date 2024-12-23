// Quick Sort is a popular and efficient sorting algorithm based on the divide-and-conquer strategy. It works by selecting a "pivot" element from the array and partitioning the other elements into two groups:

// Elements smaller than the pivot (placed on the left).
// Elements greater than the pivot (placed on the right).
// The process is then recursively applied to the left and right subarrays until the entire array is sorted.

// Steps in Quick Sort:
// Choose a Pivot: Select an element as the pivot. Common strategies include:

// Picking the first element.
// Picking the last element.
// Picking a random element.
// Picking the median.
// Partitioning: Rearrange the array such that:

// All elements smaller than the pivot are on the left.
// All elements larger than the pivot are on the right.
// Recursion:

// Recursively apply the quick sort on the left and right subarrays.
// Combine: Since the subarrays are sorted in place, no additional merging is needed.

// Time Complexity:
// Best case: 𝑂(𝑛log⁡𝑛) occurs when the pivot divides the array into two equal halves.
// Average case: 𝑂(𝑛log⁡𝑛) happens in most cases.
// Worst case: 𝑂(𝑛2) occurs when the pivot is always the smallest or largest element, resulting in highly unbalanced partitions.
// Space Complexity:𝑂(log⁡𝑛) due to recursive function calls (in-place sorting).


#include<stdio.h>
void displayArr(int *arr,int size);
void quickSort(int *arr,int start,int end);
int partition(int *arr,int start ,int end);
void swap(int *arr,int i,int j);


int main()
{

    int arr[] = {2,6,5,3,8,7,1,0};

    quickSort(arr,0,8-1);

    displayArr(arr,8);

    return 0;
}

void quickSort(int *arr,int start,int end)
{
    if(start >= end) return;
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1); // left side
    quickSort(arr,pivot+1,end); // right side
}


int partition(int *arr,int start ,int end)
{
    int j = start;
    for(int i = start; i <= end;i++) // taking pivot as the end last element of an array
    {
        if(arr[i] <= arr[end])
        {
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
            swap(arr,i,j);
            j++;
        }
    }
    return j-1;
}

void displayArr(int *arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

void swap(int *arr,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}