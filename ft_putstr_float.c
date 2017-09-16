/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:45:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/16 19:32:17 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_g_zero(double n, int a)
{
	int i;

	i = 0;
	while (a-- > 0)
	{
		if (i && (long)n % 10 >= 1)
			return (0);
		n *= 10;
	}
	return (1);
}

void			ft_putstr_float(double n, t_type *lst)
{
	double	size;
	long	i;

	size = 1;
	ft_longtoa((long)n);
	if (ft_g_zero(n, PMFW) && (lst->arg_type == 'g' || lst->arg_type == 'G'))
		return ;
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
	if ((long)(n *= 10) % 10 == 0)
		i = 1;
	while (PMFW-- > 0)
	{
		if (i == 1 && (long)n % 10 == 0)
			g_str[g_p++] = (long)n % 10 + 48;
		else
			i = 0;
		n *= 10;
	}
	// n /= 10;
	// printf("%f\n", n);
	// printf("%d\n", ((long)n % 10) >= 5);
	if (((long)n % 10) >= 5)
		n += 2;
	ft_longtoa((long)n / 10);
}

void			ft_putstr_float_gg(double n, t_type *lst)
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
		n *= 10;
	i = n * 10;
	if (i % 10 >= 5)
		n += 1;
	ft_longtoa_g((long)n);
}
