/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:21:06 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 06:10:53 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_assign_num(int n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + '0';
}

static void		ft_sign(int *n, int *s)
{
	if (*n < 0)
	{
		*s = 1;
		*n *= -1;
	}
}

void			ft_itostr(int n)
{
	int		neg;

	neg = 0;
	// if (n == -2147483648)
	// 	return (ft_strdup("-2147483648"));
	// if (n == 0)
	// 	return (ft_strdup("0"));
	ft_sign(&n, &neg);
	// if (neg)
	// {
	// 	g_str[g_p++] = '-';
	//
	// 	ft_assign_num(n);
	// }
	// else
		ft_assign_num(n);
}

void ft_itoustr(unsigned int n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + '0';
}
