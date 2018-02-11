/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 07:59:51 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/11 13:32:37 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_o_no_dash2(t_type *lst, unsigned int n)
{
	if ((FLAGS & 2) == 0)
		if ((FLAGS & 1 && n) || (FLAGS & 1 && PMFW == -1 && !(n)))
		{
			if (PMFW > SIZE)
				--PMFW;
			ft_memset_g_set(g_str, '0', 1);
		}
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW - SIZE);
}

void		ft_display_arg_o_dash(t_type *lst, unsigned int n)
{
	if ((FLAGS & 1 && n && --MFW) || (FLAGS & 1 && PMFW == -1 && !(n)))
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
	{
		ft_display_arg_o_no_dash2(lst, n);
		ft_putstr_octal(n);
	}
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_o_no_dash2(lst, n);
		ft_putstr_octal(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW >= SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_octal(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
	}
	else if ((MFW < SIZE || MFW == 0) && (PMFW < SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_octal(n);
}

void		ft_display_arg_o_no_dash(t_type *lst, unsigned int n)
{
	if (MFW > PMFW)
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	ft_display_arg_o_no_dash2(lst, n);
}

void		ft_display_arg_o_no_dash3(t_type *lst, unsigned int n)
{
	ft_display_mfw(lst);
	if (FLAGS & 4 && PMFW != -1)
		ft_memset_g_set(g_str, '0', MFW - SIZE);
	else
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
	if (FLAGS & 1 && n && g_p--)
		ft_memset_g_set(g_str, '0', 1);
}

void		ft_display_arg_o(t_type *lst, va_list list)
{
	unsigned int		n;

	if (MOD)
	{
		ft_display_arg_o_mod(lst, list);
		return ;
	}
	n = va_arg(list, unsigned int);
	ft_check_size_o(lst, n);
	if (FLAGS & 2)
		ft_display_arg_o_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_o_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_o_no_dash2(lst, n);
		else if (MFW > SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_o_no_dash3(lst, n);
		else if ((MFW < SIZE || MFW == 0) && (PMFW < SIZE || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_octal(n);
	}
}
