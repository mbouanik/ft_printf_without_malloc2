/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:21:06 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 08:18:21 by mbouanik         ###   ########.fr       */
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
	ft_sign(&n, &neg);
	ft_assign_num(n);
}

void		ft_itoustr(unsigned int n)
{
	if (n > 0)
		ft_itoustr(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + '0';
}

void		ft_putstr_octal(long long n)
{
	if (n > 0)
		ft_putstr_octal(n / 8);
	if (n > 0)
		g_str[g_p++] = n % 8 + '0';
}
