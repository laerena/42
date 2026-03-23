#include "fdf.h"

static double	max_double(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

static double	min_double(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_color(int z)
{
	if (z > 0)
		return (0x00FF8800);
	if (z < 0)
		return (0x0000A0FF);
	return (0x00FFFFFF);
}

/*
** Project one map point into isometric space WITHOUT centering it in the window.
** This is used to measure the true size of the rendered model.
*/
t_point	project_raw(t_app *app, int x, int y)
{
	t_point	p;
	double	px;
	double	py;

	p.x = x * app->view.scale;
	p.y = y * app->view.scale;
	p.z = app->map.z[y][x] * app->view.z_scale;
	px = (p.x - p.y) * cos(app->view.angle);
	py = (p.x + p.y) * sin(app->view.angle) - p.z;
	p.x = px;
	p.y = py;
	p.color = get_color(app->map.z[y][x]);
	return (p);
}

/*
** Walk through the whole map and measure the min/max projected coordinates.
*/
static t_bounds	get_projected_bounds(t_app *app)
{
	t_bounds	b;
	t_point		p;
	int			x;
	int			y;

	p = project_raw(app, 0, 0);
	b.min_x = p.x;
	b.max_x = p.x;
	b.min_y = p.y;
	b.max_y = p.y;
	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			p = project_raw(app, x, y);
			b.min_x = min_double(b.min_x, p.x);
			b.max_x = max_double(b.max_x, p.x);
			b.min_y = min_double(b.min_y, p.y);
			b.max_y = max_double(b.max_y, p.y);
			x++;
		}
		y++;
	}
	return (b);
}

/*
** Compute a scale and shifts so the whole projected model fits inside the window.
** Margin keeps the drawing away from the edges.
*/
void	fit_view_to_window(t_app *app)
{
	t_bounds	b;
	double		model_w;
	double		model_h;
	double		margin;
	double		scale_x;
	double		scale_y;
	double		scale;

	margin = 50.0;
	app->view.scale = 1.0;
	app->view.z_scale = 1.0;
	b = get_projected_bounds(app);
	model_w = b.max_x - b.min_x;
	model_h = b.max_y - b.min_y;
	if (model_w < 1.0)
		model_w = 1.0;
	if (model_h < 1.0)
		model_h = 1.0;
	scale_x = (WIN_W - 2.0 * margin) / model_w;
	scale_y = (WIN_H - 2.0 * margin) / model_h;
	scale = scale_x;
	if (scale_y < scale)
		scale = scale_y;
	if (scale < 0.1)
		scale = 0.1;
	app->view.scale = scale;
	app->view.z_scale = scale / 2.0;
	b = get_projected_bounds(app);
	app->view.shift_x = (int)((WIN_W - (b.min_x + b.max_x)) / 2.0);
	app->view.shift_y = (int)((WIN_H - (b.min_y + b.max_y)) / 2.0);
}

/*
** Final version used by rendering:
** raw projection + shift into window coordinates.
*/
t_point	project_point(t_app *app, int x, int y)
{
	t_point	p;

	p = project_raw(app, x, y);
	p.x = p.x + app->view.shift_x;
	p.y = p.y + app->view.shift_y;
	return (p);
}
