/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:20:30 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:31:38 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_octal_dash(t_type *lst, long int n, int size)
{
	if (FLAGS & 1 && n && --MFW)
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > size && (PMFW > MFW || PMFW == MFW))
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_lo(n);
	}
	else if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_putstr_lo(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > size && (PMFW < size || PMFW == 0))
	{
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_lo(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
	{
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_lo(n);
	}
}

void		ft_display_arg_octal_no_dash2(t_type *lst, int size)
{
	ft_memset_g_set(g_str, '0', PMFW - size);
}

void		ft_display_arg_octal_no_dash(t_type *lst, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
	}
	else if (PMFW >= MFW)
		ft_display_arg_octal_no_dash2(lst, size);
}

void		ft_display_arg_octal_no_dash3(t_type *lst, long int n, int size)
{
	ft_memset_g_set(g_str, ' ', MFW - size);
	if (FLAGS & 1 && n && g_p--)
		ft_memset_g_set(g_str, '0', 1);
}

void		ft_display_arg_octal(t_type *lst, va_list list)
{
	long int		n;

	if (MOD)
	{
		ft_display_arg_o_mod(lst, list);
		return ;
	}
	n = va_arg(list, long int);
	ft_check_size_o(lst, n);
	if (FLAGS & 2)
		ft_display_arg_octal_dash(lst, n, SIZE);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_octal_no_dash(lst, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_octal_no_dash2(lst, SIZE);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_octal_no_dash3(lst, n, SIZE);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_lo(n);
	}
}
