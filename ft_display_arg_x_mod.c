/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_x_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:55:32 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/15 02:12:53 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg_x[] = {
	{104, &ft_display_arg_x_us},
	{208, &ft_display_arg_x_uchar},
	{108, &ft_display_arg_x_uintm},
	{216, &ft_display_arg_x_uintm},
	{106, &ft_display_arg_x_uintm},
	{122, &ft_display_arg_x_uintm},
};

void		ft_display_arg_x_mod(t_type *lst, va_list list)
{
	int j;

	j = -1;
	while (++j < 6)
		if (lst->mod == g_arg_x[j].c)
			g_arg_x[j].f(lst, list);
}
