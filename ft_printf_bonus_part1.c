/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_part1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:42:47 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/21 15:37:27 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>

static int	ft_convert_args(int convert, t_flags flags, va_list args)
{
	int	len;

	len = 0;
	if (convert == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (convert == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (convert == 'p')
		len += ft_ptrhexa(va_arg(args, void *));
	else if (convert == 'u')
		len += ft_unsigned_decimal(va_arg(args, unsigned int));
	else if (convert == 'x')
		len += ft_puthexa_lowercase(va_arg(args, unsigned int), flags);
	else if (convert == 'X')
		len += ft_puthexa_uppercase(va_arg(args, unsigned int), flags);
	else if (convert == 'd' || convert == 'i')
		len += ft_putnbr(va_arg(args, int), flags);
	return (len);
}

static int	ft_parsing_flag(const char *format, int *index, va_list args)
{
	int		count;
	t_flags	flags;

	flags = (t_flags){false};
	while (strchr("# +", format[*index]))
	{
		if (format[*index] == '#')
			flags.hash = true;
		else if (format[*index] == ' ')
			flags.space = true;
		else if (format[*index] == '+')
			flags.sign = true;
		(*index)++;
	}
	if (ft_strchr("dixX", format[*index]))
		count = ft_convert_args(format[*index], flags, args);
	if (ft_strchr("cspdiuxX", format[*index]))
		count += ft_convert_args(format[*index], flags, args);
	return (count);
}

static int	ft_parse(const char *format, va_list args)
{
	int		index;
	int		len;
	t_flags flags;

	if (!format)
		return (-1);
	index = 0;
	len = 0;
	while (format && format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			index++;
			if (ft_strchr("# +", format[index]))
				len += ft_parsing_flag(&format[index], &index, args);
			else if (ft_strchr("cspdiuxX", format[index]))
				len += ft_convert_args(format[index], flags, args);
			else if (format[index] == '%')
				len += ft_putchar('%');
		}
		else if (format[index] == '%' && !format[index + 1])
			return (-1);
		else
			len += ft_putchar(format[index]);
		index++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_parse(format, args);
	va_end(args);
	return (len);
}
