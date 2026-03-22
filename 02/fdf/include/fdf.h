/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:54:48 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:43:23 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# ifdef __linux__
#  include <X11/X.h>
#  include <X11/keysym.h>
#  define KEY_ESC XK_Escape
# else
#  define KEY_ESC 53 // mac only
# endif

# define WIN_W 1400
# define WIN_H 900
# define ISO_ANGLE 0.523599

// mlx image buffer to draw pixels into an image
typedef struct s_img
{
	void	*ptr; // mlx_new_image()
	char	*addr; // mlx_get_data_addr() 
	// raw memory address of the image pixel data
	int		bpp; // bits per pixel, macos mlx sets 32 bits = 4 bytes
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z;
}	t_map;

typedef struct s_view
{
	double	scale;
	double	z_scale;
	double	angle;
	int		shift_x;
	int		shift_y;
}	t_view;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

// Bresenham support
// describes the state of an algorithm while running
typedef struct s_line
{
	int		x0;
	int		y0; // current start/current pixel
	int		x1;
	int		y1; // target end
	int		dx;
	int		dy; // absolute distances
	int		sx;
	int		sy; // step directions +1/-1
	int		err;
	int		e2;
}	t_line;

// central
typedef struct s_app
{
	void	*mlx; // mlx connection/context mlx_init()
	void	*win;
	t_img	img;
	t_map	map;
	t_view	view;
}	t_app;

// init
int		init_app(t_app *app);
void	init_view(t_app *app);

// destroy
void	free_words(char **words);
void	free_map(t_map *map);
void	destroy_mlx(t_app *app);
void	destroy_app(t_app *app);
void	exit_error(char *msg, t_app *app);

// parsing
int		get_map_size(char *path, t_map *map);
int		parse_map(char *path, t_map *map);

// pixels
void	put_pixel(t_img *img, int x, int y, int color);
void	clear_image(t_img *img, int color);

// projection
t_point	project_point(t_app *app, int x, int y);
int		get_color(int z);

// lines
void	draw_line(t_img *img, t_point a, t_point b);

// render
void	render_scene(t_app *app);
int		expose_hook(t_app *app);

// hooks
int		key_hook(int keycode, t_app *app);
int		close_hook(t_app *app);

#endif