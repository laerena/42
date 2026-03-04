#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0, j = 0;

    if (ac == 3)
    {
        //loop over s2
        while (av[2][j] && av[1][i])
        {
            //if current char of s2 = current char of s1
            //advance in s1 by one place
            //and keep going in s2
            if (av[2][j] == av[1][i])
                i++;
            j++;
        }
        if (av[1][i] == 0)
            write (1, "1", 1);
        else
            write (1, "0", 1);
    }
    write(1, "\n", 1);
}