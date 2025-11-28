/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:00:36 by leilai            #+#    #+#             */
/*   Updated: 2025/11/28 01:03:10 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_leftover(int fd, char *leftover, char *buffer);
static char	*get_line(char *leftover);
static char	*set_leftover(char *leftover);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = fill_leftover(fd, leftover, buffer);
	free(buffer);
	if (!leftover)
		return (NULL);
	line = get_line(leftover);
	if (!line)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = set_leftover(leftover);
	return (line);
}

/*
	fill_leftover:
	- reads until it finds '\n' in leftover or reaches EOF / error
	- on success, returns the updated leftover
	- on error (read < 0 or malloc fail), frees all it owns and returns NULL
*/
static char	*fill_leftover(int fd, char *leftover, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0 && !ft_strchr(leftover, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(leftover);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!leftover)
		{
			leftover = ft_strdup(buffer);
			if (!leftover)
				return (NULL);
		}
		else
		{
			tmp = ft_strjoin(leftover, buffer);
			if (!tmp)
			{
				free(leftover);
				return (NULL);
			}
			free(leftover);
			leftover = tmp;
		}
	}
	return (leftover);
}

/*
	get_line:
	- allocates and returns exactly one line from leftover
	- includes the '\n' if present
*/
static char	*get_line(char *leftover)
{
	ssize_t	i;

	if (!leftover || leftover[0] == '\0')
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	return (ft_substr(leftover, 0, i));
}

/*
	set_leftover:
	- cuts off the first line from leftover
	- returns a new leftover (everything after the first '\n')
	- frees the old leftover
*/
static char	*set_leftover(char *leftover)
{
	ssize_t	i;
	char	*new;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	i++;
	new = ft_substr(leftover, i, ft_strlen(leftover) - i);
	free(leftover);
	if (!new || new[0] == '\0')
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	if (!s)
		return (NULL);
	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return (&s[i]);
		i++;
	}
	if (s[i] == cc)
		return (&s[i]);
	return (NULL);
}
