/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:38:20 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/19 14:44:08 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i])
			i++;
	return (i);
}

size_t	ft_strlen_uni(wchar_t *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i])
			i++;
	return (i);
}
