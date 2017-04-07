/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 23:11:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/29 10:15:36 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_hexa(unsigned long long int n)
{
	int size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n)
	{
		size += 1;
		n /= 16;
	}
	return (size);
}
