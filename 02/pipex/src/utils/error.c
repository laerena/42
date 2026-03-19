/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:56:06 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 15:56:07 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** writes an error message to stderr and exits
** stderr = file descriptor 2
*/
void	error_exit(char *msg, int code)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(code);
}

/*
** print a system-level error message and exits
** eg. "infile: No such file or directory"
*/
void	perror_exit(char *msg, int code)
{
	perror(msg);
	exit(code);
}
