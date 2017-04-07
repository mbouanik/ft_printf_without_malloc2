/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:22:13 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/29 13:23:45 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_x_assign(uintmax_t n)
{
	if (n)
		ft_putstr_x_assign(n / 16);
	if (n && (n % 16) <= 9)
		g_str[g_p++] = (n % 16) + 48;
	if ((n % 16) > 9)
		g_str[g_p++] = (n % 16) + 55;
}

void			ft_putstr_x(uintmax_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_x_assign(n);
}
