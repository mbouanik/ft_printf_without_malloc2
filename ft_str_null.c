/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:19:41 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/23 15:24:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_str_null_no_dash(t_type *lst, int size)
{
	if (MFW > size)
	{
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW - size);
		else
			ft_memset_g_set(g_str, ' ', MFW - size);
		if (PMFW != -1)
			ft_memcpy_g(g_str, "(null)", size);
	}
	else
	{
		if (PMFW != -1)
			ft_memcpy_g(g_str, "(null)", size);
	}
}

void		ft_str_null(t_type *lst)
{
	if ((SIZE = 6) && SIZE > PMFW && PMFW > 0)
		SIZE = PMFW;
	if (PMFW == -1)
		SIZE = 0;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
	{
		if (PMFW != -1)
			ft_memcpy_g(g_str, "(null)", SIZE);
		if (MFW > 0)
			ft_memset_g_set(g_str, ' ', MFW - SIZE);
	}
	else
		ft_str_null_no_dash(lst, SIZE);
}
