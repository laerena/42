/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:56:18 by leilai            #+#    #+#             */
/*   Updated: 2026/03/17 11:45:11 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "pipex.h"

/*
** Main orchestration
**
** - validate input
** - open both files
** - create the pipe
**
** Later:
** - create child 1
** - create child 2
** - close parent pipe fds
** - wait for both children
*/
int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	check_args(ac);
	init_files(&px, av);
	init_pipe(px.pipefd);
	create_children(&px, av, envp);
	close_fd(px.infile);
	close_fd(px.outfile);
	close_pipe(px.pipefd);
	return (wait_children(&px));
}
