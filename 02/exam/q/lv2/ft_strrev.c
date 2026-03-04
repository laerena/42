#include <stdio.h>

char *ft_strrev(char *str)
{
    int i = 0;
    int len = 0;
    char tmp;

    while (str[len])
        len++;
    while (i < len - 1)
    {
        //swap
        tmp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = tmp;
        i++;
        len--;
    }
    return (str);
}