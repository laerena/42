#include <stdlib.h>

static int is_sep(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
static int count_words(char *s)
{
    int i = 0, count = 0;

    while (s[i])
    {
        while (s[i] && is_sep(s[i]))
            i++;
        if (s[i])
            count++;
        while (s[i] && !is_sep(s[i]))
            i++;
    }
    return (count);
}
char **ft_split(char *str)
{
    char **out;
    int i = 0, w = 0, start, len, k;

    out = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!out)
        return (NULL);
    
    while (str[i])
    {
        while (str[i] && is_sep(str[i]))
            i++;
        if(!str[i])
            break;

        start = i;
        while (str[i] && !is_sep(str[i]))
            i++;
        len = i - start;

        out[w] = (char *)malloc(len + 1);
        if (!out[w])
            return (NULL);
        k = 0;
        while (k < len)
        {
            out[w][k] = str[start + k];
            k++;
        }
        out[w][k] = '\0';
        w++;
    }
    out[w] = NULL;
    return (out);
}