#include<stdio.h>
#define MAX 100
void insertion_sort(int *arr, int size);

// best case = O(n)
//  worst case and average case is O(n power 2)

int main()
{

int arr[MAX];
int n;
printf("ENTER THE SIZE OF AN ARRAY : ");
scanf("%d",&n);
printf("ENTER THE %d ELEEMNTS IN AN ARRAY : \n");
for (int i = 0; i < n; i++)
{
   scanf("%d",&arr[i]);
}
printf("\n");
// BEFORE INSERTION SORT
printf("ARRAY BEFORE SORT : ");
for (int i = 0; i < n; i++)
{
   printf("%d ",arr[i]);
}
printf("\n");

insertion_sort(arr,n);

// AFTER INSERTION SORT
printf("ARRAY AFTER SORT : ");
for (int i = 0; i < n; i++)
{
   printf("%d ",arr[i]);
}

}

void insertion_sort(int *arr,int size)
{
    for(int i = 1;i<size;i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
           int temp = arr[j];
           arr[j] = arr[j-1];
           arr[j-1] = temp;
           j--;
        }
        
    }
}


    


