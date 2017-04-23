/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_uu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:03:57 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/23 01:21:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_uu_dash(t_type *lst, unsigned long n, int size)
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
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
	}
}

void		ft_display_arg_uu_no_dash2(t_type *lst, unsigned long n, int size)
{
	if (FLAGS & 8 && PMFW++ && size++)
		ft_memset_g_set(g_str, ' ', 1);
	ft_memset_g_set(g_str, '0', PMFW - size);
	ft_itoustr(n);
}

void		ft_display_arg_uu_no_dash(t_type *lst, unsigned long n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_itoustr(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_uu_no_dash2(lst, n, size);
}

void		ft_display_arg_uu_no_dash3(t_type *lst, unsigned long n, int size)
{
	if (FLAGS & 4 && PMFW != -1)
	{
		if (FLAGS & 8 && size++)
			ft_memset_g_set(g_str, ' ', 1);
		ft_memset_g_set(g_str, '0', MFW - size);
	}
	else
		ft_memset_g_set(g_str, ' ', MFW - size);
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_itoustr(n);
}

void		ft_display_arg_uu(t_type *lst, va_list list)
{
	unsigned long	n;

	n = va_arg(list, unsigned long);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_uu_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_uu_no_dash(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_uu_no_dash2(lst, n, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_uu_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 8)
				ft_memset_g_set(g_str, ' ', 1);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_itoustr(n);
		}
	}
}
