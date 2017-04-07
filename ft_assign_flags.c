/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:32:42 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/07 04:51:36 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags(char **f, t_type *lst)
{
	if (**f == '#')
		FLAGS |= 1;
	else if (**f == '-')
		FLAGS |= 2;
	else if (**f == '0')
		FLAGS |= 4;
	else if (**f == ' ')
		FLAGS |= 8;
	else if (**f == '+')
		FLAGS |= 16;
}

static void		ft_arg_type(t_type *lst, char **str)
{
	MOD |= *(*str)++;
	if (**str == 'h' || **str == 'l')
		MOD += *(*str)++;
	MOD += *(*str)++;
}

void			ft_assign_flags(char **f, t_type *lst)
{
	*f += 1;
	if (**f == '\0')
		return ;
	while (!(ft_isalpha(**f)) && **f != '%')
	{
		if (**f >= '1' && **f <= '9' && lst->deep == 0 && (lst->deep += 1))
			lst->mfw = ft_atoi(*f);
		else if (**f == '.' && *(*f + 1) >= '1' && *(*f + 1) <= '9'
				&& (lst->deep = 1))
			lst->pmfw = ft_atoi(*f += 1);
		else if (**f == '#' || **f == ' ' || **f == '-'
			|| **f == '+' || (**f == '0' && !(ft_isdigit(*(*f - 1)))))
			ft_flags(f, lst);
		*f += 1;
	}
	if (**f == '%' && ++(*f))
		ft_display_arg_pur(lst);
	else if (**f == 'h' || **f == 'l' || **f == 'j' || **f == 'z')
		ft_arg_type(lst, f);
	else if (ft_isalpha(**f) && ((*(*f - 1) == '.') || ((*(*f - 2) == '.')
		&& (*(*f - 1) == '0') && PMFW == 0)))
		*f += 1;
	else
		MOD += *(*f)++;
}
