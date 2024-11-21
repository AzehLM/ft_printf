// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   ft_printf_bonus_part1.c                            :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2024/11/17 20:42:47 by gueberso          #+#    #+#             */
// // /*   Updated: 2024/11/19 11:43:30 by gueberso         ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>

// // // static int	format_identifier(const char *format, const char *str)
// // // {
// // // 	int	i;

// // // 	i = 0;
// // // 	j = 0;
// // // 	while (str && str[i])
// // // 	{
// // // 		while (str[i] != )
// // // 	}
// // // }

// // static int	parsing_bonus(const char *format, va_list args)
// // {
// // 	int	i;

// // 	i = 0;
// // 	while (format[i])
// // 	{
// // 		if (format_identifier("dixX", &format[i]))
// // 			i++; //REMOTE THAT (ERROR MANAGEMENT)
// // 	}
// // }

// static t_bool	ft_reset_struct(t_bool *flags)
// {
// 	flags->hash = false;
// 	flags->space = false;
// 	flags->sign = false;
// }

static int	ft_parsing_flag(const char *format, int *index, va_list args)
{
	int	count;
	t_flags	flags;

	flags = (t_flags){false};
	while (strchr("# +", format[*index]))
	{
		if (format[*index]== '#')
			flags.hash = true;
		else if (format[*index] == ' ')
			flags.space = true;
		else if (format[*index] == '+')
			flags.sign = true;
		(*index)++;
	}
	if (ft_strchr("dixX", format[*index]))
		count = ft_flags_management(format[*index], flags, args);

	return (count);
}

static int	ft_parse(const char *format, va_list args)
{
	int	index;
	int	len;

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
			if (ft_strchr("cspdiuxX", format[index]))
				len += ft_convert_args(format[index], args);
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
