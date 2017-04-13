/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:05:13 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:32:20 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_xx_dash(t_type *lst, unsigned int n, int size)
{
	if (FLAGS & 1 && n && (MFW -= 2))
		ft_memcpy_g(g_str, "0x", 2);
	if (PMFW > size && (PMFW > MFW || PMFW == MFW))
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_x(n);
	}
	else if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_x(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > size && (PMFW < size || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else if ((MFW < SIZE || MFW == 0) && (PMFW < SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
}

void		ft_display_arg_xx_no_dash2(t_type *lst, unsigned int n, int size)
{
	if (FLAGS & 1 && n && (MFW -= 2))
		ft_memcpy_g(g_str, "0X", 2);
	ft_memset_g_set(g_str, '0', PMFW - size);
}

void		ft_display_arg_xx_no_dash(t_type *lst, unsigned int n, int size)
{
	if (MFW > PMFW)
	{
		if (FLAGS & 4)
		{
			if (FLAGS & 1 && n && (MFW -= 2))
				ft_memcpy_g(g_str, "0x", 2);
			ft_memset_g_set(g_str, '0', PMFW - size);
		}
		else
		{
			if (FLAGS & 1 && n && (MFW -= 2))
				ft_memcpy_g(g_str, "0x", 2);
			ft_memset_g_set(g_str, ' ', MFW - PMFW);
			ft_memset_g_set(g_str, '0', PMFW - size);
		}
	}
	else
		ft_display_arg_xx_no_dash2(lst, n, size);
}

void		ft_display_arg_xx_no_dash3(t_type *lst, unsigned int n, int size)
{
	if (FLAGS & 1 && n)
		MFW -= 2;
	if (FLAGS & 4)
	{
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
		ft_memset_g_set(g_str, '0', MFW - size);
	}
	else
	{
		ft_memset_g_set(g_str, ' ', MFW - size);
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
	}
}

void		ft_display_arg_xx(t_type *lst, va_list list)
{
	unsigned int	n;

	if (MOD)
	{
		ft_display_arg_xx_mod(lst, list);
		return ;
	}
	n = va_arg(list, unsigned int);
	ft_check_size_hexa(lst, n);
	if (FLAGS & 2)
		ft_display_arg_xx_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_xx_no_dash(lst, n, SIZE);
		else if (((MFW <= SIZE || MFW == 0) && PMFW >= SIZE))
			ft_display_arg_xx_no_dash2(lst, n, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_xx_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memcpy_g(g_str, "0X", 2);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
	}
}
