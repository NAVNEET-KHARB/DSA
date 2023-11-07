#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    if (n == 1)
    {
        printf("It is neither a prime nor non prime");
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("It isn't a prime number");
            return 0;
        }
    }
    printf("It is a prime no.");
    return 1;
}
int main()
{
    isPrime(4);
}