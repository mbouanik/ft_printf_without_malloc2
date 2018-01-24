/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_g.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:57:29 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/24 20:31:24 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_g_dash(t_type *lst, double n)
{
	if (MFW > PMFWG && MFW && PMFWG)
	{
		--MFW;
		ft_display_mfw(lst);
		if (FLAGS & 1 && n >= 0)
			--MFW;
		ft_memset_g_set(g_str, ' ', MFW - PMFWG);
		ft_flags_sign(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_g(n, lst);
		ft_memset_g_set(g_str, '0', PMFWG - SIZE + 1);
	}
	else
	{
		ft_flags_sign(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_g(n, lst);
		if ((FLAGS & 1) && PMFWG)
			ft_memset_g_set(g_str, '0', PMFWG - SIZE + 1);
		else if (MFW > SIZE)
		{
			ft_display_mfw(lst);
			ft_memset_g_set(g_str, ' ', MFW - SIZE);
		}
	}
}

void		ft_display_arg_g_no_dash(t_type *lst, double n)
{
	if (n < 0 || FLAGS & 16)
		MFW--;
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
		if (n < 0 || FLAGS & 16)
			ft_flags_sign(lst, n);
		ft_display_mfw(lst);
	}
}

void		ft_display_arg_g_no_dash3(t_type *lst, double n)
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

void		ft_display_arg_g(t_type *lst, va_list list)
{
	double		n;

	n = va_arg(list, double);
	ft_check_size_g(lst, n);
	if (FLAGS & 2 || (FLAGS & 1 && PMFWG))
		ft_display_arg_g_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW)
			ft_display_arg_g_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_g_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_g_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			ft_flags_sign_float(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_g(n, lst);
	}
}
