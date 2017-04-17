/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:14:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/15 02:13:51 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg_d[] = {
	{104, &ft_display_arg_d_short},
	{208, &ft_display_arg_d_schar},
	{108, &ft_display_arg_d_intm},
	{216, &ft_display_arg_d_intm},
	{106, &ft_display_arg_d_intm},
	{122, &ft_display_arg_d_intm}
};

void		ft_display_arg_d_mod(t_type *lst, va_list list)
{
	int j;

	j = -1;
	while (++j < 6)
		if (lst->mod == g_arg_d[j].c)
			g_arg_d[j].f(lst, list);
}
