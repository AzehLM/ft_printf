/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:59:30 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/21 17:43:58 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

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
	int	count;

	count = 0;
	while (s && s[count])
		count++;
	return (count);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		count += write(1, "(null)", 6);
	while (str && str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_bonus(int n, t_flags flags)
{
	long	ten_power;
	long	nb;
	int		count;

	ten_power = 1;
	nb = n;
	count = 0;
	printf("flags.sign value = %d\n", flags.sign);
	if (flags.sign == true && n >= 0)
		count += ft_putchar('+');
	else if (flags.space == true && flags.sign == false && n >= 0)
		count += ft_putchar(' ');
	if (nb < 0)
	{
		nb = nb * -1;
		count += ft_putchar('-');
	}
	while (nb / (ten_power * 10) != 0)
		ten_power *= 10;
	while (ten_power != 0)
	{
		count += ft_putchar((nb / ten_power) + 48);
		nb %= ten_power;
		ten_power /= 10;
	}
	return (count);
}
