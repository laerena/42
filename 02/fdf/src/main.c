/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:24:15 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 20:08:53 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** flow:
** - parse the map
** - init MLX
** - compute a view that fits the map
** - render once
** - enter the event loop
*/
int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
	{
		write(2, "Usage: ./fdf <map.fdf>\n", 23);
		return (1);
	}
	ft_bzero(&app, sizeof(t_app));
	if (!parse_map(argv[1], &app.map))
		exit_error("Error: invalid map\n", &app);
	if (!init_app(&app))
		exit_error("Error: mlx init failed\n", &app);
	init_view(&app);
	mlx_hook(app.win, KeyPress, KeyPressMask, key_hook, &app);
	mlx_hook(app.win, DestroyNotify, StructureNotifyMask, close_hook, &app);
	mlx_expose_hook(app.win, expose_hook, &app);
	mlx_loop(app.mlx);
	return (0);
}

/*
** parse into map->z[y][x]
** project each (x, y, z) into screen coordinates
** connect neighbors with Bresenham
** write pixels into an MLX image
** push image to the window
*/