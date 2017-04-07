/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:19:16 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/29 13:29:27 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_octal_assign(long long n)
{
	if (n > 0)
		ft_putstr_octal_assign(n / 8);
	if (n > 0)
		g_str[g_p++] = n % 8 + '0';
}

void			ft_putstr_octal(long long n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_octal_assign(n);
}
