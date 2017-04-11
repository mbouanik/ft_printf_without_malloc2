/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 07:59:51 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/11 02:37:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_o_dash(t_type *lst, unsigned int n, int size)
{
	if ((FLAGS & 1 && n && --MFW) || (FLAGS & 1 && PMFW == -1 && !(n)))
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
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_octal(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_octal(n);
	}
}

void		ft_display_arg_o_no_dash2(t_type *lst, unsigned int n, int size)
{
	ft_memset_g_set(g_str, '0', PMFW - size);
	ft_putstr_octal(n);
}

void		ft_display_arg_o_no_dash(t_type *lst, unsigned int n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_octal(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_o_no_dash2(lst, n, size);
}

void		ft_display_arg_o_no_dash3(t_type *lst, unsigned int n, int size)
{
	if (FLAGS & 4)
		ft_memset_g_set(g_str, '0', MFW - size);
	else
		ft_memset_g_set(g_str, ' ', MFW - size);
	if (FLAGS & 1 && n && g_p--)
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW == -1 && n == 0 && (FLAGS & 1) == 0)
		return ;
	ft_putstr_octal(n);
}

void		ft_display_arg_o(t_type *lst, va_list list)
{
	unsigned int		n;
	int					size;

	n = va_arg(list, unsigned int);
	if ((size = ft_strlen_o(n)) && PMFW == -1 && n == 0 && !(FLAGS & 1))
		size = 0;
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_display_arg_o_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_display_arg_o_no_dash(lst, n, size);
		else if ((MFW < size || MFW == 0) && PMFW > size)
			ft_display_arg_o_no_dash2(lst, n, size);
		else if (MFW > size && (PMFW < size || PMFW == 0))
			ft_display_arg_o_no_dash3(lst, n, size);
		else if ((MFW < size || MFW == 0) && (PMFW < size || PMFW == 0))
		{
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
			if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
				ft_putstr_octal(n);
		}
	}
}
