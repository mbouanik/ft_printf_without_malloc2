/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_until.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:59:11 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/07 21:08:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_count_until(const char *str, char c)
{
	int i;

	i = 0;
	while (str[g_i] != c && str[g_i] && i++ < BUFF_SIZE)
		g_i++;
	return (g_i);
}

void		ft_cp_until(char *dest, char **src, char c)
{
	while (**src != c && **src && g_p < BUFF_SIZE)
		dest[g_p++] = *(*src)++;
	if (g_p >= BUFF_SIZE)
		ft_size_s();
}
