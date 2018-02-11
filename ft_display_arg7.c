/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:21:46 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/11 11:33:53 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_b_dash(t_type *lst, long long n)
{
	if (PMFW > SIZE && PMFW >= SIZE)
	{
		ft_display_pmfw(lst);
		ft_memset_g_set(g_str, '0', PMFW - SIZE);
	}
	ft_putstr_b(n);
	ft_display_mfw(lst);
	if (MFW > SIZE && PMFW > SIZE)
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	else
		ft_memset_g_set(g_str, ' ', MFW - SIZE);
}

void		ft_display_arg_b(t_type *lst, va_list list)
{
	long long	n;

	n = va_arg(list, long long);
	SIZE = ft_strlen_b(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_b_dash(lst, n);
	else
	{
		ft_display_mfw(lst);
		if (MFW > SIZE && PMFW > SIZE)
		{
			if (PMFW > SIZE)
				ft_memset_g_set(g_str, ' ', MFW - PMFW);
			else
				ft_memset_g_set(g_str, ' ', MFW - SIZE);
			ft_display_pmfw(lst);
			ft_memset_g_set(g_str, '0', PMFW - SIZE);
		}
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_memset_g_set(g_str, '0', PMFW - SIZE);
		else if (MFW >= SIZE && (PMFW == 0 || MFW <= SIZE))
			ft_memset_g_set(g_str, ' ', MFW - SIZE);
		ft_putstr_b(n);
	}
}
