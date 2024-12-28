// A sparce matrix is a type of matrix which contais large number of zeroes compaired
// to non-zero elements. Eg if we have a matrix of 5 * 5, if most of the elements are zero
// then it is called sparce matrix
// SO we use simple matrix insted of simple matrix because there are less
// non-zero elemnts and needs less space to represent sparce matrix.
// computing of sparce matrix becoms easy.

#include<stdio.h>

void convertToSparce(int arr[4][5],int row,int col)
{
    int non_zero_elements = 0;
    for(int i = 0;i < row;i++)
    {
        for(int j = 0; j < col;j++)
        {
            if(arr[i][j] != 0)
            {
                ++non_zero_elements;
            }
        }
    }
    printf("NUMBER OF NON ZERO ELEMNTS ARE %d : \n",non_zero_elements);

    // this will represent a sparce matrix with column no rwo no and value
    int sparce[non_zero_elements][3];
    int k = 0;
    for(int i = 0; i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            if(arr[i][j] != 0)
            {
                sparce[k][0] = i; // Row number
                sparce[k][1] = j; // Column number
                sparce[k][2] = arr[i][j]; // actual value of cell i * j
                k++;
            }
        }
    }

    // printf sparce matrix
    printf("SPARCE MATRIX IS : \n");
    printf("Row\tColumn\tValue\n");
    for(int i = 0;i < non_zero_elements;i++)
    {
        printf("%d\t%d\t%d\n",sparce[i][0],sparce[i][1],sparce[i][2]);
    }

}

int main()
{
    int arr[4][5];
    printf("ENTER THE 20 ELEMENTS IS AN ARRAY : ");
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            scanf("%d ",&arr[i][j]);
        }
    }
     for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    convertToSparce(arr,4,5);
}