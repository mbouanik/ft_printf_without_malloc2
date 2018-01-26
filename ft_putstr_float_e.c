/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:17:20 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/26 09:57:07 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_assign(long double n, t_type *lst)
{
	int i;
	long double j;

	i = 0;
	j  = 10;
	if (n < 0)
		n *= -1;
	ft_itoustr((uint64_t)n);
	n = n - (uint64_t)n;
	while (PMFW-- > 0)
	{
		n = (long double)n * 10;
		g_str[g_p++] = (uint64_t)n % 10 + 48;
		n = n - (uint64_t)n;
	}
	ft_round_up(n);
}

void		ft_e(t_type *lst, long e, long a)
{
	if (lst->arg_type == 'e' || lst->arg_type == 'g')
		ft_memset_g(g_str, 'e', 1);
	else
		ft_memset_g(g_str, 'E', 1);
	if (a)
		ft_memset_g(g_str, '-', 1);
	else
		ft_memset_g(g_str, '+', 1);
	if (e < 10)
		ft_memset_g(g_str, '0', 1);
	ft_longtoa((long)e);
}

double		ft_double(long double n, int *e, int *a, uint64_t *k)
{
	if (n < 0.0)
		n *= -1;
	if (n < 1.0)
		*a = 1;
	if (n > 1.0)
	{
		while (n > 0.9 && ++(*e))
		{
			n /= 10;
			*k *= 10;
		}
		*e -= 1;
		n *= 10;
	}
	else
	{
		while (n < 0.9)
		{
			n *= 10;
			(*e)++;
		}
	}
	return (n);
}

void		ft_assign_e(long double n, long double j, int e, t_type *lst)
{
	if (j < 0)
		j *= -1;
	if (PMFW >= (uint64_t)ft_strlen_num((uint64_t)j))
	{
		if (e == 0)
			j *= 10;
		PMFW -= (uint64_t)ft_strlen_num((uint64_t)j);
		while ((uint64_t)j % 10 == 0)
			j *= 10;
		j = (long double)j - (uint64_t)j;
		ft_assign((long double)j * 10, lst);
	}
	else
	{
		PMFW -= 1;
		ft_assign((n - (uint64_t)n) * 10, lst);
	}
}

void		ft_putstr_float_e(long double n, t_type *lst)
{
	int				e;
	int				a;
	long double		j;
	uint64_t		k;

	j = n;
	k = 1;
	a = 0;
	e = 0;
	n = ft_double(n, &e, &a, &k);
	g_ok = g_p;
	ft_itoustr((uint64_t)n);
	if (PMFW == -1 || PMFW == 0)
	{
		if (PMFW == 0)
			ft_e(lst, e, a);
		return ;
	}
	else
		ft_memset_g(g_str, '.', 1);
	j = (j - ((uint64_t)n * k / 10));
	ft_assign_e(n, j, e, lst);
	ft_e(lst, e, a);
}
