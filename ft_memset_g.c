/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 09:12:33 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/19 10:34:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memset_g(void *b, wchar_t c, size_t len)
{
	char		*str;

	str = (char *)b;
	if (len)
		while (len--)
			str[g_p++] = (wchar_t)c;
}

void	ft_memcpy_g(void *dest, const void *src, size_t n)
{
	char	*sc;
	char	*des;

	sc = (char*)src;
	des = (char*)dest;
	if (n)
		while (n--)
			des[g_p++] = *sc++;
}

void	*ft_memset_g_set_zero(void *b, int c, size_t len)
{
	uint64_t	*word;
	uint64_t	a;

	word = (uint64_t *)b;
	a = c * BASE;
	while (len)
	{
		*word++ = a;
		len -= 8;
	}
	return (word);
}

void	*ft_memset_g_set(void *b, int c, size_t len)
{
	uint64_t	*word;
	uint64_t	a;
	char		*str;

	word = NULL;
	a = 0;
	str = (char *)b;
	while (len && len % 8)
	{
		str[g_p++] = c;
		len--;
	}
	if (len && !(len % 8))
	{
		word = (uint64_t *)&str[g_p];
		a = c * BASE;
		while (len)
		{
			*word++ = a;
			len -= 8;
			g_p += 8;
		}
	}
	return (word);
}
