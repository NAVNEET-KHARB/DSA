#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int indInsertion(int arr[], int size, int capacity, int index, int element)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = (size - 1); i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element, index, capacity = 100;
    display(arr, size);
    printf("Enter the index at which you want to add your element : ");
    scanf("%d", &index);
    printf("Enter the element you want to add at index %d : ", index);
    scanf("%d", &element);
    int ins = indInsertion(arr, size, capacity, index, element);
    if (ins == 1)
    {
        printf("Insertion was successful.\n");
        size += 1;
        display(arr, size);
    }
    else
    {
        printf("Insertion was unsuccessful.");
    }
    return 0;
}