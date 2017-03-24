/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_identifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:32:42 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 07:23:27 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flags(char *f, t_type *list)
{
	if (*f == '#')
		list->flags |= 1;
	if (*f == '-')
		list->flags |= 2;
	if (*f == '0')
		list->flags |= 4;
	if (*f == ' ')
		list->flags |= 8;
	if (*f == '+')
		list->flags |= 16;
}

int			ft_check_str(char *str)
{
	int i;

	i = 0;
	while (!(ft_isalpha(str[i])))
		i++;
	if (ft_isalpha(str[i]))
		return (1);
	return (0);
}

void		ft_assign_flags(char *f, t_type *list)
{
	int			i;
	int			z;

	z = 0;
	i = 0;
	while (!(ft_isalpha(f[i])))
	{
		if (f[i] >= '1' && f[i] <= '9' &&
		(ft_count_until(f, '.') || ft_check_str(&f[i])) && z == 0)
		{
			list->mfw = ft_atoi(&f[i]);
			z += 1;
		}
		if (f[i] == '.' && (z = 1))
			list->pmfw = ft_atoi(&f[++i]);
		if (f[i] == '#' || f[i] == ' ' || f[i] == '-'
			|| f[i] == '+' || (f[i] == '0' && !(ft_isdigit(f[i - 1]))))
			ft_flags(&f[i], list);
		i++;
	}
	list->arg_type = f[i];
}
