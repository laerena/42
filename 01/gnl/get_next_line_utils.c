/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:55:31 by leilai            #+#    #+#             */
/*   Updated: 2025/12/07 15:23:15 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//size_t standard type for length/indices
size_t  ft_strlen(const char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}
//return a pointer to the first occurrence of char c in s or NULL if not found
char    *ft_strchr(const char *s, int c)
{
    unsigned char   cc;

    if (!s)
        return (NULL);
    cc = (unsigned char)c;
    while (*s)
    {
        if (*s == cc)
            return ((char *)s);
        s++;
    }
    if (cc == '\0')
        return ((char *)s);
    return (NULL);
}
//allocate and return a copy of s
char    *ft_strdup(const char *s)
{
    char    *copy;
    size_t  i;

    if (!s)
        return (NULL);
    copy = malloc(ft_strlen(s) + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
//allocate and return a substring of s
char    *ft_substr(char const *s, unsigned int st, size_t len)
{
    size_t  i;
    char    *sub;

    if (!s)
        return (NULL);
    if (st >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + st))
        len = ft_strlen(s + st);
    sub = malloc(len + 1 * sizeof(char));
    if(!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[st + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
//allocate and return a new string s1 followed by s2
char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *res;
    size_t  i;
    size_t  j;

    res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        res [i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);
}

