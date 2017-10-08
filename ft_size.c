/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 06:52:06 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/30 18:16:40 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_size(t_type *lst, int size)
{
	if (g_p + size >= BUFF_SIZE || g_p + MFW >= BUFF_SIZE ||
		g_p + PMFW >= BUFF_SIZE)
	{
		ft_putstr_g(g_str);
		g_size += g_p;
		g_p = 0;
	}
}

void		ft_size_s(void)
{
	ft_putstr_g(g_str);
	g_size += g_p;
	g_p = 0;
}

void		ft_check_size(t_type *lst, int n)
{
	if ((SIZE = ft_strlen_num(n)) && PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_o(t_type *lst, long int n)
{
	if ((SIZE = ft_strlen_o(n)) && PMFW == -1 && n == 0 && !(FLAGS & 1))
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_hexa(t_type *lst, uint64_t n)
{
	if ((SIZE = ft_strlen_hexa(n)) && PMFW == -1 && n == 0 && !(FLAGS & 1))
		SIZE = 0;
	ft_size(lst, SIZE);
}
