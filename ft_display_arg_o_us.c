/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_o_us.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:25:09 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:40:17 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_o_us_dash(t_type *lst, unsigned short n, int size)
{
	if (FLAGS & 1 && n && --MFW)
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > size && (PMFW > MFW || PMFW == MFW))
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_octal(n);
	}
	else if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_octal(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > size && (PMFW < size || PMFW == 0))
	{
		ft_putstr_octal(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
		ft_putstr_octal(n);
}

void	ft_display_arg_o_us_no_dash2(t_type *lst, unsigned short n, int size)
{
	ft_memset_g_set(g_str, '0', PMFW - size);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_us_no_dash(t_type *lst, unsigned short n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_octal(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_o_us_no_dash2(lst, n, size);
}

void	ft_display_arg_o_us_no_dash3(t_type *lst, unsigned short n, int size)
{
	ft_memset_g_set(g_str, ' ', MFW - size);
	if (FLAGS & 1 && g_p--)
		ft_memset_g_set(g_str, '0', 1);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_us(t_type *lst, va_list list)
{
	unsigned short		n;

	n = (unsigned short)va_arg(list, unsigned int);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_o_us_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_o_us_no_dash(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_o_us_no_dash2(lst, n, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_o_us_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 1)
				ft_memset_g_set(g_str, '0', 1);
			ft_putstr_octal(n);
		}
	}
}
