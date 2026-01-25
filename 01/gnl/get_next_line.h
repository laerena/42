/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:53:22 by leilai            #+#    #+#             */
/*   Updated: 2025/12/07 15:08:42 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>   // read, ssize_t
# include <stdlib.h>   // malloc, free
# include <limits.h>   // OPEN_MAX

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char    *get_next_line(int fd);

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int st, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);

#endif