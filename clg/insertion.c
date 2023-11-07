#include <stdio.h>
int main()
{
    int LA[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int item, k, n = 10;
    int i = 0, j = n;
    printf("Enter the number you want to insert");
    scanf("%d", &item);
    printf("Enter the position(index+1) you want to insert your number at");
    scanf("%d", &k);
    if (k > 0 && k < 11)
    {
        printf("Array elements before insertion\n");
        for (i = 0; i < n; i++)
        {
            printf("LA[%d]%d\n", i, LA[i]);
        }
        n = n + 1;
        while (j >= k)
        {
            LA[j + 1] = LA[j];
            j = j - 1;
        }
        LA[k] = item;
        printf("Array elements after insertion\n");
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