#include<stdio.h>
#define MAX 100

// TIME COMPLEXITY
// BEST CASE : O(n)
// WORST CASE : O(n POWER 2)
// AVERAGE CASE : O(n power 2)
// SPACE COMPLEXITY : O(1)

void bobble_sort(int *arr, int size);

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
// BEFORE BUBLE SORT
printf("ARRAY BEFORE SORT : ");
for (int i = 0; i < n; i++)
{
   printf("%d ",arr[i]);
}
printf("\n");

bobble_sort(arr,n);

// AFTER BUBLE SORT
printf("ARRAY AFTER SORT : ");
for (int i = 0; i < n; i++)
{
   printf("%d ",arr[i]);
}

}

void bobble_sort(int *arr, int size)
{
    for(int i = 0;i<size;i++)
    {
        for (int j = 0; j < size - i -1; j++)
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