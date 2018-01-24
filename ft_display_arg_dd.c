/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_dd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 06:16:13 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/17 15:33:10 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_dd_dash(t_type *lst, long n, int size)
{
	ft_flags_sign(lst, n);
	if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW < size && PMFW > size && PMFW >= MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
	}
	else if (MFW > size && PMFW < size)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
}

void		ft_display_arg_dd_no_dash2(t_type *lst, long n, int size)
{
	if (n < 0 || FLAGS & 16 || FLAGS & 8)
	{
		if ((FLAGS & 16) && n >= 0)
			ft_memset_g_set(g_str, '+', 1);
		else if (n < 0)
			ft_memset_g_set(g_str, '-', 1);
		else if (FLAGS & 8 && n > 0)
			ft_memset_g_set(g_str, ' ', 1);
	}
	ft_memset_g_set(g_str, '0', PMFW - size);
}

void		ft_display_arg_dd_no_dash(t_type *lst, long n, int size)
{
	if (MFW > PMFW)
	{
		if (n < 0 || FLAGS & 16)
			MFW--;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n >= 0)
				ft_memset_g_set(g_str, '+', 1);
			else
				ft_memset_g_set(g_str, '-', 1);
		}
		ft_memset_g_set(g_str, '0', PMFW - size);
	}
	else if (PMFW >= MFW)
		ft_display_arg_dd_no_dash2(lst, n, size);
}

void		ft_display_arg_dd_no_dash3(t_type *lst, long n, int size)
{
	if (FLAGS & 4 && PMFW != -1)
	{
		ft_flags_sign(lst, n);
		if (MFW && FLAGS & 4)
			size += 1;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW - size);
	}
	else
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - size);
		if (FLAGS & 16 && n >= 0)
			ft_memset_g_set(g_str, '+', 1);
		if (n < 0 && --g_p)
			ft_memset_g_set(g_str, '-', 1);
	}
	if (PMFW == -1 && !(n))
		return ;
}

void		ft_display_arg_dd(t_type *lst, va_list list)
{
	long	n;

	n = va_arg(list, long);
	if ((SIZE = ft_strlen_num(n)) && PMFW == -1 && n == 0)
		SIZE = 1;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_dd_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_dd_no_dash(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_dd_no_dash2(lst, n, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_dd_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			if ((FLAGS & 16 || FLAGS & 8) || n < 0)
				ft_flags_sign(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
	}
}
