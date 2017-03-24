/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:44:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 07:46:46 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_d_dash(t_type *lst, int n, int size)
{
	if ((FLAGS & 16 || FLAGS & 20) && n > 0)
		ft_memset(&g_str[g_p++], '+', 1);
	if (MFW > size && PMFW > size)
	{
		ft_memset(&g_str[g_p], '0', PMFW - size);
		ft_itostr(n);
		ft_memset(&g_str[g_p + PMFW], ' ', MFW - PMFW);
	}
	else if (MFW < size && PMFW > size)
	{
		ft_memset(&g_str[g_p], '0', PMFW - size);
		ft_itostr(n);
	}
	else if (MFW > size && PMFW < size)
	{
		if (FLAGS & 16)
			MFW--;
		ft_itostr(n);
		ft_memset(&g_str[g_p], ' ', MFW - size);
		g_p += MFW - size;
	}
}

void		ft_display_arg_d_no_dash2(t_type *lst, int n, int size)
{
	if (n < 0 || FLAGS & 16 || FLAGS & 8)
	{
		if ((FLAGS & 16) && n > 0)
			ft_memset(&g_str[g_p++], '+', 1);
		else if (n < 0)
			ft_memset(&g_str[g_p++], '-', 1);
		else if (FLAGS & 8 && n > 0)
			ft_memset(&g_str[g_p++], ' ', 1);
	}
	ft_memset(&g_str[g_p], '0', PMFW - size);
	g_p += PMFW - size;
	ft_itostr(n);
}

void		ft_display_arg_d_no_dash(t_type *lst, int n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset(&g_str[g_p], ' ', MFW - PMFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n > 0)
				ft_memset(&g_str[g_p + (MFW - PMFW - 1)], '+', 1);
			else
				ft_memset(&g_str[g_p + (MFW - PMFW - 1)], '-', 1);
		}
		ft_memset(&g_str[g_p + (MFW - PMFW)], '0', PMFW - size);
		g_p += MFW - size;
		ft_itostr(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_d_no_dash2(lst, n, size);
}

void		ft_display_arg_d_no_dash3(t_type *lst, int n, int size)
{
	if (FLAGS & 4)
	{
		if (n < 0 || FLAGS & 16 || FLAGS & 8)
		{
			if (FLAGS & 16 && n < 0 && size++)
				ft_memset(&g_str[g_p++], '+', 1);
			else if (FLAGS & 8 && n > 0 && size++)
				ft_memset(&g_str[g_p++], ' ', 1);
			else
				ft_memset(&g_str[g_p++], '-', 1);
		}
		ft_memset(&g_str[g_p], '0', MFW - size);
	}
	else
	{
		ft_memset(&g_str[g_p], ' ', MFW);
		if (FLAGS & 16 && n > 0)
			ft_memset(&g_str[g_p + (MFW - size - 1)], '+', 1);
		if (n < 0)
			ft_memset(&g_str[g_p + (MFW - size - 1)], '-', 1);
		g_p += MFW - size;
	}
	ft_itostr(n);
}

void		ft_display_arg_d(t_type *lst, va_list list)
{
	int n;
	int size;

	n = va_arg(list, int);
	size = ft_strlen_num(n);
	if (FLAGS & 2)
		ft_display_arg_d_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_display_arg_d_no_dash(lst, n, size);
		else if ((MFW < size || MFW == 0) && PMFW > size)
			ft_display_arg_d_no_dash2(lst, n, size);
		else if (MFW > size && (PMFW < size || PMFW == 0))
			ft_display_arg_d_no_dash3(lst, n, size);
		else if ((MFW < size || MFW == 0) && (PMFW < size || PMFW == 0))
		{
			if ((FLAGS & 16 || FLAGS & 8) || n < 0)
			{
				if (FLAGS & 16 && n > 0)
					ft_memset(&g_str[g_p++], '+', 1);
				else if (FLAGS & 8 && n > 0)
					ft_memset(&g_str[g_p++], ' ', 1);
				else if (n < 0)
					ft_memset(&g_str[g_p++], '-', 1);
			}
			ft_itostr(n);
		}
	}
}
