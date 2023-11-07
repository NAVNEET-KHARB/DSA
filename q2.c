#include <stdio.h>
void func(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d,%d\n", i, j);
        }
    }
}
int main()
{
    int a = 4;
    func(a);
}