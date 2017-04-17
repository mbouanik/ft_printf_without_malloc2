/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_o_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:52:42 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/15 02:13:36 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg_o[] = {
	{104, &ft_display_arg_o_us},
	{208, &ft_display_arg_o_uchar},
	{108, &ft_display_arg_o_uintm},
	{216, &ft_display_arg_o_uintm},
	{106, &ft_display_arg_o_uintm},
	{122, &ft_display_arg_o_uintm}
};

void		ft_display_arg_o_mod(t_type *lst, va_list list)
{
	int j;

	j = -1;
	while (++j < 6)
		if (lst->mod == g_arg_o[j].c)
			g_arg_o[j].f(lst, list);
}
