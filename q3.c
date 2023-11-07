#include <stdio.h>
#include <stdlib.h>
int random(int a)
{
    int num = (rand() % (a + 1));
    printf("%d", num);
    return num;
}
int funct(int n)
{
    int i;
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        i = random(n - 1);
        printf("this\n");
        return funct(i) + funct(n - 1 - i);
    }
}
int main()
{
    funct(6);
    return 0;
}