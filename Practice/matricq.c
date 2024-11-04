#include <stdio.h>
#include <stdlib.h>

int checkSymetric(int *R, int n);
int checkReflexive(int *R, int n);
void printRelationalMatrx(int *R, int n);
int* createRelation(int *A, int n);

int main()
{

    int n;

    printf("Enter the  size of set A : ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements in set A : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // This fun will create a relation R
    int *R = createRelation(A, n);

    // Print relational matrix
    printRelationalMatrx(R,n);

    // This fun will check for reflexivity
    int isReflexive = checkReflexive(R,n);

    if(isReflexive){
        printf("Relation R is reflexive : \n");
    }else{
        printf("Relation R is not reflexive : \n");
    }

    // This fun will check is R symetric or not
    int isSymetric = checkSymetric(R,n);

    if(isSymetric){
        printf("Relation R is symetric : \n");
    }else{
        printf("Relation R is asymetric : \n");
    }

    // variable R will store the relation in the form of 1's and 0's
    // int *R = (int *)malloc(n * n * sizeof(int));
    // int k = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("is ( %d , %d) in a relation if yes then enter 1 else 0 : ", A[i], A[j]);
    //         int v;
    //         scanf("%d", &v);
    //         R[k++] = v;
    //     }
    // }

    // Print Relational matrix
    // for (int i = 0; i < n * n; i++)
    // {
    //     printf("%d ", R[i]);
    //     if ((i + 1) % n == 0)
    //     {
    //         printf("\n");
    //     }
    // }

    // int flag = 1;
    // // Check for reflecive
    // for (int i = 0; i < n * n; i = i + n + 1)
    // {
    //     if (R[i] == 0)
    //     {
    //         printf("Relation R is not reflecive : \n");
    //         flag = -1;
    //         break;
    //     }
    // }
    // if (flag == 1)
    // {
    //     printf("Relation R is reflecive : \n");
    // }

    // int flag2 = 1;
    // // check for symetric
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (R[j * n + i] != R[i * n + j])
    //         {
    //             printf("Relation R is asymmetric  : \n");
    //             flag2 = 0;
    //             break;
    //         }
    //     }
    //     if (flag2 == 0)
    //         break;
    // }
    // if (flag2 == 1)
    // {
    //     printf("relation R is symetric : \n");
    // }

    return 0;
}

int* createRelation(int *A, int n)
{
    int *R = (int *)malloc(n * n * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("is ( %d , %d) in a relation if yes then enter 1 else 0 : ", A[i], A[j]);
            int v;
            scanf("%d", &v);
            R[k++] = v;
        }
    }
    return R;
}

void printRelationalMatrx(int *R, int n){
    for (int i = 0; i < n * n; i++)
    {
        printf("%d ", R[i]);
        if ((i + 1) % n == 0)
        {
            printf("\n");
        }
    }
}

int checkReflexive(int *R, int n){
    for (int i = 0; i < n * n; i = i + n + 1)
    {
        if (R[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

int checkSymetric(int *R, int n){
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (R[j * n + i] != R[i * n + j])
            {
               return 0;
            }
        }
    }
    return 1;
}