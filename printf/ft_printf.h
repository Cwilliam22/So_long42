/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:08:20 by wcapt             #+#    #+#             */
/*   Updated: 2024/10/17 06:13:56 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
ssize_t	ft_putstr(char *s);
ssize_t	ft_putchar(char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_adresse(void *adresse);
ssize_t	ft_hexa_conv(unsigned int c, int index);
ssize_t	ft_put_u_nbr(unsigned long n);

#endif
