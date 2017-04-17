/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:14:24 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/15 00:16:05 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_hexa_assign(uintmax_t n)
{
	if (n)
		ft_putstr_hexa_assign(n / 16);
	if (n && (n % 16) <= 9)
		g_str[g_p++] = (n % 16) + 48;
	if ((n % 16) > 9)
		g_str[g_p++] = (n % 16) + 87;
}

void			ft_putstr_hexa(uintmax_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_hexa_assign(n);
}
