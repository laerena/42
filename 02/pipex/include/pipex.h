/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:09:31 by leilai            #+#    #+#             */
/*   Updated: 2026/03/19 22:22:24 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

/*
** infile      -> fd for av[1]
** outfile     -> fd for av[4]
** pipefd[0]   -> read end of pipe
** pipefd[1]   -> write end of pipe
** pid1/pid2   -> child process ids
*/
typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

// setup
void	check_args(int argc);
void	init_files(t_pipex *px, char **av);
void	init_pipe(int pipefd[2]);

// process
void	create_children(t_pipex *px, char **av, char **envp);
void	redirect_c1(t_pipex *px);
void	redirect_c2(t_pipex *px);
int		wait_children(t_pipex *px);

// exec
void	exec_cmd(char *cmd_str, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
char	**ft_split(char const *s, char c);

// utils - errors
void	error_exit(char *msg, int code);
void	perror_exit(char *msg, int code);

// utils - strings
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);

// utils - cleanup
void	close_fd(int fd);
void	close_pipe(int pipefd[2]);
void	free_split(char **tab);

#endif