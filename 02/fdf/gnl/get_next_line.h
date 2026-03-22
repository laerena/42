/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <leilai@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:00:49 by leilai            #+#    #+#             */
/*   Updated: 2026/03/22 17:40:32 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_strdup(char *s);
size_t	gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int st, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

#endif
