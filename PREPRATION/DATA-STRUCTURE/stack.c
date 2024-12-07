#include<stdio.h>
#define MAX 100
int isEmpty();
int isFull();
void push(int data);
int pop();
void display();


int stack[MAX];
int top = -1;

int main()
{
    push(20);
    push(40);
    push(60);
    push(80);
    push(100);

    display();
}

void push(int data)
{
if(isFull())
{
    printf("STACK IS FULL CNA NOT PUSH : \n");
    return;
}
top++;
stack[top] = data;
}

int pop()
{
    if(isEmpty())
    {
        printf("STACK IS EMPTY CAN NOT POP : \n");
        return -1;
    }
    int popElm= stack[top];
    top--;
    return popElm;
}

void display()
{
if(isEmpty())
{
    printf("STACK IS EMPTY CNA NOT DISPLAY : ");
    return;
}
int temp = top;
printf("STACK ELEMENTS ARE : ");
for(int i = 0;i<=top;i++)
{
printf("%d ",stack[i]);
}
}

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX-1;
}

// =========================

#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    // Traverse the array
    for (i = 0; i < n - 1; i++) {
        minIndex = i; // Assume the first element is the smallest
        // Find the index of the smallest element in the unsorted portion
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;}}
        // Swap the smallest element with the first element of the unsorted portion
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;}}}
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);}
    selectionSort(arr, n);
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);}
    return 0;}
    // OUTPUT ===============
//     Enter the number of elements: 5
// Enter the elements:
// 29 10 14 37 13
// Sorted array in ascending order:
// 10 13 14 29 37
