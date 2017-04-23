/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_x_uintm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:27:54 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/23 02:36:31 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_x_uintm_dash(t_type *lst, uintmax_t n, int size)
{
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0x", 2);
	if (PMFW > size && (PMFW > MFW || PMFW == MFW))
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_hexa(n);
	}
	else if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_putstr_hexa(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > size && (PMFW < size || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
	}
}

void		ft_display_arg_x_uintm_no_dash2(t_type *lst, uintmax_t n, int size)
{
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0x", 2);
	ft_memset_g_set(g_str, '0', PMFW - size);
}

void		ft_display_arg_x_uintm_no_dash(t_type *lst, uintmax_t n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', PMFW - size);
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
		ft_putstr_hexa(n);
	}
	else
		ft_display_arg_x_uintm_no_dash2(lst, n, size);
}

void		ft_display_arg_x_uintm_no_dash3(t_type *lst, uintmax_t n, int size)
{
	if (FLAGS & 4 && PMFW != -1)
	{
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
		ft_memset_g_set(g_str, '0', MFW - size);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
	}
	else
	{
		ft_memset_g_set(g_str, ' ', MFW - size);
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
		ft_display_arg_x_uintm_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_x_uintm_no_dash(lst, n, SIZE);
		else if (((MFW <= SIZE || MFW == 0) && PMFW >= SIZE))
			ft_display_arg_x_uintm_no_dash2(lst, n, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_x_uintm_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 1 && n)
				ft_memcpy_g(g_str, "0x", 2);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_putstr_hexa(n);
		}
	}
}
