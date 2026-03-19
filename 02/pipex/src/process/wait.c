/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:07:01 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 21:26:04 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** waits for both children
*/
int	wait_children(t_pipex *px)
{
	int	status1;
	int	status2;

	status1 = 0;
	status2 = 0;
	waitpid(px->pid1, &status1, 0); // kernel writes exit info into status1
	waitpid(px->pid2, &status2, 0);
	if (WIFEXITED(status2)) // did process exit normally?
		return (WEXITSTATUS(status2)); // extracts exit code
	if (WIFEXITED(status1))
		return (WEXITSTATUS(status1));
	return (1);
}
