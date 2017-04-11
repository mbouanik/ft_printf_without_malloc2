/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_lo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:15:19 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/10 19:27:05 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_lo_assign(uint64_t n)
{
	if (n > 0)
		ft_putstr_lo_assign(n / 8);
	if (n > 0)
		g_str[g_p++] = n % 8 + '0';
}

void			ft_putstr_lo(uint64_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_lo_assign(n);
}
