/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:24:49 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:43:05 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ft_split allocates a null-terminated array of strings.
void	free_words(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

// Free all map rows, then the row-pointer array.
void	free_map(t_map *map)
{
	int	y;

	if (!map->z)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->z[y]);
		y++;
	}
	free(map->z);
	map->z = NULL;
	map->width = 0;
	map->height = 0;
}

void	destroy_mlx(t_app *app)
{
	if (!app->mlx)
		return ;
	if (app->img.ptr)
		mlx_destroy_image(app->mlx, app->img.ptr);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
#ifdef __linux__
	mlx_destroy_display(app->mlx);
	free(app->mlx);
#endif
	app->mlx = NULL;
	app->win = NULL;
	app->img.ptr = NULL;
	app->img.addr = NULL;
}

// Destroy everything that may have been created.
void	destroy_app(t_app *app)
{
	free_map(&app->map);
	destroy_mlx(app);
}

void	exit_error(char *msg, t_app *app)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	destroy_app(app);
	exit(1);
}
