/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:59:28 by leilai            #+#    #+#             */
/*   Updated: 2026/03/19 22:10:18 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// as execve() usually wants the full executable path
/*
** returns 1 if str starts with prefix
** detect "PATH=" in envp

static int	starts_with(char *str, char *prefix)
{
	int	i;

	i = 0;
	while (prefix[i])
	{
		if (str[i] != prefix[i])
			return (0);
		i++;
	}
	return (1);
}

** returns the value part of an environment variable
** eg.
** env entry: PATH=/usr/bin:/bin
** returns:   /usr/bin:/bin
*/
static char	*get_env_value(char **envp, char *name)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (name[j] && envp[i][j] == name[j])
			j++;
		if (name[j] == '\0')
			return (envp[i] + j);
		i++;
	}
	return (NULL);
}

/*
** returns 1 if cmd already contains '/'
** if it does we treat it as a direct path 
** instead of searching PATH
*/
static int	has_slash(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

/*
** builds dir/cmd in newly allocated memory
** eg.
** /usr/bin + grep --> /usr/bin/grep
*/
static char	*join_path(char *dir, char *cmd)
{
	char	*full;
	int		i;
	int		j;

	full = malloc(sizeof(char) * (ft_strlen(dir) + ft_strlen(cmd) + 2));
	if (!full)
		return (NULL);
	i = 0;
	j = 0;
	while (dir[i])
		full[j++] = dir[i++];
	full[j++] = '/';
	i = 0;
	while (cmd[i])
		full[j++] = cmd[i++];
	full[j] = '\0';
	return (full);
}

/*
** searches cmd inside the directories listed in PATH
**
** access() flags:
** F_OK → does the file exist
** R_OK → can it be read
** W_OK → can it be written
** X_OK → can it be executed
**
** returns NULL if command is not found
*/
static char	*search_in_paths(char **paths, char *cmd)
{
	char	*full;
	int		i;

	i = 0;
	while (paths[i])
	{
		full = join_path(paths[i], cmd);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

/*
** returns a malloc'd executable path for cmd
**
** if cmd contains '/' use it directly if executable
** otherwise search through PATH directories
*/
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full;

	if (has_slash(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_env = get_env_value(envp, "PATH=");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	full = search_in_paths(paths, cmd);
	free_split(paths);
	return (full);
}

/*
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full;
	int		i;

	if (has_slash(cmd))
	{
		if (access(cmd, X_OK) == 0) // can this files be executed as a program?
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_env = get_env_value(envp, "PATH=");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full = join_path(paths[i], cmd);
		if (full && access(full, X_OK) == 0)
			return (free_split(paths), full);
		free(full);
		i++;
	}
	free_split(paths);
	return (NULL);
}
*/