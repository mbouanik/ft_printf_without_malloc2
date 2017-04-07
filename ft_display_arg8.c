/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:34:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/06 20:26:37 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_p_dash(t_type *lst, unsigned long long int n, int size)
{
	MFW -= 2;
	ft_memcpy_g(g_str, "0x", 2);
	if ((MFW >= size && PMFW >= size) || PMFW >= MFW)
	{
		ft_memset_g(g_str, '0', PMFW - size);
		ft_putstr_hexa(n);
	}
	else if (MFW > size && (PMFW < size || PMFW == 0))
	{
		ft_putstr_hexa(n);
		ft_memset_g(g_str, ' ', MFW - size);
	}
}

void	ft_display_p_no_dash2(t_type *lst, unsigned long long int n, int size)
{
	ft_memcpy_g(g_str, "0x", 2);
	ft_memset_g(g_str, '0', PMFW - size);
	ft_putstr_hexa(n);
}

void	ft_display_p_no_dash(t_type *lst, unsigned long long int n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g(g_str, ' ', MFW - PMFW);
		ft_memcpy_g(g_str, "0x", 2);
		ft_memset_g(g_str, '0', PMFW - size);
		ft_putstr_hexa(n);
	}
	else
		ft_display_p_no_dash2(lst, n, size);
}

void	ft_display_p_no_dash3(t_type *lst, unsigned long long int n, int size)
{
	if (FLAGS & 4 && PMFW == 0)
	{
		ft_memcpy_g(g_str, "0x", 2);
		ft_memset_g(g_str, '0', MFW - size);
	}
	else
	{
		ft_memset_g(g_str, ' ', MFW - size);
		ft_memcpy_g(g_str, "0x", 2);
	}
	ft_putstr_hexa(n);
}

void	ft_display_arg_p(t_type *lst, va_list list)
{
	unsigned long long int	n;
	int						size;

	n = va_arg(list, unsigned long long int);
	size = ft_strlen_hexa(n);
	ft_size(lst, size);
	if (FLAGS & 2)
		ft_display_p_dash(lst, n, size);
	else
	{
		if (MFW >= size && PMFW >= size && (MFW -= 2))
			ft_display_p_no_dash(lst, n, size);
		else if ((MFW <= size || MFW == 0) && PMFW >= size)
			ft_display_p_no_dash2(lst, n, size);
		else if (MFW >= size && (PMFW <= size || PMFW == 0) && (MFW -= 2))
			ft_display_p_no_dash3(lst, n, size);
		else if ((MFW <= size || MFW == 0) && (PMFW <= size || PMFW == 0))
		{
			ft_memcpy_g(g_str, "0x", 2);
			ft_putstr_hexa(n);
		}
	}
}
