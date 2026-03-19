/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:55:39 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 21:10:16 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** verifies that the program receives exactly 4 arguments
** after the executable name, 5 in total
**
** argv[0] = ./pipex
** argv[1] = file1
** argv[2] = cmd1
** argv[3] = cmd2
** argv[4] = file2
*/
void	check_args(int ac)
{
	if (ac != 5)
		error_exit("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2", 1);
}
