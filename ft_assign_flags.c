/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:32:42 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/11 05:59:07 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags(char **f, t_type *lst)
{
	while (!(ft_isalpha(**f)) && !(ft_isdigit_s(**f)) && **f != '%'
			&& **f != '.' && **f)
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
		*f += 1;
	}
}

static void		ft_arg_type(t_type *lst, char **str)
{
	// int a;

	// a = 0;
	// if (**str == 'j' || **str == 'z')
	// 	a = 1;
	MOD |= *(*str)++;
	if ((**str == 'h' || **str == 'l'))// && a == 0)
		MOD += *(*str)++;
	// else
	// 	*str += 1;
	// if (MOD == 104 || MOD == 208 || MOD == 108 || MOD == 216
	// 	|| MOD == 106 || MOD == 122)
		if (ft_isalpha(**str))
		 	MOD += *(*str)++;
}

void			ft_assign_flags(char **f, t_type *lst)
{
	*f += 1;
	if (**f == '\0')
		return ;
	ft_flags(f, lst);
	while (!(ft_isalpha(**f)) && **f != '%' && **f)
	{
		if (ft_isdigit_s(**f) && lst->deep == 0 && (lst->deep += 1))
			lst->mfw = ft_atoi(*f);
		else if (**f == '.' && (lst->deep = 1))
		{
			if (ft_isdigit_s(*(*f + 1)))
				PMFW = ft_atoi(*f += 1);
			else
				PMFW = -1;
		}
		*f += 1;
	}
	if (**f == '%' && ++(*f))
		ft_display_arg_pur(lst);
	else if (**f == 'h' || **f == 'l' || **f == 'j' || **f == 'z')
		ft_arg_type(lst, f);
	// else
	// {
		if (ft_isalpha(**f))
			MOD += *(*f)++;
	// }
}
