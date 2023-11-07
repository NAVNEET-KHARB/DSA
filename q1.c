#include <stdio.h>
int func1(int arr[], int length)
{
    int sum = 0;
    int product = 1;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < length; i++)
    {
        product *= arr[i];
    }
    printf("%d and %d", sum, product);
    return 0;
}
int main()
{
    int arr[] = {3, 5, 8, 24,33};
    func1(arr, 5);
}