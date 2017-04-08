/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:05:30 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/08 03:36:45 by mbouanik         ###   ########.fr       */
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
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
