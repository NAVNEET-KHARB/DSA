#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void selectionSortA(int *A, int n)
{
    int index;
    int key;
    for (int i = 0; i < n - 1; i++) // No. of passes
    {
        key = A[i];
        index = i;
        for (int j = i + 1; j < n; j++) // Finding smallest element
        {
            if (key > A[j])
            {
                key = A[j];
                index = j;
            }
        }
        A[index] = A[i];
        A[i] = key;
    }
}
void selectionSortD(int *A, int n)
{
    int index, key;
    for (int i = 0; i < n - 1; i++) // No. of passes
    {
        key = A[i];
        index = i;
        for (int j = i + 1; j < n; j++) // Finding biggest element
        {
            if (A[j] > key)
            {
                key = A[j];
                index = j;
            }
        }
        A[index] = A[i];
        A[i] = key;
    }
}
int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {44, 33, 11, 12, 34, 22};
    int n = 6;
    printArray(A, n);
    selectionSortA(A, n);
    // selectionSortD(A, n);
    printArray(A, n);
    return 0;
}