/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:00:10 by leilai            #+#    #+#             */
/*   Updated: 2026/03/17 16:58:43 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// close one fd if it looks valid
void	close_fd(int fd)
{
	if (fd >= 0)
		close(fd);
}

/*
** close both ends of a pipe
**
** used by parent after forking
** and by childern after dup2()
*/
void	close_pipe(int pipefd[2])
{
	close_fd(pipefd[0]);
	close_fd(pipefd[1]);
}

// frees a NULL-terminated array of strings
void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
