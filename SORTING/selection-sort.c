#include<stdio.h>
void selectionSort(int *arr,int length);

// TIME COMPLEXITY
// bset case (already sorted) : O(n power 2)
//Worst Case (Reverse sorted) : O(n power 2)
// Average Case :  O(n power 2)

// QUICK SOR TIME COMPLEXITY 
// best case O(nlogn)
// worst case O(n power 2)
// average case O(nlogn)

int main()
{
    
    int arr[] = {2,3,1,4,5,6,10,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("THE SIZE OF AN ARRAY IS %d : \n",size);

    // array before sort
    printf("ARRAY BEFORE SORT : ");
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    // call secection sort algo
    selectionSort(arr,size);

        // array after sort
    printf("ARRAY AFTER SORT : ");
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}

void selectionSort(int *arr,int length)
{

 int k = -1;

 for(int i = 0;i<length-1;i++)
 {
    for(int j = i+1;j<length;j++)
    {
        if(arr[j] < arr[i])
        {
            k = j;
        }
    }
  if(k != -1)
  {
      int temp = arr[k];
    arr[k] = arr[i];
    arr[i] = temp;
    k = -1;
  }
 }

}