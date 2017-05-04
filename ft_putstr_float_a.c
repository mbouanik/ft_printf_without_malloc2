/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 19:52:34 by mbouanik          #+#    #+#             */
/*   Updated: 2017/05/04 18:58:58 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_hexa_assign_a(uintmax_t n)
{
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
	ft_memset_g(g_str, '.', 1);
	i = PMFW + 1;
	while (i-- > 0)
		size /= 10;
	if (n > 0)
		n += size;
	else
		n -= size;
	PMFW = 13;
	// printf("before %f\n", n);
	while (PMFW-- > 0)
	{
		ft_putstr_hexa((unsigned long)n);
		n = n - (long)n;
		// printf("e %f\n", n);
		n *= 16;
		// printf("o %f\n", n);
	}
}
