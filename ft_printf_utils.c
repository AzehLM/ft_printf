/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:39:48 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/16 16:39:46 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != (char) c)
		i++;
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	ten_power;
	long	nb;
	int		i;

	ten_power = 10;
	nb = n;
	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i += ft_putchar('-');
	}
	while (nb / (ten_power * 10) != 0)
		ten_power *= 10;
	while (ten_power != 0)
	{
		i += ft_putchar((nb / ten_power) + 48);
		nb %= ten_power;
		ten_power /= 10;
	}
	return (i);
}
