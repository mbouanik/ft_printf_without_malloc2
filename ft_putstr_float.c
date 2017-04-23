/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:45:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/23 03:52:58 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_float(double n, t_type *lst)
{
	double	size;
	long	i;

	size = 1;
	ft_longtoa((long)n * 1);
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
