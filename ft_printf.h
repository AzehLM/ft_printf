/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:34:07 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/16 21:20:05 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);

int		ft_ptrhexa(void *ptr);
int		ft_putchar(int c);
int		ft_puthexa_lowercase(unsigned int n);
int		ft_puthexa_uppercase(unsigned int n);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_strlen(const char *s);
int		ft_unsigned_decimal(unsigned int n);
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

#endif
