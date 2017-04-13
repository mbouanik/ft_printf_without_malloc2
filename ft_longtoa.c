/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 06:24:05 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:15:00 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_assign_num(long n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + '0';
}

static void		ft_sign(long *n, int *s)
{
	if (*n < 0)
	{
		*s = 1;
		*n *= -1;
	}
}

void			ft_longtoa(long n)
{
	int		neg;

	if (n < -9223372036854775807)
	{
		ft_memcpy_g(g_str, "9223372036854775808", 19);
		return ;
	}
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	neg = 0;
	ft_sign(&n, &neg);
	ft_assign_num(n);
}
