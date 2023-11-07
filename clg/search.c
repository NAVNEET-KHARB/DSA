#include <stdio.h>
int main()
{
    // int arr[] = {1, 2, 3, 6, 5, 4, 7, 8, 9, 4, 3, 3, 1, 8, 5, 3, 2};
    int arr[100] = {};
    int search, c, count = 0;
    printf("Enter the no. of elements in array : ");
    scanf("%d", &c);
    printf("Enter %d elements", c);
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search : ");
    scanf("%d", &search);
    for (int i = 0; i < c; i++)
    {
        if (arr[i] == search)
        {
            count++;
            printf("%d found at index %d\n", search, i);
        }
    }
    if (count > 0)
    {
        printf("The element %d is found %d times.", search, count);
    }
    else
    {
        printf("The element %d is not found", search);
    }
}