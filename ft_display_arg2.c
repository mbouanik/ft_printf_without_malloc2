/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:19:40 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:30:52 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_u_dash(t_type *lst, unsigned int n, int size)
{
	if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_itoustr(n);
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
	}
	else if ((MFW < size && PMFW > size) || PMFW > MFW || PMFW == MFW)
	{
		ft_memset_g_set(g_str, '0', PMFW - size);
		ft_itoustr(n);
	}
	else if (MFW > size && PMFW < size)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
		ft_memset_g_set(g_str, ' ', MFW - size);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
	}
}

void		ft_display_arg_u_no_dash2(t_type *lst, unsigned int n, int size)
{
	ft_memset_g_set(g_str, '0', PMFW - size);
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_itoustr(n);
}

void		ft_display_arg_u_no_dash(t_type *lst, unsigned int n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g_set(g_str, ' ', MFW - PMFW);
		ft_memset_g_set(g_str, '0', PMFW - size);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_u_no_dash2(lst, n, size);
}

void		ft_display_arg_u_no_dash3(t_type *lst, unsigned int n, int size)
{
	if (FLAGS & 4)
		ft_memset_g_set(g_str, '0', MFW - size);
	else
		ft_memset_g_set(g_str, ' ', MFW - size);
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_itoustr(n);
}

void		ft_display_arg_u(t_type *lst, va_list list)
{
	unsigned int	n;
	int				size;

	if (MOD)
	{
		ft_display_arg_u_mod(lst, list);
		return ;
	}
	n = va_arg(list, unsigned int);
	size = ft_strlen_num(n);
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_display_arg_u_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_display_arg_u_no_dash(lst, n, size);
		else if ((MFW <= size || MFW == 0) && PMFW >= size)
			ft_display_arg_u_no_dash2(lst, n, size);
		else if (MFW >= size && (PMFW <= size || PMFW == 0))
			ft_display_arg_u_no_dash3(lst, n, size);
		else if ((MFW <= size || MFW == 0) && (PMFW <= size || PMFW == 0))
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_itoustr(n);
	}
}
