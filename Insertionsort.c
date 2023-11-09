#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void insertionSortA(int *A, int n)
{
    int key, j;
    for (int i = 1; i < n; i++) // For insertion of ith element of the array
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) // For comparing with already sorted array
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
void insertionSortD(int *A, int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] < key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    // insertionSortA(A, n);
    insertionSortD(A, n);
    printArray(A, n);
    return 0;
}