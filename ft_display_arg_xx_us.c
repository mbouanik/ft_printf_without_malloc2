/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_xx_us.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:48:36 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/04 07:04:07 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_xx_us_dash(t_type *lst, unsigned short n, int size)
{
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0x", 2);
	if (PMFW > size && (PMFW > MFW || PMFW == MFW))
	{
		ft_memset_g(g_str, '0', PMFW - size);
		ft_putstr_x(n);
	}
	else if (MFW > size && PMFW > size && PMFW < MFW)
	{
		ft_putstr_x(n);
		ft_memset_g(g_str, ' ', MFW - PMFW);
	}
	else if (MFW > size && (PMFW < size || PMFW == 0))
	{
		ft_putstr_x(n);
		ft_memset_g(g_str, ' ', MFW - size);
	}
	else
		ft_putstr_x(n);
}

void	ft_display_arg_xx_us_no_dash2(t_type *lst, unsigned short n, int size)
{
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0x", 2);
	ft_memset_g(g_str, '0', PMFW - size);
}

void	ft_display_arg_xx_us_no_dash(t_type *lst, unsigned short n, int size)
{
	if (MFW > PMFW)
	{
		ft_memset_g(g_str, ' ', MFW - PMFW);
		if (FLAGS & 4)
			ft_memset_g(g_str, '0', PMFW - size);
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0x", 2);
	}
	else
		ft_display_arg_xx_us_no_dash2(lst, n, size);
}

void	ft_display_arg_xx_us_no_dash3(t_type *lst, unsigned short n, int size)
{
	if (FLAGS & 4)
		ft_memset_g(g_str, '0', MFW - size);
	else
		ft_memset_g(g_str, ' ', MFW - size);
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0x", 2);
}

void	ft_display_arg_xx_us(t_type *lst, va_list list)
{
	unsigned char	n;
	int				size;

	n = (unsigned short)va_arg(list, int);
	size = ft_strlen_hexa(n);
	ft_size(lst, size);
	if (FLAGS & 1 && MFW >= 2)
		MFW -= 2;
	if (FLAGS & 2)
		ft_display_arg_xx_us_dash(lst, n, size);
	else
	{
		if (MFW > size && PMFW > size)
			ft_display_arg_xx_us_no_dash(lst, n, size);
		else if (((MFW < size || MFW == 0) && PMFW > size))
			ft_display_arg_xx_us_no_dash2(lst, n, size);
		else if (MFW > size && (PMFW < size || PMFW == 0))
			ft_display_arg_xx_us_no_dash3(lst, n, size);
		else if ((MFW < size || MFW == 0) && (PMFW < size || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memcpy_g(g_str, "0x", 2);
		ft_putstr_x(n);
	}
}
