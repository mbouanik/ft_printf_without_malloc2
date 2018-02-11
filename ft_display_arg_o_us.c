/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_o_us.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:25:09 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/11 09:31:05 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_o_us_no_dash2(t_type *lst, unsigned short n)
{
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW - SIZE);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_us_dash(t_type *lst, unsigned short n)
{
	if (FLAGS & 1 && n && --MFW)
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
		ft_display_arg_o_us_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_o_us_no_dash2(lst, n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_octal(n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_octal(n);
}

void	ft_display_arg_o_us_no_dash(t_type *lst, unsigned short n)
{
	if (MFW > PMFW)
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_display_arg_o_us_no_dash2(lst, n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_o_us_no_dash2(lst, n);
}

void	ft_display_arg_o_us_no_dash3(t_type *lst, unsigned short n)
{
	ft_display_mfw(lst);
	if (FLAGS & 4 && PMFW != -1)
		ft_memset_g_set(g_str, '0', MFW - SIZE);
	else
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
	if (FLAGS & 1 && g_p--)
		ft_memset_g_set(g_str, '0', 1);
	if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
		ft_putstr_octal(n);
}

void	ft_display_arg_o_us(t_type *lst, va_list list)
{
	unsigned short		n;

	n = (unsigned short)va_arg(list, unsigned int);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_o_us_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_o_us_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_o_us_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_o_us_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
			if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
				ft_putstr_octal(n);
		}
	}
}
