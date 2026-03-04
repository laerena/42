#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i])
        {
            //when it is uppercase
            if (av[1][i] >= 65 && av[1][i] <= 90)
            //eg. 90 - 65(A) = 35, 35 + 65 = 90(Z)
            //eg. 90 - 66(B) = 34, 34 + 65 = 89(Y)
                av[1][i] = 90 - av[1][i] + 65;
            else if (av[1][i] >= 97 && av[1][i] <= 122)
                av[1][i] = 122 - av[1][i] + 97;
            write(1, & av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}