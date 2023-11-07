#include <stdio.h>
int main()
{
    int LA[] = {1, 3, 5, 7, 8};
    int k, n = 5;
    printf("Enter the index you want to delete");
    scanf("%d", &k);
    if (k < 6 && k > 0)
    {
        int i, j;
        printf("Array elements before deletion\n");
        for (i = 0; i < n; i++)
        {
            printf("LA[%d]%d\n", i, LA[i]);
        }
        j = k;
        while (j < n)
        {
            LA[j - 1] = LA[j];
            // j = j + 1;
            j++;
        }
        n = n - 1;
        printf("Array elements after deletion\n");
        for (i = 0; i < n; i++)
        {
            printf("LA[%d]%d\n", i, LA[i]);
        }
    }
    else
    {
        printf("Enter a valid index");
    }
    return 0;
}