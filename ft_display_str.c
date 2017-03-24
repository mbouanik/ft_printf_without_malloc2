/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:44:20 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 07:44:25 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_s(t_type *lst, va_list list)
{
	char	*s;
	int		size;

	s = va_arg(list, char *);
	size = ft_strlen(s);
	if (size > PMFW && PMFW > 0)
		size = PMFW;
	if (FLAGS & 2)
	{
		ft_memcpy(&g_str[g_p], s, size);
		g_p += size;
		if (MFW > 0)
			ft_memset(&g_str[g_p], ' ', MFW - size);
		g_p += MFW - size;
	}
	else
	{
		if (MFW > 0)
		{
			if (FLAGS & 4)
				ft_memset(&g_str[g_p], '0', MFW - size);
			else
				ft_memset(&g_str[g_p], ' ', MFW - size);
			ft_memcpy(&g_str[g_p + MFW - size], s, size);
			g_p += MFW;
		}
		else
		{
			ft_memcpy(&g_str[g_p], s, size);
			g_p += size;
		}
	}
}

void		ft_display_arg_c(t_type *lst, va_list list)
{
	int		s;

	s = va_arg(list, int);
	if (FLAGS & 2)
	{
		ft_memset(&g_str[g_p++], s, 1);
		if (MFW > 1)
			ft_memset(&g_str[g_p], ' ', MFW - 1);
		g_p += MFW - 1;
	}
	else
	{
		if (MFW > 1)
		{
			if (FLAGS & 4)
				ft_memset(&g_str[g_p], '0', MFW - 1);
			else
				ft_memset(&g_str[g_p], ' ', MFW - 1);
			ft_memset(&g_str[g_p + (MFW - 1)], s, 1);
			g_p += MFW;
		}
		else
			ft_memset(&g_str[g_p++], s, 1);
	}
}
