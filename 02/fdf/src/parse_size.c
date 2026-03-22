/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:05 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:25:06 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// count how many tokens ft_split produced
static int	word_count(char **words)
{
	int	count;

	count = 0;
	while (words[count])
		count++;
	return (count);
}

// read one line and determine how many map entries it contains
static int	line_width(char *line)
{
	int		width;
	char	**words;

	words = ft_split(line, ' ');
	if (!words)
		return (-1);
	width = word_count(words);
	free_words(words);
	return (width);
}

/*
** first pass:
** - count height
** - detect width from the first row
** - verify all rows have the same width
*/
int	get_map_size(char *path, t_map *map)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		width = line_width(line);
		if (width <= 0 || (map->width != 0 && width != map->width))
			return (free(line), close(fd), 0);
		if (map->width == 0)
			map->width = width;
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->width == 0 || map->height == 0)
		return (0);
	return (1);
}
