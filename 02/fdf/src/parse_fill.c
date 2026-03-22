/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:23:54 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:23:55 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_rows(int **z, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(z[i]);
		i++;
	}
	free(z);
}

// allocate one int row per map line
static int	alloc_map(t_map *map)
{
	int	y;

	map->z = malloc(sizeof(int *) * map->height);
	if (!map->z)
		return (0);
	y = 0;
	while (y < map->height)
	{
		map->z[y] = malloc(sizeof(int) * map->width);
		if (!map->z[y])
		{
			free_rows(map->z, y);
			map->z = NULL;
			return (0);
		}
		y++;
	}
	return (1);
}

/*
** ft_atoi stops at the first non-digit
** values like "12,0xFFAA00" still give z = 12
*/
static int	fill_row(t_map *map, int y, char *line)
{
	int		x;
	char	**words;

	words = ft_split(line, ' ');
	if (!words)
		return (0);
	x = 0;
	while (x < map->width)
	{
		map->z[y][x] = ft_atoi(words[x]); // retrieves only the int value
		x++;
	}
	free_words(words);
	return (1);
}

/*
** second pass:
** reopen the file and actually store the z-values.
*/
static int	read_values(char *path, t_map *map)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!fill_row(map, y, line))
			return (free(line), close(fd), 0);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

// first know the size, then allocate, then fill.
int	parse_map(char *path, t_map *map)
{
	if (!get_map_size(path, map))
		return (0);
	if (!alloc_map(map))
		return (0);
	if (!read_values(path, map))
	{
		free_map(map);
		return (0);
	}
	return (1);
}
