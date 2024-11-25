/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:30 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/25 14:47:45 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_list
{
	bool	hash;
	bool	space;
	bool	sign;
}	t_flags;

char	*ft_strchr(const char *s, int c);
int		ft_ptrhexa(void *ptr);
int		ft_putchar(int c);
int		ft_puthexa_lowercase_bonus(unsigned long n, t_flags flags);
int		ft_puthexa_uppercase_bonus(unsigned int n, t_flags flags);
int		ft_puthexa_lowercase(unsigned long n);
int		ft_putnbr_base(unsigned long nbr, char *base);
int		ft_putnbr_bonus(int n, t_flags flags, long ten_power, int count);
int		ft_putstr(char *str);
int		ft_strlen(const char *s);
int		ft_unsigned_decimal(unsigned int n);

int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

#endif
