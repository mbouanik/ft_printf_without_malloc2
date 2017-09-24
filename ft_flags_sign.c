/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:50:04 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/22 21:00:21 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flags_sign(t_type *lst, long n)
{
	if (FLAGS & 16 && n >= 0 && --MFW)
		ft_memset_g(g_str, '+', 1);
	else if (FLAGS & 8 && n >= 0 && --MFW)
		ft_memset_g(g_str, ' ', 1);
	else if (n < 0 && --MFW)
		ft_memset_g(g_str, '-', 1);
}

void			ft_flags_sign_float(t_type *lst, double n)
{
	if (FLAGS & 16 && n >= 0 && --MFW)
		ft_memset_g(g_str, '+', 1);
	else if (FLAGS & 8 && n >= 0 && --MFW)
		ft_memset_g(g_str, ' ', 1);
	else if (n < 0 && --MFW)
		ft_memset_g(g_str, '-', 1);
}
