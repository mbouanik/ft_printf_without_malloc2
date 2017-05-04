/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:45:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/05/01 19:51:52 by mbouanik         ###   ########.fr       */
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
		n *= 10;
	i = n * 10;
	if (i % 10 >= 5)
		n += 1;
	ft_longtoa((long)n);
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
