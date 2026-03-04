#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    return (n != 0 && (n & (n - 1)) == 0);
}
/*
int is_power_of_2(unsigned int n)
{
    unsigned int test = 1;
    while (test <= n)
    {
        if (test == n)
            return (1);
        test = test * 2;
    }
    return (0);
}
*/
/*
int main()
{
    printf("%d\n", is_power_of_2(-3));
}
*/