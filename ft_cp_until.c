/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:59:11 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/24 16:43:04 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_cp_until(char *dest, char **src, char c)
{
	while (**src != c && **src && g_p < BUFF_SIZE && g_keep == 1)
		dest[g_p++] = *(*src)++;
	if (g_p & BUFF_SIZE)
		ft_size_s();
}
