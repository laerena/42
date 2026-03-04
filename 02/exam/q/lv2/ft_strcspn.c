#include <stdio.h>

//basically count how many indexs of s we go through
//until we find a s[i] that is in c
size_t ft_strcspn(const char *s, const char *c)
{
    size_t i = 0;
    while (s[i++])
    {
        size_t j = 0;
        //check the current s[i] against all char in c
        while (c[j])
        {
            if (s[i] == c[j++])
                return (i);
        }
    }
    return (i);
}