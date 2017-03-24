/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:44:20 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 11:06:44 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_s(t_type *lst, va_list list)
{
	char	*s;
	int		size;

	s = va_arg(list, char *);
	if ((size = ft_strlen(s)) && size > PMFW && PMFW > 0)
		size = PMFW;
	if (FLAGS & 2)
	{
		ft_memcpy_g(g_str, s, size);
		if (MFW > 0)
			ft_memset_g(g_str, ' ', MFW - size);
	}
	else
	{
		if (MFW > 0)
		{
			if (FLAGS & 4)
				ft_memset_g(g_str, '0', MFW - size);
			else
				ft_memset_g(g_str, ' ', MFW - size);
			ft_memcpy_g(g_str, s, size);
		}
		else
			ft_memcpy_g(g_str, s, size);
	}
}

void		ft_display_arg_c(t_type *lst, va_list list)
{
	int		s;

	s = va_arg(list, int);
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
