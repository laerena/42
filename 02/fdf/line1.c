/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:24:58 by leilai            #+#    #+#             */
/*   Updated: 2026/03/23 16:37:17 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
** Return 1 if the whole line is definitely outside the screen
** on the same side, so there is nothing useful to draw.
*/
static int	line_outside_screen(t_point a, t_point b)
{
	if (a.x < 0 && b.x < 0)
		return (1);
	if (a.x >= WIN_W && b.x >= WIN_W)
		return (1);
	if (a.y < 0 && b.y < 0)
		return (1);
	if (a.y >= WIN_H && b.y >= WIN_H)
		return (1);
	return (0);
}

static void	init_line(t_line *line, t_point a, t_point b)
{
	line->x0 = (int)a.x;
	line->y0 = (int)a.y;
	line->x1 = (int)b.x;
	line->y1 = (int)b.y;
	line->dx = abs_i(line->x1 - line->x0);
	line->dy = abs_i(line->y1 - line->y0);
	line->sx = -1;
	line->sy = -1;
	if (line->x0 < line->x1)
		line->sx = 1;
	if (line->y0 < line->y1)
		line->sy = 1;
	line->err = line->dx - line->dy;
}

static void	step_line(t_line *line)
{
	line->e2 = line->err * 2;
	if (line->e2 > -line->dy)
	{
		line->err = line->err - line->dy;
		line->x0 = line->x0 + line->sx;
	}
	if (line->e2 < line->dx)
	{
		line->err = line->err + line->dx;
		line->y0 = line->y0 + line->sy;
	}
}

void	draw_line(t_img *img, t_point a, t_point b)
{
	t_line	line;

	if (line_outside_screen(a, b))
		return ;
	init_line(&line, a, b);
	while (1)
	{
		put_pixel(img, line.x0, line.y0, a.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		step_line(&line);
	}
}
