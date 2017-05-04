/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 06:24:05 by mbouanik          #+#    #+#             */
/*   Updated: 2017/05/01 18:52:51 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_num;

static void		ft_assign_num(long n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
	{
		if (n % 10 == 0)
			g_num += 1;
		else
			g_num = 0;
		g_str[g_p++] = n % 10 + 48;
	}
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

	g_num = 0;
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
	neg = 0;
	ft_assign_num(n);
}

void			ft_longtoa_g(long n)
{
	int		neg;

	g_num = 0;
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
	neg = 0;
	ft_assign_num(n);
	g_p = g_p - g_num;
}
