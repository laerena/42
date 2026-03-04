#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        unsigned int i = 0;
        //loop through first spaces and tabulations
        while (av[1][i] == 32 || av[1][i] == 9)
            i++;
        //loop and write the word until first space occurs
        while ((av[1][i] != 32 && av[1][i] != 9) && av[1][i])
            write(1, &av[1][i++], 1);
    }
    write(1, "\n", 1); //print newline
    return (0);
}