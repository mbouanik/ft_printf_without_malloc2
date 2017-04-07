/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:21:06 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/05 18:09:02 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_assign_num(intmax_t n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + '0';
}

static void		ft_sign(intmax_t *n, int *s)
{
	if (*n < 0)
	{
		*s = 1;
		*n *= -1;
	}
}

void			ft_itostr(intmax_t n)
{
	int		neg;

	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	neg = 0;
	ft_sign(&n, &neg);
	ft_assign_num(n);
}
