#include <stdio.h>
//write a program to find the multiplication of two matrix
int main(){

      int commonDim=0,r1=0,c2;
     int temp=0,size=3;

     printf("ENTER THE NUMBER OF ROSE AND COLUMNS OF FIRST MATRIX : \n");
     scanf("%d%d",&r1,&commonDim);
     printf("ENTER THE NUMBER OF COLUMNS OF SECOND MATRIX : \n");
     scanf("%d",&c2);

     int a1[r1][commonDim],a2[commonDim][c2],r[r1][c2];

     printf("ENTER THE ELEMENTS IN FIRST MATRIX : \n");
       for(int i = 0;i<r1;i++)
      {
        for(int j = 0;j<commonDim;j++)
        {
            scanf("%d",&a1[i][j]);
        }
      }

     printf("ENTER THE ELEMENTS IN SECOND MATRIX : \n");
       for(int i = 0;i<commonDim;i++)
      {
        for(int j = 0;j<c2;j++)
        {
            scanf("%d",&a2[i][j]);
        }
      }
  
    printf("FIRST MATRIX IS : \n");
     
       for(int i = 0;i<r1;i++)
      {
        for(int j = 0;j<commonDim;j++)
        {
            printf("%d ",a1[i][j]);
        }
        printf("\n");
      }


       printf("SECOND MATRIX IS : \n");
     
       for(int i = 0;i<commonDim;i++)
      {
        for(int j = 0;j<c2;j++)
        {
            printf("%d ",a2[i][j]);
        }
        printf("\n");
      }

      for(int i = 0;i<r1;i++)
      {
        for(int j = 0;j<c2;j++)
        {
            for(int k = 0;k<commonDim;k++)
            {
                temp += a1[i][k] * a2[k][j];
            }
            r[i][j] = temp;
            temp = 0;
        }
      }

      printf("THE MULTIPLICATIOF OF TWO MATRIX IS : \n");
      for(int i = 0;i<r1;i++)
      {
        for(int j = 0;j<c2;j++)
        {
            printf("%d ",r[i][j]);
        }
        printf("\n");
      }

    return 0;
}