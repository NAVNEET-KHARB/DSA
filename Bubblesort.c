#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// Non-Adaptive
// void bubblesort(int *A, int n)
// {
//     int temp;
//     for (int i = 0; i < n - 1; i++) // no. of passes
//     {
//         for (int j = 0; j < n - i - 1; j++) // no.of comparisons
//         {
//             if (A[j] > A[j + 1])
//             {
//                 temp = A[j];
//                 A[j] = A[j + 1];
//                 A[j + 1] = temp;
//             }
//         }
//     }
// }
// Adaptive
void bubblesort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // no. of passes
    {
        printf("Pass %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++) // no.of comparisons
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}
int main()
{
    // int a[] = {12, 54, 65, 7, 23, 9};
    int a[] = {11, 22, 33, 44, 55, 66};
    int n = 6;
    printArray(a, n);
    bubblesort(a, n);
    printArray(a, n);
    return 0;
}