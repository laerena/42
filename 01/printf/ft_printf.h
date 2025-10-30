/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leilai <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:51 by leilai            #+#    #+#             */
/*   Updated: 2025/10/29 17:56:54 by leilai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_base(unsigned int n, char *base, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_putuint_fd(unsigned int n, int fd);
int	ft_handlef(const char *format, va_list args, int *i);
int	ft_printf(const char *format, ...);

#endif
