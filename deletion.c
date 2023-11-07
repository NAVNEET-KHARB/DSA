#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int deletion(int arr[], int size, int index)
{
    if (index >= size)
    {
        return -1;
    }
    for (int i = index; i < (size - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}
int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7, index;
    display(arr, size);
    printf("Enter the index you want to delete element for : ");
    scanf("%d", &index);
    int a = deletion(arr, size, index);
    if (a == 1)
    {
        size -= 1;
        display(arr, size);
    }
    else
    {
        printf("Item wasn't deleted");
    }
    return 0;
}