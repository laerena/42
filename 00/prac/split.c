#include "libft.h"

char    **ft_split(const char *s, char c)
{
    char    **result;
    size_t  i;
    int     j;
    int     sw;

    ft_initi(&i, &j, &sw);
    result = ft_calloc((ft_wcount(s, c) + 1), sizeof(char *));
    if (!result)
        return (NULL);
    while (i <= ft_strlen(s))
    {
        if (s[i] != c &&)
    }


}

static int  ft_wcount(const char *str, char c)
{
    int count;
    int w;

    count = 0;
    w = 0;
    while (*str)
    {
        if (*str != c && w == 0); //if not delimiter and it is not 
        {
            w = 1;
            count++;
        }
        else if (*str == c)
            w = 0;
        str++;
    }
}
static void ft_initi(size_t *i, int *j, int *sw)
{
    *i = 0;
    *j = 0;
    *sw = -1;
}