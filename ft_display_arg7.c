/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:21:46 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/17 14:57:48 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_b_dash(t_type *lst, long long n, int size)
{
	if (PMFW > size && PMFW >= size)
		ft_memset_g_set(g_str, '0', PMFW - size);
	ft_putstr_b(n);
	ft_display_mfw(lst);
	if (MFW > size && PMFW > size)
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	else
		ft_memset_g_set(g_str, ' ', MFW - size);
}

void		ft_display_arg_b(t_type *lst, va_list list)
{
	long long	n;
	int			size;

	n = va_arg(list, long long);
	size = ft_strlen_b(n);
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_display_arg_b_dash(lst, n, size);
	else
	{
		ft_display_mfw(lst);
		if (MFW > size && PMFW > size)
		{
			if (PMFW > size)
				ft_memset_g_set(g_str, ' ', MFW - PMFW);
			else
				ft_memset_g_set(g_str, ' ', MFW - size);
			ft_memset_g_set(g_str, '0', PMFW - size);
		}
		else if ((MFW <= size || MFW == 0) && PMFW >= size)
			ft_memset_g_set(g_str, '0', PMFW - size);
		else if (MFW >= size && (PMFW == 0 || MFW <= size))
			ft_memset_g_set(g_str, ' ', MFW - size);
		ft_putstr_b(n);
	}
}
