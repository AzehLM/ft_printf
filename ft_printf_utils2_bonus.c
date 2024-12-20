/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:09:44 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/25 14:12:00 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthexa_lowercase(unsigned long n)
{
	int	count;

	count = 0;
	count += ft_putnbr_base(n, "0123456789abcdef");
	return (count);
}
