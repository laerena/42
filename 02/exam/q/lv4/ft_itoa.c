#include <stdlib.h>

int count_len(long n)
{
    int len = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        n = -n;
    while (n > 0)
    {
        //each division add one digit for len
        n = n / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nb)
{
    char *res;
    long n = nb;
    int len = count_len(n);

    if (nb < 0)
        len++; //for '-'
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    res[len] = '\0'; //because index starts at 0!!!
    if (n < 0)
    {
        res[0] = '-';
        n = -n;
    }
    while (len > (nb < 0))//true or false statement, !(nb < 0) = 0
    {
        res[len - 1] = (n % 10) + 48;
        n = n / 10;
        len--;
    }
    return (res);
}