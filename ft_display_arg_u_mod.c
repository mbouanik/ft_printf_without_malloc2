/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_u_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:59:27 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/16 00:15:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg_u[] = {
	{104, &ft_display_arg_u_us},
	{208, &ft_display_arg_u_uchar},
	{108, &ft_display_arg_u_uintm},
	{216, &ft_display_arg_u_uintm},
	{106, &ft_display_arg_u_uintm},
	{122, &ft_display_arg_u_uintm},
};

void		ft_display_arg_u_mod(t_type *lst, va_list list)
{
	int j;

	j = -1;
	while (++j < 6)
		if (lst->mod == g_arg_u[j].c)
			g_arg_u[j].f(lst, list);
}
