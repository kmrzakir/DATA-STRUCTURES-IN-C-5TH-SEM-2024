#include<stdio.h>
int main(){
int cols;
printf("ENTER THE NO OF COLLOMNS OF 2 D ARRAY [SQUARE MATRIX] : ");
scanf("%d",&cols);
int arr[cols][cols];

//ENTER ELEEMNTS IN AN ARRAY
printf("ENTER %d ELEMENTS IN AN ARRAY : \n",cols*cols);
for (int i = 0; i < cols; i++)
{
   for(int j=0;j<cols;j++){
    scanf("%d",&arr[i][j]);
   }
}

//PRINT ARRAY
printf("THE SQUARE MATRIX IS : \n");
for (int i = 0; i < cols; i++)
{
   for(int j=0;j<cols;j++){
    printf("%d ",arr[i][j]);
   }
   printf("\n");
}

//CONVERTING 2 D ARRAY INTO UPPER MATRIX
for(int i=0;i<=cols-2;i++){
    for(int j=i+1;j<cols;j++){
      arr[j][i] = 0;
    }
}
   
//PRINT UPPER TRANGULAR MATRIX HERE
printf("THE UPPER TRANGULAR MATRIX IS : \n");
for (int i = 0; i < cols; i++)
{
   for(int j=0;j<cols;j++){
    printf("%d ",arr[i][j]);
   }
   printf("\n");
}
    return 0;
}