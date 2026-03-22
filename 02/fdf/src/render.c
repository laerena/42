/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:16 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:25:17 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** each map point connects:
** - the point on its right
** - the point below it
**
** to creates the wireframe grid
*/
static void	draw_neighbors(t_app *app, int x, int y)
{
	t_point	a;
	t_point	b;

	a = project_point(app, x, y);
	if (x + 1 < app->map.width)
	{
		b = project_point(app, x + 1, y);
		draw_line(&app->img, a, b);
	}
	if (y + 1 < app->map.height)
	{
		b = project_point(app, x, y + 1);
		draw_line(&app->img, a, b);
	}
}

static void	draw_grid(t_app *app)
{
	int	x;
	int	y;

	y = 0;
	while (y < app->map.height) // walk the full grid
	{
		x = 0;
		while (x < app->map.width)
		{
			draw_neighbors(app, x, y);
			x++;
		}
		y++;
	}
}

void	render_scene(t_app *app)
{
	clear_image(&app->img, 0x00000000);
	draw_grid(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img.ptr, 0, 0);
}

// redraw visible window
int	expose_hook(t_app *app)
{
	render_scene(app);
	return (0);
}
