#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void mergeA(int *A, int mid, int low, int high)
{
    int B[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int a = low; a < high + 1; a++)
    {
        A[a] = B[a];
    }
}
void mergeSortA(int *A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortA(A, low, mid);
        mergeSortA(A, mid + 1, high);
        mergeA(A, mid, low, high);
    }
}
void mergeD(int *A, int mid, int low, int high)
{
    int B[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] > A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int a = low; a < high + 1; a++)
    {
        A[a] = B[a];
    }
}
void mergeSortD(int *A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortD(A, low, mid);
        mergeSortD(A, mid + 1, high);
        mergeD(A, mid, low, high);
    }
}
int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    // mergeSortA(A, 0, n - 1);
    mergeSortD(A, 0, n - 1);
    printArray(A, n);
    return 0;
}