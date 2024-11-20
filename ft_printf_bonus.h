/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:16:30 by gueberso          #+#    #+#             */
/*   Updated: 2024/11/19 11:31:34 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdbool.h>

int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

typedef struct	s_list
{
	bool	hash;
	bool	space;
	bool	sign;
}	t_bool;	

#endif
