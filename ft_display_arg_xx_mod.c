/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_xx_mod.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:57:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/11 21:33:50 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg_xx[] = {
	{104, &ft_display_arg_xx_us},
	{208, &ft_display_arg_xx_uchar},
	{108, &ft_display_arg_xx_uintm},
	{216, &ft_display_arg_xx_uintm},
	{106, &ft_display_arg_xx_uintm},
	{122, &ft_display_arg_xx_uintm}
};

void		ft_display_arg_xx_mod(t_type *lst, va_list list)
{
	int j;

	j = -1;
	while (lst->mod != g_arg_xx[j].c && j++ < 6)
		if (lst->mod == g_arg_xx[j].c)
			g_arg_xx[j].f(lst, list);
}
