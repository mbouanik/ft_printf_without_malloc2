/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:50:04 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/24 14:56:14 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flags_sign(t_type *lst, long n)
{
	if (FLAGS & 16 && n >= 0 && --MFW)
		ft_memset_g(g_str, '+', 1);
	else if (FLAGS & 8 && n >= 0 && --MFW)
		ft_memset_g(g_str, ' ', 1);
	else if (n < 0 && --MFW)
		ft_memset_g(g_str, '-', 1);
}

void			ft_flags_sign_float(t_type *lst, double n)
{
	if (FLAGS & 16 && n >= 0 && --MFW)
		ft_memset_g(g_str, '+', 1);
	else if (FLAGS & 8 && n >= 0 && --MFW)
		ft_memset_g(g_str, ' ', 1);
	else if (n < 0 && --MFW)
		ft_memset_g(g_str, '-', 1);
}

void			ft_display_mfw(t_type *lst)
{
	if (MFW > BUFF_SIZE)
	{
		ft_putstr_g(g_str);
		g_size += g_p;
		g_p = 0;
		if (FLAGS & 4 && lst->arg_type != '%')
			ft_memset_g_set(g_str, '0', BUFF_SIZE);
		else
			ft_memset_g_set(g_str, ' ', BUFF_SIZE);
		while (MFW > BUFF_SIZE)
		{
			ft_putstr_g(g_str);
			if (MFW > BUFF_SIZE)
				MFW -= BUFF_SIZE;
			g_size += BUFF_SIZE;
		}
		g_p = 0;
	}
}
