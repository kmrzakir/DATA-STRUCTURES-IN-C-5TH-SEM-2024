#include<stdio.h>
#define MAX 100
int adjencyList[MAX][MAX];
int vertices,edges;

void cretaeMatrix()
{
    printf("ENTER THE NUMBER OF VERTICES : \n");
    scanf("%d",&vertices);

    printf("ENTER THE NUMBER OF EDGES : \n");
    scanf("%d",&edges);

    for(int i = 0; i < edges; i++)
    {
        printf("ENTER %d THE SRC AND DEST VERTEX : \n",i+1);
        int src,dest;
        scanf("%d%d",&src,&dest);
        adjencyList[src][dest] = 1;
        adjencyList[dest][src] = 1;
    }
}

void display()
{
    for (int i = 0; i < vertices; i++)
    {
        for(int j = 0;j < vertices;j++)
        {
            printf("%d ",adjencyList[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{

    cretaeMatrix();
    display();
    return 0;
}
