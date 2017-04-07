/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:50:04 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/30 18:08:45 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flags_sign(t_type *lst, int n)
{
	if (FLAGS & 16 && n >= 0)
		ft_memset_g(g_str, '+', 1);
	else if (FLAGS & 8 && n > 0)
		ft_memset_g(g_str, ' ', 1);
	else if (n < 0)
		ft_memset_g(g_str, '-', 1);
}
