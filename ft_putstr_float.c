/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:45:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/24 04:06:02 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_float(double n, t_type *lst)
{
	double	size;
	long	i;

	size = 1;
	ft_longtoa((long)n);
	ft_memset_g(g_str, '.', 1);
	if (PMFW == -1)
		return ;
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

void			ft_putstr_float_g(double n, t_type *lst)
{
	double	size;
	long	i;

	size = 1;
	if (ft_strlen_num((long)n) == 2)
	{
		ft_longtoa((long)n);
		return ;
	}
	if (PMFW > 0 && PMFW < 3)
	{
		if (lst->arg_type == 'g')
			lst->arg_type = 'e';
		else
			lst->arg_type = 'E';
		PMFW = 1;
		if (PMFW == 2)
			PMFW = -1;
		ft_putstr_float_e(n, lst);
		if (lst->arg_type == 'e')
			lst->arg_type = 'g';
		else
			lst->arg_type = 'G';
		return ;
	}
	if (n < 0)
		n *= -1;
	ft_longtoa((long)n);
	if (PMFW == 3)
		return ;
	ft_memset_g(g_str, '.', 1);
	if (PMFW == 0)
		PMFW = 3;
	n = n - (long)n;
	i = PMFW + 1;
	while (i-- > 0)
		size /= 10;
	if (n > 0)
		n += size;
	else
		n -= size;
	if (PMFW == 4)
	{
		n *= 10;
		n *= 10;
		ft_longtoa((long)n);
		if (g_str[g_p - 1] >= '5')
		{
			g_str[g_p - 2] += 1;
			g_str[g_p - 1] = 0;
		}
		return ;
	}
	else
		while (PMFW-- > 0)
		{
			n *= 10;
			if (!(i = (long)n % 10))
				break ;
			ft_longtoa((long)n);
			n = n - (long)n;
		}
}

void			ft_putstr_hexa_assign_a(uintmax_t n)
{
	// if (n)
	// 	ft_putstr_hexa_assign(n / 16);
	if (n && (n % 16) <= 9)
		g_str[g_p++] = (n % 16) + 48;
	if ((n % 16) > 9)
		g_str[g_p++] = (n % 16) + 87;
}

void			ft_putstr_hexa_a(uintmax_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_hexa_assign_a(n);
}


void			ft_putstr_float_a(double n, t_type *lst)
{
	double	size;
	long	i;
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
	if (lst->arg_type == 'a')
		ft_memcpy_g(g_str, "0x", 2);
	else
		ft_memcpy_g(g_str, "0X", 2);
	size = 1;
	ft_longtoa((long)n);
	ft_memset_g(g_str, '.', 1);
	if (PMFW == -1)
		return ;
	n = n - (long)n;
	i = PMFW + 1;
	while (i-- > 0)
		size /= 10;
	if (n > 0)
		n += size;
	else
		n -= size;
	PMFW = 12;
	while (PMFW-- > 0)
	{
		n = n - (long)n;
		n *= 16;
		ft_putstr_hexa_a((long)n);
	}
}
