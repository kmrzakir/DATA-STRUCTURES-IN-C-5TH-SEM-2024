#include<stdio.h>
void selection_sort(int *arr,int size);
void bubble_sort(int *arr,int size);
void insertion_sort(int *arr,int size);
void reverse(int *arr,int size);

int main()
{

  int arr[] = {5,8,1,10,12,2,3,8,0};
  reverse(arr,9);

  printf("ARRAY AFTER SORT : ");
  for (int i = 0; i < 9; i++)
  {
    printf("%d ",arr[i]);
  }
  

    return 0;
}


void reverse(int *arr,int size){
    for (int i = 0; i <= size/2; i++)
    {
      int temp = arr[i];
      arr[i] = arr[size-i-1];
      arr[size-i-1] = temp;
    }
    
}


// void insertion_sort(int *arr,int size){
//   for (int i = 1; i < size; i++)
//   {
//     int j  = i;
//     int temp = arr[i];
//     while (j>0 && arr[j] < arr[j-1])
//     {
//       int tt = arr[j];
//       arr[j] = arr[j-1];
//       arr[j-1] = tt;
//       j--;
//     }
//   }
  
// }

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


// void insertion_sort(int *arr,int size){
//   for(int i = 1;i<size;i++){
//     int j = i;
//     while(j>0 && arr[j] < arr[j-1]){
//       int temp = arr[j];
//       arr[j] = arr[j-1];
//       arr[j-1] = temp;
//       j--;
//     }
//   }
// }


// void bubble_sort(int *arr,int size){
//   for (int i = 0; i < size; i++)
//   {
//     for(int j = 0;j<size-i-1;j++){
//       if(arr[j] > arr[j+1]){
//         int temp = arr[j];
//         arr[j] = arr[j+1];
//         arr[j+1] = temp;
//       }
//     }
//   }
  
// }

// void selection_sort(int *arr,int size)
// {
//  for (int i = 0; i < size; i++)
//  {
//   int temp = i;
//   for (int j = i+1; j < size; j++)
//   {
//    if(arr[temp] > arr[j]){
//     temp = j;
//    } 
//   }

//   if(temp != i){
//     int tt = arr[i];
//     arr[i] = arr[temp];
//     arr[temp] = tt;
//   }
  
//  }
  
// }