/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoustr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:14:19 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/08 15:06:10 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_itoustr_assign(unsigned long n)
{
	if (n > 0)
		ft_itoustr_assign(n / 10);
	if (n > 0)
		g_str[g_p++] = n % 10 + '0';
}

void		ft_itoustr(unsigned long n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_itoustr_assign(n);
}
