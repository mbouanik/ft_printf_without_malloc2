/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoustr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:14:19 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/15 07:29:42 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_itoustr_assign(uint64_t n)
{
	if (n > 0)
		ft_itoustr_assign(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + 48;
}

void		ft_itoustr(uint64_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_itoustr_assign(n);
}
