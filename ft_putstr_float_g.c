/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:33:25 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/14 19:42:47 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_assign_g_e_g(double n, t_type *lst)
{
	long	i;
	double	size;

	size = 1;
	ft_longtoa((long)n);
	if (PMFW == -1)
		return ;
	else if (PMFW == 3)
		PMFW = 2;
	else if (PMFW == 2)
		PMFW = 1;
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
		n *= 10;
	i = n * 10;
	if (i % 10 >= 5)
		n += 1;
	ft_longtoa_g((long)n);
}

void		ft_e_g(t_type *lst, int e, int a)
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

void		ft_putstr_float_e_g(double n, t_type *lst)
{
	int		e;
	int		a;
	long	r;

	a = 0;
	e = 0;
	if (n < 0)
		n *= -1;
	if (n < 1)
		a = 1;
	if (!a)
	{
		while (n > 1.0 && ++e)
			n /= 10;
		e -= 1;
		n *= 10;
	}
	else
	{
		while (n < 1.0)
		{
			n *= 10;
			e++;
		}
	}
	if (PMFW == 1)
	{
		n *= 10;
		r = (long)n;
		n /= 10;
		if (r % 10 > 5)
		{
			ft_longtoa((long)n + 1);
			ft_e_g(lst, e, a);
		}
		else
		{
			ft_longtoa((long)n);
			ft_e_g(lst, e, a);
		}
		return ;
	}
	ft_assign_g_e_g(n, lst);
	if (e > 1)
		ft_e_g(lst, e, a);
}

void			ft_putstr_float_g(double n, t_type *lst)
{
	double	size;
	long	i;
	int f;

	size = 1;
	f = ft_strlen_num((long)n) + 1;
	if ((PMFW < f - 1 && PMFW != 0) || (PMFW == 0 && f > 7 && (PMFW = 4)))
	{
		ft_putstr_float_g2(lst, n, f);
		return ;
	}
	if (n < 0)
		n *= -1;
	else if (PMFW == f - 1)
	{
		i = n * 10;
		if (i % 10 >= 5)
			n += 1;
		ft_longtoa((long)n);
		return ;
	}
	else if (PMFW == f)
	{
		PMFW = 1;
		i = n * 10;
		if (i % 10 >= 5)
			n += 0.1;
		ft_putstr_float_gg(n, lst);
		return ;
	}
	else if (PMFW > f && PMFW >= f * 2)
	{
		PMFW -= f - 1;
		ft_putstr_float_gg(n, lst);
		return ;
	}
	else
	{
		PMFW = 7 - f;
		if (n < 1)
			PMFW = 7;
		if (PMFW)
			ft_putstr_float(n, lst);
	}
}
