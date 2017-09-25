/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:35:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/25 16:19:44 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_size_f(t_type *lst, uint64_t n)
{
	SIZE = ft_strlen_num((uint64_t)n) + 1;
	if (PMFW == 0 && (PMFW = 6))
		SIZE += 6;
	else if (PMFW > 0)
		SIZE += PMFW;
	if (PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_f_g(t_type *lst, uint64_t n)
{
	SIZE = ft_strlen_num((uint64_t)n);
	if (SIZE < 6 && PMFW <= 7)
	{
		if ((long)n == 0)
			PMFW = 8 - SIZE;
		else
			PMFW = 7 - SIZE;
		SIZE += PMFW + 1;
	}
	else if ((SIZE == 7 && PMFW <= 7) || (SIZE == PMFW))
		PMFW = -1;
	else if (PMFW > 7)
	{
		SIZE = PMFW;
		PMFW = SIZE - ft_strlen_num((long)n);
		SIZE += 1;
	}
	if (PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_f_e(t_type *lst, uint64_t n)
{
	SIZE = 1;
	if (PMFW == 1)
		SIZE += 4;
	else if (PMFW == 0 && (PMFW = 6))
		SIZE += 6;
	else if (PMFW > 0)
		SIZE += PMFW + 4;
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

void		ft_check_size_g(t_type *lst, uint64_t n)
{
	SIZE = ft_strlen_num((uint64_t)n);
	if (SIZE <= 7 || PMFW >= SIZE || (PMFW > SIZE && PMFW >= 16))
	{
		ft_check_size_f_g(lst, n);
		g_ok = 1;
	}
	else
		ft_check_size_f_e(lst, n);
}
