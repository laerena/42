#include <stdio.h>
#include <stdlib.h>

int main(int ac, char ** av)
{
    int n1;
    int n2;

    if (ac == 3)
    {
        n1 = atoi(av[1]);
        n2 = atoi(av[2]);
        int tmp;

        while (n2 != 0)
        {
            //replace the big number by the smaller one
            //replace the smaller one by the remainder
            //stop when remainder is 0
            tmp = n1 % n2;
            n1 = n2;
            n2 = tmp;

            //./pgcd 10 42

            //step 1
            //tmp = 10 % 42 = 10
            //n1 = 42
            //n2 = tmp = 10

            //step 2
            //tmp = 42 % 10 = 2
            //n1 = 10
            //n2 = 2

            //step 3
            //tmp = 10 % 2 = 0
            //n1 = 2
            //n2 = 0

            //pgcd = 2

        }
    }
    printf("%d\n", n1);
    return (0);
}