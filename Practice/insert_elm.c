#include<stdio.h>
int deleat_at(int *arr,int position,int size);
void print_array(int *arr,int size);
int insert_at(int *arr,int position,int size,int elm);

int main()
{
 int arr[] = {1,2,3,4,5,6,7,8,9,10};
 int size = sizeof(arr)/sizeof(arr[0]);
 printf("SIZE OF AN ARRAY IS : %d \n",size);
//  printf("ARRAY BEFORE DELEATING AN ELEMENT : ");
//  print_array(arr,size);
//  int newSize = deleat_at(arr,3,size);
//  printf("ARRAY AFTER DELEATING AN ELEMENT : ");
//  print_array(arr,newSize);
printf("ARRAY BEFORE INSERTING AN ELEMENT : \n");
print_array(arr,size);
int newSize = insert_at(arr,4,size,88);
printf("ARRAY AFTER INSERTING AN ELEMENT : \n");
print_array(arr,newSize);
}

int insert_at(int *arr,int position,int size,int elm)
{
    if(position >= size || position < 0)
    {
        printf("INVALID POSITION FOR DELATING AN ELEMENT : \n");
        return -1;
    }
    for (int i = size; i >= position; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[position] = elm;
    return size+1;
}

int deleat_at(int *arr,int position,int size)
{
    if(position>= size || position < 0)
    {
        printf("INVALIT POSITION : ");
        return -1;
    }
    for (int i = position; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    return size-1;
}

void print_array(int *arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}