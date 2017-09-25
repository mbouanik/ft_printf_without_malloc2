/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:33:25 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/25 16:14:30 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_float_g(double n, t_type *lst)
{
	SIZE = ft_strlen_num((long long)n);
	// printf("SIZE %d\n", SIZE);
	// printf("PMFW %d\n", PMFW);

	if(g_ok == 1) //(SIZE <= 6 || PMFW >= SIZE || (PMFW > SIZE && PMFW >= 16))
	{
		if (PMFW == SIZE)
			PMFW = -1;
		// if (PMFW != -1)
			// PMFW += 1;
		ft_putstr_float(n, lst);
		// lst->arg_type = 'g';
	}
	else
	{
		if (PMFW != -1 || PMFW > 0)
			PMFW -= 1;
		// printf("PMDAFE %d\n", PMFW);
		ft_putstr_float_e(n, lst);

	}
}
