#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int j;

    //check number of arguments
    if (ac == 2)
    {
        i = 0;
        //loop over the string
        while (av[1][i])
        {
            //if uppercase
            if (av[1][i] >= 65 && av[1][i] <= 90)
            {
                j = 0;
                //loop to get the index
                while (j < av[1][i] - 64)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else if (av[1][i] >= 97 && av[1][i] <= 122)
            {
                j = 0;
                while (j < av[1][i] - 96)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else//if not a letter simply write the character
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}