#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void countSortA(int *A, int n)
{
    int size = maximum(A, n);                             // finding max element in unsorted array
    int *count = (int *)malloc((size + 1) * sizeof(int)); // declaring auxillary array
    // Initializing auxillary array
    for (int i = 0; i <= size; i++)
    {
        count[i] = 0;
    }
    // marking all elements from unsorted array in auxillary array
    for (int i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    int i = 0; // pointer for auxillary array
    int j = 0; // pointer for turning unsorted array into sorted one
    while (i <= size)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}
void countSortD(int *A, int n)
{
    int size = maximum(A, n);                             // finding max element in unsorted array
    int *count = (int *)malloc((size + 1) * sizeof(int)); // declaring auxillary array
    // Initializing auxillary array
    for (int i = 0; i <= size; i++)
    {
        count[i] = 0;
    }
    // marking all elements from unsorted array in auxillary array
    for (int i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    int i = size; // pointer for auxillary array
    int j = 0;    // pointer for turning unsorted array into sorted one
    while (i >= 0)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i--;
        }
    }
}
int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    // countSortA(A, n);
    countSortD(A, n);
    printArray(A, n);
    return 0;
}