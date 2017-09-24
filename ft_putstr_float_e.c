/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:17:20 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/24 21:50:29 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_round_up(double n)
{
	int i;

	i = g_p;
	g_p--;
	if ((uint64_t)(n * 10) % 10 >= 5)
	{
		if (g_str[g_p] <= '8')
			g_str[g_p] += 1;
		else if (g_str[g_p] == '9')
		{
			while (g_str[g_p] == '9')
			{
				g_str[g_p] = '0';
				g_p--;
			}
			if (g_str[g_p] == '.')
				--g_p;
			g_str[g_p] += 1;
		}
	}
	g_p = i;
}

void		ft_assign(double n, t_type *lst)
{
	ft_itoustr((uint64_t)n);
	n = n - (uint64_t)n;
	while (PMFW-- > 0)
	{
		n *= 10;
		g_str[g_p++] = (uint64_t)n % 10 + 48;
		n = n - (int)n;
	}
	if (lst->arg_type == 'e' || lst->arg_type == 'E')
		ft_round_up(n);
}

void		ft_e(t_type *lst, long e, long a)
{
	if (lst->arg_type == 'g')
		lst->arg_type = 'e';
	else
		lst->arg_type = 'E';
	ft_memset_g(g_str, lst->arg_type, 1);
	if (a)
		ft_memset_g(g_str, '-', 1);
	else
		ft_memset_g(g_str, '+', 1);
	if (e < 10)
		ft_memset_g(g_str, '0', 1);
	ft_longtoa((long)e);
	if (lst->arg_type == 'e')
		lst->arg_type = 'g';
	else
		lst->arg_type = 'G';
}

void		ft_putstr_float_e(double n, t_type *lst)
{
	int			e;
	int			a;
	double		j;
	uint64_t	k;

	j = n;
	k = 1;
	a = 0;
	if ((e = 0) && n < 0)
		n *= -1;
	if (n < 1)
		a = 1;
	if (n > 1.0)
	{
		while (n > 0.9 && ++e)
		{
			n /= 10;
			k *= 10;
		}
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
	g_ok = g_p;
	if (n < 0)
		ft_itoustr((uint64_t)(n *= -1));
	else
		ft_itoustr((uint64_t)n);
	if (PMFW == -1)
		return ;
	ft_memset_g(g_str, '.', 1);
	j = (j - ((int)n * k / 10));
	if (PMFW >= ft_strlen_num((long long)j))
	{
		if (e == 0)
			j *= 10;
		PMFW -= ft_strlen_num((long long)j);
		ft_assign(j, lst);
	}
	else
	{
		PMFW -= 1;
		ft_assign((n - (int)n) * 10, lst);
	}
	ft_e(lst, e, a);
}
