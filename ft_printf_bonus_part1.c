// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_printf_bonus_part1.c                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/17 20:42:47 by gueberso          #+#    #+#             */
// /*   Updated: 2024/11/18 12:13:44 by gueberso         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf_bonus.h"
// #include <stdarg.h>

// // static int	format_identifier(const char *format, const char *str)
// // {
// // 	int	i;

// // 	i = 0;
// // 	j = 0;
// // 	while (str && str[i])
// // 	{
// // 		while (str[i] != )
// // 	}
// // }

// static int	parsing_bonus(const char *format, va_list args)
// {
// 	int	i;

// 	i = 0;
// 	while (format[i])
// 	{
// 		if (format_identifier("dixX", &format[i]))
// 	}
// }

// static int	ft_parse(const char *format, va_list args)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (format && format[i])
// 	{
// 		if (format[i] == '%' && format[i + 1])
// 		{
// 			i++;
// 			parsing_bonus(&format[i], args);
// 		}
// 	}
// }



// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		len;

// 	va_start(args, format);
// 	len = ft_parse(format, args);
// 	va_end(args);
// 	return (len);
// }
