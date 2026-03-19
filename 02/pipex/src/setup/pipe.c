/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:56:01 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 15:56:02 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** creates the pipe between cmd1 and cmd2
**
** pipefd[0] = read end
** pipefd[1] = write end
**
** cmd1 stdout --> pipefd[1] ... pipe ... pipefd[0] --> cmd2 stdin
*/
void	init_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		perror_exit("pipe", 1);
}
