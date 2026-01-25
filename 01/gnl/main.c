/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:07:07 by leilai            #+#    #+#             */
/*   Updated: 2025/12/07 16:27:07 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}

/*
int main()
{
    char *s = "hello\nworld";
    char *p;
    char *copy;
    char *sub;
    char *join;

    printf("len of \"%s\" = %zu\n", s, ft_strlen(s));

    p = ft_strchr(s, '\n');
    if (p)
        printf("found '\\n' at index %ld\n", p - s);
    else
        printf("no '\\n', found\n");

    copy = ft_strdup(s);
    if (copy)
    {
        printf("copy = \"%s\"\n", copy);
        free(copy);
    }
    else
        printf("ft_strdup failed\n");
    
    sub = ft_substr(s, 6, 5);
    if (sub)
    {
        printf("substr: \"%s\"\n", sub);
        free(sub);
    }
    join = ft_strjoin("abc", "def");
    if (join)
    {
        printf("join: \"%s\"\n", join);
        free(join);
    }
    return (0);
}
*/  