/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 09:12:33 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 11:02:14 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset_g(void *b, int c, size_t len)
{
	char		*str;

	str = (char*)b;
	if (len <= 0)
		return (str);
	if (len)
		while (len--)
			str[g_p++] = (unsigned char)c;
	return (str);
}

void	*ft_memcpy_g(void *dest, const void *src, size_t n)
{
	char	*sc;
	char	*des;

	sc = (char*)src;
	des = (char*)dest;
	if (n <= 0)
		return (sc);
	while (n--)
		des[g_p++] = *sc++;
	return (des);
}
