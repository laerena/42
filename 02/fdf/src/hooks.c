/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:23:40 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:23:41 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		destroy_app(app);
		exit(0);
	}
	return (0);
}

int	close_hook(t_app *app)
{
	destroy_app(app);
	exit(0);
}
