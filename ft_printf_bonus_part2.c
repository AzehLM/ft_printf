/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_part2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:46:45 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/21 15:02:45 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_puthexa_lowercase(unsigned long n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash == true)
		count += ft_putstr("0x");
	count += ft_putnbr_base(n, "0123456789abcdef");
	return (count);
}

int	ft_puthexa_uppercase(unsigned int n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash == true)
		count += ft_putstr("0X");
	count += ft_putnbr_base(n, "0123456789ABCDEF");
	return (count);
}
