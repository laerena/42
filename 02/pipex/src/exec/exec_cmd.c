/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:24 by leilai            #+#    #+#             */
/*   Updated: 2026/03/17 18:12:24 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// when PATH lookup fails
static void	cmd_not_found(char *cmd)
{
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
}

static void	clean_exec_exit(char *path, char **args, int code)
{
	free(path);
	free_split(args);
	exit(code);
}

/*
** executes one command string
**
** parse string to args
** find executable path
** call execve()
** if execve() returns, it failed
*/
void	exec_cmd(char *cmd_str, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd_str, ' ');
	if (!args || !args[0])
		error_exit("pipex: empty command", 127); // exit code 127 for command not found
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		cmd_not_found(args[0]);
		free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	perror(args[0]); // only reaches here if execve failed
	if (errorno == EACCES)
		clean_exec_exit(path, args, 126); //exit code 126 command found but not executable
	else
		clean_exec_exit(path, args, 127);
}
