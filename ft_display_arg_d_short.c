/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d_short.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:18:08 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/04 07:01:49 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_d_short_dash(t_type *lst, short n, int size)
{
	if ((FLAGS & 16 || FLAGS & 20) && n > 0)
		ft_memset_g(g_str, '+', 1);
	if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g(g_str, '0', PMFW - size);
		ft_itostr(n);
		ft_memset_g(g_str, ' ', MFW - PMFW);
	}
	else if ((MFW < size && PMFW > size) || PMFW > MFW || PMFW == MFW)
	{
		ft_memset_g(g_str, '0', PMFW - size);
		ft_itostr(n);
	}
	else if (MFW > size && PMFW < size)
	{
		if (FLAGS & 16)
			MFW--;
		ft_itostr(n);
		ft_memset_g(g_str, ' ', MFW - size);
	}
	else
		ft_itostr(n);
}

void		ft_display_arg_d_short_no_dash2(t_type *lst, short n, int size)
{
	if (n < 0 || FLAGS & 16 || FLAGS & 8)
	{
		if ((FLAGS & 16) && n > 0)
			ft_memset_g(g_str, '+', 1);
		else if (n < 0)
			ft_memset_g(g_str, '-', 1);
		else if (FLAGS & 8 && n > 0)
			ft_memset_g(g_str, ' ', 1);
	}
	ft_memset_g(g_str, '0', PMFW - size);
	ft_itostr(n);
}

void		ft_display_arg_d_short_no_dash(t_type *lst, short n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g(g_str, ' ', MFW - PMFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n > 0)
				ft_memset_g(g_str, '+', 1);
			else
				ft_memset_g(g_str, '-', 1);
		}
		ft_memset_g(g_str, '0', PMFW - size);
		ft_itostr(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_d_short_no_dash2(lst, n, size);
}

void		ft_display_arg_d_short_no_dash3(t_type *lst, short n, int size)
{
	if (FLAGS & 4)
	{
		if (n < 0 || FLAGS & 16 || FLAGS & 8)
		{
			if (FLAGS & 16 && n < 0 && size++)
				ft_memset_g(g_str, '+', 1);
			else if (FLAGS & 8 && n > 0 && size++)
				ft_memset_g(g_str, ' ', 1);
			else
				ft_memset_g(g_str, '-', 1);
		}
		ft_memset_g(g_str, '0', MFW - size);
	}
	else
	{
		ft_memset_g(g_str, ' ', MFW - size);
		if (FLAGS & 16 && n > 0)
			ft_memset_g(g_str, '+', 1);
		if (n < 0)
			ft_memset_g(g_str, '-', 1);
	}
	ft_itostr(n);
}

void		ft_display_arg_d_short(t_type *lst, va_list list)
{
	short	n;
	int		size;

	n = (short)va_arg(list, int);
	size = ft_strlen_num(n);
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_display_arg_d_short_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_display_arg_d_short_no_dash(lst, n, size);
		else if ((MFW < size || MFW == 0) && PMFW > size)
			ft_display_arg_d_short_no_dash2(lst, n, size);
		else if (MFW > size && (PMFW < size || PMFW == 0))
			ft_display_arg_d_short_no_dash3(lst, n, size);
		else if ((MFW < size || MFW == 0) && (PMFW < size || PMFW == 0))
		{
			if ((FLAGS & 16 || FLAGS & 8) || n < 0)
				ft_flags_sign(lst, n);
			ft_itostr(n);
		}
	}
}
