#include<stdio.h>
#define MAX 100
int adjencyMatrix[MAX][MAX] = {0};
int vertices,edges;

// undirected graph
void createGraph()
{
    printf("ENTER THE NUMBER VERTICES IN A GRAPH : ");
    scanf("%d",&vertices);
    printf("ENTER THE NUMBER OF EDGES IN A GRAPH : ");
    scanf("%d",&edges);

    printf("ENTER THE %d EDGES FROM SORCE TO DESTINATTION : ");
    for(int i = 0; i<edges;i++)
    {
        int k,j;
        scanf("%d %d",&k,&j);
        if(k < 0 || k >= vertices || j < 0 || j >= vertices)
        {
            printf("INVALID EDGE EDGE CNA BE FROM 0 to %d RE-ENTER EDGE AGAIN : ",vertices);
            i--;
        }
        adjencyMatrix[k][j] = 1;
        adjencyMatrix[j][k] = 1;
    }

}

void displayGraph()
{
    for (int i = 0; i < vertices; i++)
    {
       for (int j = 0; j < vertices; j++)
       {
        printf("%d ",adjencyMatrix[i][j]);
       }
       printf("\n");
    } 
}


int main()
{
    
    createGraph();
    displayGraph();
    return 0;
}