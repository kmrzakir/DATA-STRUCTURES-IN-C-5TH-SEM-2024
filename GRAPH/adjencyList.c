#include<stdio.h>

// this will represent the vertext of a graph
struct vertex
{
    int data;
    struct vertex *next;
};

// this will represent the vertext list
struct adjencyList
{
    struct vertex *head;
};

// this will represent the grapg
struct Graph
{
    int v; // the number of vertices
    struct adjencyList array; //  this will represent the vertex list
};


int main()
{


    return 0;
}