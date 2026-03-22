/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:24:54 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 20:09:13 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** image buffer for drawing pixels first
** later push that full image to the window
*/
static int	init_image(t_app *app)
{
	app->img.ptr = mlx_new_image(app->mlx, WIN_W, WIN_H); // create an off-screen image buffer/a canvas
	if (!app->img.ptr)
		return (0);
	app->img.addr = mlx_get_data_addr(app->img.ptr,
			&app->img.bpp,
			&app->img.line_len,
			&app->img.endian);
	if (!app->img.addr)
	{
		destroy_mlx(app);
		return (0);
	}
	return (1);
}

/*
** mlx order:
** mlx_init -> new_window -> new_image
*/
int	init_app(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, WIN_W, WIN_H, "fdf");
	if (!app->win)
		return (destroy_mlx(app), 0);
	if (!init_image(app))
		return (destroy_mlx(app), 0);
	return (1);
}

/*
** the view stores how large the map should appear
** how much z should influence height, and where to center it
**
** make visual adjustments HERE
*/
void	init_view(t_app *app)
{
	int		size;
	double	w_scale;
	double	h_scale;

	size = app->map.width;
	if (app->map.height > size)
		size = app->map.height;
	if (size < 1)
		size = 1;
	w_scale = (double)(WIN_W / 3) / size; // only use about 1/3 of the window
	h_scale = (double)(WIN_H / 3) / size;
	app->view.scale = w_scale;
	if (h_scale < app->view.scale)
		app->view.scale = h_scale;
	if (app->view.scale < 1.0)
		app->view.scale = 1.0;
	app->view.z_scale = app->view.scale / 2.0;
	app->view.angle = ISO_ANGLE;
	app->view.shift_x = WIN_W / 2;
	app->view.shift_y = WIN_H / 4;
}
