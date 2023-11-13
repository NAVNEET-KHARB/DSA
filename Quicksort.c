#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int partitionA(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSortA(int *A, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partitionA(A, low, high);
        quickSortA(A, low, partitionIndex - 1);
        quickSortA(A, partitionIndex + 1, high);
    }
}
int partitionD(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] > pivot)
        {
            i++;
        }
        while (A[j] <= pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSortD(int *A, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partitionD(A, low, high);
        quickSortD(A, low, partitionIndex - 1);
        quickSortD(A, partitionIndex + 1, high);
    }
}
int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    // quickSortA(A, 0, n - 1);
    quickSortD(A, 0, n - 1);
    printArray(A, n);
    return 0;
}