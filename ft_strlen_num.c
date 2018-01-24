/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:05:30 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/24 17:50:42 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen_num(long long int n)
{
	size_t size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

size_t		ft_strlen_o(long long int n)
{
	size_t size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 8;
		size++;
	}
	return (size);
}

size_t		ft_strlen_comma(float n)
{
	size_t i;

	i = 0;
	while ((((uint64_t)(n *= 10)) % 10) != 0)
		++i;
	n += 00.1;
	if ((((uint64_t)(n)) % 10) != 0)
		++i;
	return (i);
}
