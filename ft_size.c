/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 06:52:06 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/07 21:09:55 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_size(t_type *lst, int size)
{
	if (g_p + size > BUFF_SIZE || g_p + MFW > BUFF_SIZE ||
		g_p + PMFW > BUFF_SIZE)
	{
		ft_putstr(g_str);
		g_size += g_p;
		ft_memset_g_set_zero(&g_str[0], 0, BUFF_SIZE);
		g_p = 0;
	}
}

void		ft_size_s(void)
{
	ft_putstr(g_str);
	g_size += g_p;
	ft_memset(&g_str[0], 0, BUFF_SIZE);
	g_p = 0;
}
