#include <unistd.h>

/*
void ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    char c = nbr % 10 + '0';
    write (1, &c, 1);
}*/
void ft_putnbr(int i)
{
    if (i > 9)
        ft_putnbr(i / 10);
    write(1, &"0123456789"[i % 10], 1);
}

int main(int ac, char **av)
{
    (void)av;
    ft_putnbr(ac - 1);
    write(1, "\n", 1);
    return (0);
}