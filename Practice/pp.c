#include<stdio.h>
void selection_sort(int *arr,int size);
void bubble_sort(int *arr,int size);
void insertion_sort(int *arr,int size);
void reverse(int *arr,int size);
void selection_sort2(int *arr,int size);
void bubble_sort2(int *arr,int size);
void print_n(int n);

int main()
{

  // int arr[] = {5,8,1,10,12,2,3,8,0};
  // bubble_sort2(arr,9);

  // printf("ARRAY AFTER SORT : ");
  // for (int i = 0; i < 9; i++)
  // {
  //   printf("%d ",arr[i]);
  // }
  printf("FIRST N NUMBERS USING RECURSION ARE : ");
  print_n(12);
  return 0;
}

void print_n(int n)
{
  if(n == 0) return;
  print_n(n-1);
  printf("%d ",n);
}

void insertion_sort(int *arr,int size)
{
  for (int i = 0; i < size-1; i++)
  {
   int j = i+1;
   while (j> 0 && arr[j] < arr[j-1])
   {
    int temp = arr[j];
    arr[j] = arr[j-1];
    arr[j-1] = temp;
    j--;
   }
    
  }
}

void reverse(int *arr,int size){
    for (int i = 0; i <= size/2; i++)
    {
      int temp = arr[i];
      arr[i] = arr[size-i-1];
      arr[size-i-1] = temp;
    }
    
}

void bubble_sort(int *arr,int size){
  for (int i = 0; i < size; i++)
  {
    for (int j = 0;j<size-1-i;j++)
    {
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    
  }  
}

void bubble_sort2(int *arr,int size)
{
  for(int i = 0;i<size;i++)
  {
    for(int j = 0;j<size-1-i;j++)
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

void selection_sort2(int *arr,int size)
{
  for(int i = 0;i<size-1;i++)
  {
    int small = i;
    for(int j = i+1;j<size;j++)
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

void selection_sort(int *arr,int size){
  for (int i = 0; i < size; i++)
  {
    int small = i;
    for(int j = i+1;j<size;j++){
      if(arr[small] > arr[j]){
        small = j;
      }
    }
    if (small != i)
    {
      int temp = arr[small];
      arr[small] = arr[i];
      arr[i] = temp;
    }
    
  }
  
}