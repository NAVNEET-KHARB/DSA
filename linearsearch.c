#include <stdio.h>
// int linearsearch(int arr[], int size, int element)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("%d\n", mid);
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    // int arr[100] = {234, 4, 2, 5, 6, 9, 56, 80, 343, 22, 55, 34, 64, 3, 4, 5, 6, 78};
    // int size = sizeof(arr) / sizeof(int);
    // int element;
    // printf("Enter the element you want to search for : ");
    // scanf("%d", &element);
    // int search = linearsearch(arr, size, element);
    // if (search >= 0)
    // {
    //     printf("Element %d found at index %d", element, search);
    // }
    // else
    // {
    //     printf("Element %d wasn't found in the array", element);
    // }
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int element;
    printf("Enter the element you want to search for : ");
    scanf("%d", &element);
    int search = binarySearch(arr, size, element);
    if (search >= 0)
    {
        printf("Element %d found at index %d", element, search);
    }
    else
    {
        printf("Element %d wasn't found in the array", element);
    }

    return 0;
}