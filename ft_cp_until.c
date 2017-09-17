/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:59:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/17 16:28:15 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_cp_until(char *dest, char **src, char c)
{
	while (**src != c && **src && g_p < BUFF_SIZE && g_keep)
		dest[g_p++] = *(*src)++;
	if (g_p & BUFF_SIZE)
		ft_size_s();
}
