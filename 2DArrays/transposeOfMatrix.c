#include<stdio.h>
//WRITE A PROGRAM TO FIND THE TRANSPOSE OF A MATRIX
int main(){
  int cols=0,row=0;
  printf("ENTER THE NUMBER OF ROWS OF A MATRIX : \n");
  scanf("%d",&row);
  printf("ENTER THE NUMBER OF COLMNS OF A MATRIX : \n");
  scanf("%d",&cols);
  int arr[row][cols],transposeMatrix[cols][row];

  printf("ENTER %d ELEMENTS IN MATRIX : \n",row*cols);
  for(int i = 0;i<row;i++)
  {
    for(int j = 0;j<cols;j++)
    {
        scanf("%d",&arr[i][j]);
    }
  }
  //PRINT ENTERED ARRAY
   printf("THE ARRAY IS : \n");
  for(int i = 0;i<row;i++)
  {
    for(int j = 0;j<cols;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  //TRANSPOSE OF MATRIX
  for(int i = 0;i<row;i++)
  {
    for(int j = 0;j<cols;j++)
    {
        transposeMatrix[j][i] = arr[i][j];
    }
  }
  //PRINT TRANSPOSE MATRIX
  printf("TRANSPOSE MATRIX IS : \n");
  for(int i = 0;i<cols;i++)
  {
    for(int j = 0;j<row;j++)
    {
        printf("%d ",transposeMatrix[i][j]);
    }
    printf("\n");
  }
    return 0;
}



