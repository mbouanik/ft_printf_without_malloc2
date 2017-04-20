/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:53:33 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/20 20:16:25 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_zero(t_type *lst)
{
	FLAGS |= 4;
}

void		ft_mfw(t_type *lst)
{
	MFW = ft_atoi_s(f, list);
	if (MFW < 0)
	{
		FLAGS += 2;
		MFW *= -1;
	}
}

void		ft_pmfw(t_type *lst)
{
	PMFW = ft_atoi_s(f, list);
	if (PMFW == 0)
		PMFW = -1;
}
