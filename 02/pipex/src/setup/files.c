/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:55:55 by leilai            #+#    #+#             */
/*   Updated: 2026/03/16 21:11:17 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** opens the input file in read-only mode
** < file1
*/
static int	open_infile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror_exit(filename, 1);
	return (fd);
}

/*
** opens the output file in truncate-write mode
** > file2
**
** O_CREAT: creat if missing
** O_TRUNC: empty if it already exist
*/
static int	open_outfile(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror_exit(filename, 1);
	return (fd);
}

/*
** stores two file descriptors in central struct
**
** av[1] = infile
** av[4] = outfile
*/
void	init_files(t_pipex *px, char **av)
{
	px->infile = open_infile(av[1]);
	px->outfile = open_outfile(av[4]);
}
