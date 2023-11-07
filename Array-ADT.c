#include <stdio.h>
int main()
{
    struct myArray
    {
        int total_size;
        int used_size;
    };
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
}