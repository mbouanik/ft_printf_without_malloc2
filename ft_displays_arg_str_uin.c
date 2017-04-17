/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displays_arg_str_uin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:22:23 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/17 10:57:01 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_c_uni(t_type *lst, va_list list)
{
	wchar_t		s;
	long  n;

	n = 14712960;
	s = va_arg(list, wchar_t);
	SIZE = ft_strlen_b(s);
	s >>= 3;
	n |= s;
	printf("%d\n", SIZE);
	printf("%lx\n", n);
	ft_putstr_hexa(n);
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_memset_g(g_str, s, 1);
		if (MFW > 1)
			ft_memset_g(g_str, ' ', MFW - 1);
	}
	else
	{
		if (MFW > 1)
		{
			if (FLAGS & 4)
				ft_memset_g(g_str, '0', MFW - 1);
			else
				ft_memset_g(g_str, ' ', MFW - 1);
			ft_memset_g(g_str, s, 1);
		}
		else
			ft_memset_g(g_str, s, 1);
	}
}
