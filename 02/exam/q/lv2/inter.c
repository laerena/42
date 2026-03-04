#include <unistd.h>

/*int main(int ac, char **av)
{
    int found;

    if (ac == 3)
    {
        int i = 0;
        while (av[1][i])
        {
            int j = 0;
            found = 0;
            while (av[2][j])
            {
                //check if av[1][i] exist in av[2]
                if (av[1][i] == av[2][j])
                {
                    found = 1;
                    break;
                }
                j++;
            }
            if (found)
            {
                //check if av[1][i] appeared before
                int k = 0;
                while (k < i)
                {
                    if (av[1][k] == av[1][i])
                        break;
                    k++;
                }
                //if k reached i, it means it's the first occurence
                if (k == i)
                    write(1, &av[1][i], 1);
            } 
            i++; 
        }
    }
    write(1, "\n", 1);
    return (0);
}*/
int main(int ac, char **av)
{
    int i = 0;
    int j;
    int mu[256] = {0};

    if (ac == 3)
    {
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[1][i] == av[2][j] && !mu[av[2][j]])
                {
                    mu[av[2][j]] = 1;
                    write(1, &av[2][j], 1);
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}