#include<stdio.h>
int main(){
int cols=0;
printf("ENTER THE NUMBER OF COLUMNS OF A SQUARE MATRIX : \n");
scanf("%d",&cols);
int arr[cols][cols];
//ENTER THE ELEMENTS IN A SQUARE MATRIX
printf("ENTER %d NUMBERS IN 2 D ARRAY : \n",cols*cols);
for(int i=0;i<cols;i++)
{
    for(int j=0;j<cols;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}
//PRINT ARRAY
printf("ENTER 2 D ARRAY IS : \n");
for(int i=0;i<cols;i++)
{
    for(int j=0;j<cols;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}

//CONVERTING 2 D ARRAY INTO LOWER MATRIX
for(int i=0;i<=cols-2;i++)
{
    for(int j=i+1;j<cols;j++)
    {
        arr[i][j] = 0;
    }
}
//PRINT LOWER MATRIX HERE
perror("THET LOWER MATRIX : \n");
for(int i=0;i<cols;i++)
{
    for(int j=0;j<cols;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}


    return 0;
}