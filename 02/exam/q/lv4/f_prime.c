#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i;
    int num;

    i = 2;
    if (ac == 2)
    {
        num = atoi(av[1]);
        if (num == 1)
            printf("1");
        while (i <= num)
        {
            //divde num immediately when possible
            if (num % i == 0)//is it divisible?
            {
                printf("%d", i);
                if (num != i)//not yet equal to this denominator?
                    printf("*");
                num = num / i;
            }
            //only move to the next i if current one does NOT divide num
            else
                i++;
        }
    }
    printf("\n");
    return (0);
}