/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:22:21 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/16 22:09:28 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthexa_lowercase(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_putnbr_base(n, "0123456789abcdef");
	return (count);
}

int	ft_puthexa_uppercase(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_putnbr_base(n, "0123456789ABCDEF");
	return (count);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	len_base;
	int				count;

	len_base = ft_strlen(base);
	count = 0;
	if (nbr >= len_base)
	{
		count += ft_putnbr_base(nbr / len_base, base);
		count += ft_putchar(base[nbr % len_base]);
	}
	else
		count += ft_putchar(base[nbr % len_base]);
	return (count);
}

int	ft_ptrhexa(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	if (!ptr)
		count += ft_putstr("(nil)");
	else
	{
		address = (unsigned long) ptr;
		count += write(1, "0x", 2);
		count += ft_puthexa_lowercase(address);
	}
	return (count);
}

int	ft_unsigned_decimal(unsigned int n)
{
	unsigned long	ten_power;
	unsigned int	nb;
	int				i;

	ten_power = 1;
	nb = n;
	i = 0;
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
