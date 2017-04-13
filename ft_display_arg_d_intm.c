/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d_intm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:45:29 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:50:46 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_d_intm_dash(t_type *lst, long n, int size)
{
	if ((FLAGS & 16 || FLAGS & 20) && n > 0)
		ft_memset_g_set(g_str, '+', 1);
	if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_longtoa(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if ((MFW < size && PMFW > size) || PMFW > MFW || PMFW == MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_longtoa(n);
	}
	else if (MFW > size && PMFW < size)
	{
		if (FLAGS & 16)
			MFW--;
		ft_longtoa(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
		ft_longtoa(n);
}

void	ft_display_arg_d_intm_no_dash2(t_type *lst, long n, int size)
{
	if (n < 0 || FLAGS & 16 || FLAGS & 8)
	{
		if ((FLAGS & 16) && n > 0)
			ft_memset_g_set(g_str, '+', 1);
		else if (n < 0)
			ft_memset_g_set(g_str, '-', 1);
		else if (FLAGS & 8 && n > 0)
			ft_memset_g_set(g_str, ' ', 1);
	}
	ft_memset_g_set(g_str, '0', PMFW - size);
	ft_longtoa(n);
}

void	ft_display_arg_d_intm_no_dash(t_type *lst, long n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n > 0)
				ft_memset_g_set(g_str, '+', 1);
			else
				ft_memset_g_set(g_str, '-', 1);
		}
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_longtoa(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_d_intm_no_dash2(lst, n, size);
}

void	ft_display_arg_d_intm_no_dash3(t_type *lst, long n, int size)
{
	if (FLAGS & 4)
	{
		ft_flags_sign(lst, n);
		ft_memset_g_set(g_str, '0', MFW - size);
	}
	else
	{
		if (FLAGS & 16)
			--MFW;
		ft_memset_g_set(g_str, ' ', MFW - size);
		if (FLAGS & 16)
			ft_memset_g_set(g_str, '+', 1);
	}
	ft_longtoa(n);
}

void	ft_display_arg_d_intm(t_type *lst, va_list list)
{
	long		n;

	n = va_arg(list, long);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_d_intm_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_d_intm_no_dash(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_d_intm_no_dash2(lst, n, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_d_intm_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if ((FLAGS & 16 || FLAGS & 8))
				ft_flags_sign(lst, n);
			ft_longtoa(n);
		}
	}
}
