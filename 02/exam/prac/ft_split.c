#include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return(len);
}

char **ft_split(char *str)
{
    char **split;
    int i = 0;
    int j = 0;
    int k = 0;
    
    split = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
    while(str[i])
    {
        while (str[i] != ' ')
        {
            split[j][k] = str[i];
            i++;
            k++;
        }
        split[j][k] = '\0';
        j++;
        if (str[i] == ' ')
            i++;
    }
    split[j] = NULL;
    return (split);
}