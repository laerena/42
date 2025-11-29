/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:00:36 by leilai            #+#    #+#             */
/*   Updated: 2025/11/29 18:32:17 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *leftover, char *buffer);
static int	append_to_leftover(char **leftover, char *buffer);
static char	*set_line(char *line);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = set_line(line);
	return (line);
}

static char	*set_line(char *line_buffer)
{
	char	*leftover;
	ssize_t	i;

	i = 0;
	if (!line_buffer)
		return (NULL);
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	leftover = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (leftover == NULL || *leftover == '\0')
	{
		free(leftover);
		return (NULL);
	}
	line_buffer[i + 1] = '\0';
	return (leftover);
}

static char	*fill_line(int fd, char *leftover, char *buffer)
{
	ssize_t	b_read;

	while (1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!append_to_leftover(&leftover, buffer))
		{
			free(leftover);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

static int	append_to_leftover(char **leftover, char *buffer)
{
	char	*tmp;

	if (!*leftover)
	{
		*leftover = ft_strdup("");
		if (!*leftover)
			return (0);
	}
	tmp = *leftover;
	*leftover = ft_strjoin(tmp, buffer);
	if (!*leftover)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
