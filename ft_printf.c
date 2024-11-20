/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:15:18 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/20 11:21:47 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_convert_args(int convert, va_list args) // to do : rename convert to identifier
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
		len += ft_puthexa_lowercase(va_arg(args, unsigned int));
	else if (convert == 'X')
		len += ft_puthexa_uppercase(va_arg(args, unsigned int));
	else if (convert == 'd' || convert == 'i')
		len += ft_putnbr(va_arg(args, int));
	return (len);
}

static int	ft_parse(const char *format, va_list args) 
{
	int	i;
	int	len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			i++;
			if (ft_strchr("cspdiuxX", format[i]))
				len += ft_convert_args(format[i], args);
			else if (format[i] == '%')
				len += ft_putchar('%');
		}
		else if (format[i] == '%' && !format[i + 1])
			return (-1);
		else
			len += ft_putchar(format[i]);
		i++;
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
