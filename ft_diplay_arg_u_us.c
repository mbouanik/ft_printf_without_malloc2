/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diplay_arg_u_us.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:14:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/11 05:19:35 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_diplay_arg_u_us_dash(t_type *lst, unsigned short n, int size)
{
	if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_itoustr(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if ((MFW < size && PMFW > size) || PMFW > MFW || PMFW == MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_itoustr(n);
	}
	else if (MFW > size && PMFW < size)
	{
		ft_itoustr(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
		ft_itoustr(n);
}

void	ft_diplay_arg_u_us_no_dash2(t_type *lst, unsigned short n, int size)
{
	if (FLAGS & 8 && PMFW++ && size++)
		ft_memset_g_set(g_str, ' ', 1);
	ft_memset_g_set(g_str, '0', PMFW - size);
	ft_itoustr(n);
}

void	ft_diplay_arg_u_us_no_dash(t_type *lst, unsigned short n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_itoustr(n);
	}
	else if (PMFW >= MFW)
		ft_diplay_arg_u_us_no_dash2(lst, n, size);
}

void	ft_diplay_arg_u_us_no_dash3(t_type *lst, unsigned short n, int size)
{
	if (FLAGS & 4)
	{
		if (FLAGS & 8 && size++)
			ft_memset_g_set(g_str, ' ', 1);
		ft_memset_g_set(g_str, '0', MFW - size);
	}
	else
		ft_memset_g_set(g_str, ' ', MFW);
	ft_itoustr(n);
}

void	ft_diplay_arg_u_us(t_type *lst, va_list list)
{
	unsigned short	n;
	int				size;

	n = (unsigned short)va_arg(list, int);
	size = ft_strlen_num(n);
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_diplay_arg_u_us_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_diplay_arg_u_us_no_dash(lst, n, size);
		else if ((MFW < size || MFW == 0) && PMFW > size)
			ft_diplay_arg_u_us_no_dash2(lst, n, size);
		else if (MFW > size && (PMFW < size || PMFW == 0))
			ft_diplay_arg_u_us_no_dash3(lst, n, size);
		else if ((MFW < size || MFW == 0) && (PMFW < size || PMFW == 0))
		{
			if (FLAGS & 8 && size++)
				ft_memset_g_set(g_str, ' ', 1);
			ft_itoustr(n);
		}
	}
}
