/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_o_uchar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:20:51 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/11 05:22:06 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_o_uchar_dash(t_type *lst, unsigned char n, int size)
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

void	ft_display_arg_o_uchar_no_dash2(t_type *lst, unsigned char n, int size)
{
	ft_memset_g_set(g_str, '0', PMFW - size);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_uchar_no_dash(t_type *lst, unsigned char n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_octal(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_o_uchar_no_dash2(lst, n, size);
}

void	ft_display_arg_o_uchar_no_dash3(t_type *lst, unsigned char n, int size)
{
	ft_memset_g_set(g_str, ' ', MFW - size);
	if (FLAGS & 1 && g_p--)
		ft_memset_g_set(g_str, '0', 1);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_uchar(t_type *lst, va_list list)
{
	unsigned char		n;
	int					size;

	n = (unsigned char)va_arg(list, int);
	size = ft_strlen_num(n);
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_display_arg_o_uchar_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_display_arg_o_uchar_no_dash(lst, n, size);
		else if ((MFW < size || MFW == 0) && PMFW > size)
			ft_display_arg_o_uchar_no_dash2(lst, n, size);
		else if (MFW > size && (PMFW < size || PMFW == 0))
			ft_display_arg_o_uchar_no_dash3(lst, n, size);
		else if ((MFW < size || MFW == 0) && (PMFW < size || PMFW == 0))
		{
			if (FLAGS & 1)
				ft_memset_g_set(g_str, '0', 1);
			ft_putstr_octal(n);
		}
	}
}
