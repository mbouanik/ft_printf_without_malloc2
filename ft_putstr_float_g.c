/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:33:25 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/24 22:11:57 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_float_g(double n, t_type *lst)
{
	SIZE = ft_strlen_num((long long)n);
	printf("SIZE %d\n", SIZE);
	printf("PMFW %d\n", PMFW);
	if (SIZE <= 7)
	{
		if (PMFW != -1)
			PMFW += 1;

		ft_putstr_float(n, lst);
	}
	else
	{
		// printf("PMFW %d \n", PMFW);
		PMFW -= 1;
		ft_putstr_float_e(n, lst);
	}
}
