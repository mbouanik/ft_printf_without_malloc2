/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_x_uintm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:27:54 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/11 10:17:40 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_x_uintm_no_dash2(t_type *lst, uintmax_t n)
{
	if ((FLAGS & 2) == 0)
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW - SIZE);
}

void		ft_display_arg_x_uintm_dash(t_type *lst, uintmax_t n)
{
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0x", 2);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
		ft_display_arg_x_uintm_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_putstr_hexa(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
	}
}

void		ft_display_arg_x_uintm_no_dash(t_type *lst, uintmax_t n)
{
	if (MFW > PMFW)
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		if (FLAGS & 4)
		{
			ft_display_pmfw(lst);
			ft_memset_g_set(g_str, '0', PMFW - SIZE);
		}
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
		ft_putstr_hexa(n);
	}
	else
		ft_display_arg_x_uintm_no_dash2(lst, n);
}

void		ft_display_arg_x_uintm_no_dash3(t_type *lst, uintmax_t n)
{
	if (FLAGS & 4 && PMFW != -1)
	{
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW - SIZE);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
	}
	else
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
	}
}

void		ft_display_arg_x_uintm(t_type *lst, va_list list)
{
	uintmax_t	n;

	n = va_arg(list, uintmax_t);
	SIZE = ft_strlen_hexa(n);
	ft_size(lst, SIZE);
	if (FLAGS & 1 && MFW >= 2)
		MFW -= 2;
	if (FLAGS & 2)
		ft_display_arg_x_uintm_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_x_uintm_no_dash(lst, n);
		else if (((MFW <= SIZE || MFW == 0) && PMFW >= SIZE))
			ft_display_arg_x_uintm_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_x_uintm_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 1 && n)
				ft_memcpy_g(g_str, "0x", 2);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_putstr_hexa(n);
		}
	}
}
