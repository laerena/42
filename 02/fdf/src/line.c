/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:24:58 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:24:59 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// distance should always be postive
static int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

// prep all values the algorithm will update while drawing
static void	init_line(t_line *line, t_point a, t_point b)
{
	line->x0 = (int)a.x;
	line->y0 = (int)a.y;
	line->x1 = (int)b.x;
	line->y1 = (int)b.y; // convert projected floating-point coordinates into pixel coordinates
	line->dx = abs_i(line->x1 - line->x0);
	line->dy = abs_i(line->y1 - line->y0);
	line->sx = -1;
	line->sy = -1; // direction of movement 
	if (line->x0 < line->x1)
		line->sx = 1;
	if (line->y0 < line->y1)
		line->sy = 1;
	line->err = line->dx - line->dy;
}

// one Bresenham step updates x and/or y depending on the error
static void	step_line(t_line *line)
{
	line->e2 = line->err * 2;
	if (line->e2 > -line->dy) // move in x direction?
	{
		line->err = line->err - line->dy;
		line->x0 = line->x0 + line->sx;
	}
	if (line->e2 < line->dx) // move in y?
	{
		line->err = line->err + line->dx;
		line->y0 = line->y0 + line->sy;
	}
}

// draw from point A to point B, 1 pixel at a time
void	draw_line(t_img *img, t_point a, t_point b)
{
	t_line	line;

	init_line(&line, a, b);
	while (1)
	{
		put_pixel(img, line.x0, line.y0, a.color);
		if (line.x0 == line.x1 && line.y0 == line.y1) // reach destination
			break ;
		step_line(&line); // move to next pixel
	}
}
