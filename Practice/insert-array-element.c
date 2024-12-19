#include<stdio.h>
#define MAX 100
int insertAt(int *arr,int elm,int size,int position);

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

    // print array before inserting an element
    printf("ARRAY BEFORE INSERTING AN ELEMENT : ");
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
   
    // call insert element function
    int elm = 10;
    int positin = 1;
   int newLength = insertAt(arr,elm,n,positin);

   printf("\n");

    // printf function after insert an aeleemnt
     printf("ARRAY AFTER INSERTING AN ELEMET IS : ");
    for(int i = 0;i<newLength;i++){
        printf("%d ",arr[i]);
    }
 

    return 0;
}

int insertAt(int *arr,int elm,int size,int position)
{
    if(position > size)
    {
        printf("POSITION IS OUT OF BOUND : \n");
        return -1;
    }

    int temp;
    for (int i = size; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = elm;
    return size + 1;
}
