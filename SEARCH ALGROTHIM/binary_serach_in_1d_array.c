#include<stdio.h>
int binarySearch();
int main(){

   int isFound = binarySearch();
   if(isFound != -1)
   {
    printf("ELEMENT FOUND AT INDEX %d ",isFound);
   }else
   {
    printf("ELEMENT IS NOT FOUND ");
   }

    return 0;
}

//THIS METHOD WHILL CHECK FOR THE ELEMENT AND IF FIND'S IT WILL THEN RETURN 1(TRUE) ELSE -1(FALSE)
int binarySearch()
{
    //ASSSUME FOR NOW ARRAY IS SORTED IN AN INCREASING ORDER
    int arr[] = {1,2,3,4,5,6,7,8,9,10},target = 2;
    int size = sizeof(arr)/sizeof(int); 
    int start = 1,end = size;//MOSTLY WE NAME start AS LOW AND end AS HIGH BUT FOR NOW WE WILL USE start AND end
    while (start <= end)//IF start is > end THAT MEANS WE DID'T FIND THE ELEMENT AND WE WILL THEN RETURN -1
    {
        int mid = (start + end)/2;
        if(target == arr[mid])
        {
            return mid;
        }else if (target > arr[mid])
        {
            start = mid + 1;// HERE WE ARE ADDING 1 TO mid BECAUSE WE DON'T NEED TO CHECK FOR mid ALREADY BEEN CHECKED
        }else
        {
            end = mid - 1;// HERE WE ARE SUBTRACTING 1 FORM mid BECAUSE WE DON'T NEED TO CHECK FOR mid ALREADY BEEN CHECKED
        }
        
    }
    return -1;
    
}