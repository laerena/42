/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:36:29 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 21:55:53 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
** child 1 responsibly for cmd1
** < file cmd1 | ...
** 1. redirect infile -> stdin
** 2. redirect pipe write end -> stdout
** 3. close all original fds no longer needed
** 4. excute cmd1
*/
static void	child1(t_pipex *px, char **av, char **envp)
{
	redirect_c1(px);
	close_fd(px->infile);
	close_fd(px->outfile);
	close_pipe(px->pipefd);
	exec_cmd(av[2], envp);
}

static void	child2(t_pipex *px, char **av, char **envp)
{
	redirect_c2(px);
	close_fd(px->infile);
	close_fd(px->outfile);
	close_pipe(px->pipefd);
	exec_cmd(av[3], envp);
}

void	create_children(t_pipex *px, char **av, char **envp)
{
	px->pid1 = fork();
	if (px->pid1 < 0)
		perror_exit("fork", 1);
	if (px->pid1 == 0)
		child1(px, av, envp); // only child enters child-specific logic
	px->pid2 = fork();
	if (px->pid2 < 0)
		perror_exit("fork", 1);
	if (px->pid2 == 0)
		child2(px, av, envp);
}
