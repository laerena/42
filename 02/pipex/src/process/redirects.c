/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:37:50 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 21:46:49 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** First child redirection:
**
** file1 --> cmd1 --> pipe
** for child 1:
** - stdin must come from infile
** - stdout must go to pipe write end
**
** dup2(oldfd, newfd):
** make newfd refer to the same open resource as oldfd
*/
void	redirect_c1(t_pipex *px)
{
	if (dup2(px->infile, STDIN_FILENO) == -1) // reading from stdin actuall reads from infile
		perror_exit("dup2", 1);
	if (dup2(px->pipefd[1], STDOUT_FILENO) == -1) // writing to stdout actually writes into the pipe
		perror_exit("dup2", 1);
}
/*
** Second child redirection:
**
** pipe --> cmd2 --> file2
** for child 2:
** - stdin must come from pipe read end
** - stdout must go to outfile
*/
void	redirect_c2(t_pipex *px)
{
	if (dup2(px->pipefd[0], STDIN_FILENO) == -1) // reading from stdin actually reads from the pipe
		perror_exit("dup2", 1);
	if (dup2(px->outfile, STDOUT_FILENO) == -1) // writing to stdout actually writes to outfile
		perror_exit("dup2", 1);
}
