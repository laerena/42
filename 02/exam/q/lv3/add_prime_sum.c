#include <unistd.h>

void ft_putnbr(int nbr)
{
    unsigned int n;
    if (nbr < 0)
    {
        write(1, "-", 1);
        n = -nbr;
    }
    else
        n = nbr;
    if (nbr > 9)
        ft_putnbr(n / 10);
    write(1, &"0123456789"[n % 10], 1);
}

int is_prime(int nbr)
{
    if (nbr < 2)
        return (0);
    int i = 2;
    while (i <= nbr / 2)
    {
        if (nbr % i == 0)
            return (0);
        i++;
    }
    return (1);
}
int ft_atoi(char *str)
{
    int n = 0;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (-1);
        n = n * 10 + (*str - 48);
        str++;
    }
    return (n);
}
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int n = ft_atoi(av[1]);
        int sum = 0;

        while (n > 1)
        {
            if (is_prime(n))
                sum += n;
            n--;
        }
        ft_putnbr(sum);
        write(1, "\n", 1);
    }
}