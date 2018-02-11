/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:38:26 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/11 15:48:38 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_f_dash(t_type *lst, double n)
{
	ft_flags_sign(lst, n);
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - SIZE);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float(n, lst);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - SIZE);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float(n, lst);
	}
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float(n, lst);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float(n, lst);
}

void		ft_display_arg_f_no_dash2(t_type *lst, double n)
{
	ft_flags_sign(lst, n);
	ft_memset_g_set(g_str, '0', PMFW - SIZE);
}

void		ft_display_arg_f_no_dash(t_type *lst, double n)
{
	if (MFW > PMFW)
	{
		if (n < 0 || FLAGS & 16)
			MFW--;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n >= 0)
				ft_memset_g_set(g_str, '+', 1);
			else
				ft_memset_g_set(g_str, '-', 1);
		}
		ft_memset_g_set(g_str, '0', PMFW - SIZE);
	}
	else if (PMFW >= MFW)
		ft_display_arg_f_no_dash2(lst, n);
}

void		ft_display_arg_f_no_dash3(t_type *lst, double n)
{
	if (FLAGS & 4)
	{
		ft_flags_sign(lst, n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW - SIZE);
	}
	else
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
		if (FLAGS & 16 && n >= 0 && --g_p)
			ft_memset_g_set(g_str, '+', 1);
		if (n < 0 && --g_p)
			ft_memset_g_set(g_str, '-', 1);
	}
}

void		ft_display_arg_f(t_type *lst, va_list list)
{
	long double		n;

	n = (long double)va_arg(list, double);
	ft_check_size_f(lst, n);
	if (FLAGS & 2)
		ft_display_arg_f_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_f_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_f_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_f_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			ft_flags_sign_float(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float(n, lst);
	}
}
