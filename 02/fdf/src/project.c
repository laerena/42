/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:09 by leilai            #+#    #+#             */
/*   Updated: 2026/03/23 15:46:54 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// visible height
int	get_color(int z)
{
	if (z > 0)
		return (0x00FF8800);
	if (z < 0)
		return (0x0000A0FF);
	return (0x00FFFFFF);
}

/*
** convert one map cell into projected screen coordinates
**
** - use map indices as x/y and map value as z
** - scale them
** - apply isometric projection
** - result to window
*/
t_point	project_point(t_app *app, int x, int y)
{
	t_point	p;
	double	px;
	double	py;

	p.x = x * app->view.scale;
	p.y = y * app->view.scale; // raw grid spacing
	p.z = app->map.z[y][x] * app->view.z_scale; // altitude strength
	px = (p.x - p.y) * cos(app->view.angle);
	py = (p.x + p.y) * sin(app->view.angle) - p.z; // isometric formula
	p.x = px + app->view.shift_x;
	p.y = py + app->view.shift_y; // final placement/screen offsets
	p.color = get_color(app->map.z[y][x]);
	return (p);
}
