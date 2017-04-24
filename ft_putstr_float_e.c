/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:17:20 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/24 00:30:35 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_assign(double n, t_type *lst)
{
	long	i;
	double	size;

	size = 1;
	ft_longtoa((long)n);
	if (PMFW == -1)
		return ;
	ft_memset_g(g_str, '.', 1);
	n = n - (long)n;
	i = PMFW + 1;
	while (i-- > 0)
		size /= 10;
	if (n > 0)
		n += size;
	else
		n -= size;
	while (PMFW-- > 0)
	{
		n *= 10;
		ft_longtoa((long)n);
		n = n - (long)n;
	}
}

void		ft_e(t_type *lst, int e, int a)
{
	ft_memset_g(g_str, lst->arg_type, 1);
	if (a)
		ft_memset_g(g_str, '-', 1);
	else
		ft_memset_g(g_str, '+', 1);
	if (e < 10)
		ft_memset_g(g_str, '0', 1);
	ft_longtoa((long)e);
}

void		ft_putstr_float_e(double n, t_type *lst)
{
	int		e;
	int		a;

	a = 0;
	e = 0;
	if (n < 0)
		n *= -1;
	if (n < 1)
		a = 1;
	if (!a)
	{
		while (n > 0.9 && ++e)
			n /= 10;
		e -= 1;
		n *= 10;
	}
	else
	{
		while (n < 0.9)
		{
			n *= 10;
			e++;
		}
	}
	ft_assign(n, lst);
	ft_e(lst, e, a);
}
