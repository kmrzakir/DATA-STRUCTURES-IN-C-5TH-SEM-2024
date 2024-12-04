#include<stdio.h>

#define MAX 100
int binarySearch(int *arr,int length,int elm);
int binaryRec(int *arr,int elm,int front,int end);


int main()
{

    int arr[MAX];
    int n = 0;
    printf("ENTER TEH SIZE OF AN ARRAY : ");
    scanf("%d",&n);

    printf("ENTER %d ELEEMNTS : ",n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("THE ELEEMNTS OF AN ARRAY ARE : ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("ENTER THE ELEEMNT WHICH YOU WANT TO FIND : ");
    int elm;
    scanf("%d",&elm);
   int bool =  binaryRec(arr,elm,0,n-1);

   if(bool == -1){
    printf("ELEEMNT IS NOT PRESENT IN AN ARRAY : ");
   }else{
    printf("ELEEMNT IS PRESENT IN AN ARRAY : ");
   }
}

int binarySearch(int *arr,int length,int elm){

 int front = 0,end = length;

    while (front <= end)
    {
        int mid = front + (end - front)/2;
        if(arr[mid] == elm){
            return elm;
        }else if (arr[mid] < elm)
        {
            front = mid + 1;
        }else if (arr[mid] > elm)
        {
            end = mid - 1;
        } 
    }
    return -1; 
    
}

int binaryRec(int *arr,int elm,int front,int end){
    while (front <= end)
    {
       int mid = front + (end - front) / 2;
       if(arr[mid] == elm){
        return elm;
       }else if (arr[mid] < elm)
       {
        return binaryRec(arr,elm,mid+1,end);
       }
       else if (arr[mid] > elm)
       {
        return binaryRec(arr,elm,front,mid-1);
       }
       
       
    }
    return -1;
    
}