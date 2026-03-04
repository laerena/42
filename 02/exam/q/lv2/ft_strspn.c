#include <stdio.h>

size_t  ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int check;

    while (s[i])
    {
        int j = 0;
        check = 0;
        while (accept[j])
        {
            //flag that s[i] has been found in accept
            if (s[i] == accept[j])
                check = 1;
            j++;
        }
        //if never found return the index of the unfound char
        if (check == 0)
            return (i);
        i++;
    }
    return (i);
}