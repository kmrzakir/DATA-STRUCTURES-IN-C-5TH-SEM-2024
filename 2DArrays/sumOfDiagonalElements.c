#include<stdio.h>
//write a program to find the sum of diagonal eleemnts of an array both principle as well as other dialonal
// int sumOfPrincipleDiagonalElements(int arr[],int cols);
// int sumOfAnotherDiagonalElements(int arr[],int cols);
// //int** createArray(int cols);
// void printTheArray(int arr,int cols);

int main(){
   int cols=0,sumOfLeftDiagonalElements=0,sumOfRightDiagonalElements=0;
   printf("ENTER THE NO OF COLOMNS OF AN ARRAY AND SAME WILL BE THE NUMBER OF ROWS : \n");
   scanf("%d",&cols);
   int arr[cols][cols];
   printf("ENTER THE %d ELEMENTS IN AN ARRAY : \n",cols*cols);
     for(int i=0;i<cols;i++){
    for(int j=00;j<cols;j++){
        scanf("%d",&arr[i][j]);
    }
   }
   printf("ENTERED ARRAY IS : \n");
   for(int i=0;i<cols;i++){
    for(int j=0;j<cols;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}

//SUM OF PRINCIPLE/LEFT DIAGONAL ELEEMNTS OF ARRAY
for(int i=0;i<cols;i++){
    sumOfLeftDiagonalElements = sumOfLeftDiagonalElements + arr[i][i];
}
printf("THE SUM OF LEFT DIAGONAL ELEMENTS IS %d : \n",sumOfLeftDiagonalElements);

//SUM OF PRINCIPLE/RIGHT DIAGONAL ELEEMNTS OF ARRAY

for(int i=0,j=cols-1;i<cols;i++,j--){
 sumOfRightDiagonalElements = sumOfRightDiagonalElements + arr[i][j];
}
printf("THE SUM OF RIGHT DIAGONAL ELEMENTS IS %d : \n",sumOfRightDiagonalElements);


   //int *arr = createArray(cols);
//    printTheArray(arr);
//    int sum1 = sumOfPrincipleDiagonalElements(arr,cols);
//    int sum2 = sumOfAnotherDiagonalElements(arr,cols);

    return 0;
}
//creating array here and then returning
// int** createArray(int cols){
//    int arr[cols][cols];

//    for(int i=0;i<cols;i++){
//     for(int j=00;j<cols;j++){
//         scanf("%d",&arr[i][j]);
//     }
//    }
//     return arr;
// }
//this function will print an array
// void printTheArray(int arr[]){
// for(int i=0;i<cols;i++){
//     for(int j=0;j<cols;j++){
//         printf("%d ",arr[i][j]);
//     }
//     printf("\n");
// }
// }
//this function will return the sum of right diagonal
// int sumOfAnotherDiagonalElements(int arr[],int cols){
    

            
//     return 0;
// }
// //this function will return the sum of left/principle diagonal
// int sumOfPrincipleDiagonalElements(int arr[],int cols){


//     return 0;
// }