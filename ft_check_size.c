/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:35:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/14 20:59:32 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_size_f(t_type *lst, int n)
{
	SIZE = ft_strlen_num(n) + 1;
	if (PMFW == 0 && (PMFW = 6))
		SIZE += 6;
	else if (PMFW > 0)
		SIZE += PMFW;
	if (PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_f_e(t_type *lst, int n)
{
	SIZE = ft_strlen_num(n) + 1;
	if ((PMFW == 0 || PMFW > 6) && (PMFW = 5))
		SIZE += 6;
	else if (PMFW > 0 && PMFW < 6)
		SIZE += PMFW;
	if (PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_str(t_type *lst, char *s)
{
	if ((SIZE = ft_strlen(s)) && SIZE > PMFW && PMFW > 0)
		SIZE = PMFW;
	if (PMFW == -1)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_g(t_type *lst, double n)
{
	SIZE = ft_strlen_num(n) + 1;
	SIZE += PMFW;
	if (PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}
