/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:44:20 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/08 07:55:17 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_s_no_dash(t_type *lst, char *s, int size)
{
	if (MFW > 0)
	{
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW - size);
		else
			ft_memset_g_set(g_str, ' ', MFW - size);
		ft_memcpy_g(g_str, s, size);
	}
	else
		ft_memcpy_g(g_str, s, size);
}

void		ft_display_arg_s(t_type *lst, va_list list)
{
	char	*s;
	int		size;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		ft_memcpy_g(g_str, "(null)", 6);
		return ;
	}
	if ((size = ft_strlen(s)) && size > PMFW && PMFW)
		size = PMFW;
	ft_size(lst, size);
	if (FLAGS & 2)
	{
		ft_memcpy_g(g_str, s, size);
		if (MFW > 0)
			ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
		ft_display_arg_s_no_dash(lst, s, size);
}

void		ft_display_arg_c(t_type *lst, va_list list)
{
	int		s;

	s = va_arg(list, int);
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_memset_g_set(g_str, s, 1);
		if (MFW > 1)
			ft_memset_g_set(g_str, ' ', MFW - 1);
	}
	else
	{
		if (MFW > 1)
		{
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW - 1);
			else
				ft_memset_g_set(g_str, ' ', MFW - 1);
			ft_memset_g_set(g_str, s, 1);
		}
		else
			ft_memset_g_set(g_str, s, 1);
	}
}

void		ft_display_arg_pur(t_type *lst)
{
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_memset_g_set(g_str, '%', 1);
		if (MFW > 1)
			ft_memset_g_set(g_str, ' ', MFW - 1);
	}
	else
	{
		if (MFW > 1)
		{
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW - 1);
			else
				ft_memset_g_set(g_str, ' ', MFW - 1);
			ft_memset_g_set(g_str, '%', 1);
		}
		else
			ft_memset_g_set(g_str, '%', 1);
	}
}
