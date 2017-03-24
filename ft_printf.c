/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:49:40 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 07:43:43 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_arg g_arg[] = {
	{'s', &ft_display_arg_s},
	{'d', &ft_display_arg_d},
	{'i', &ft_display_arg_d},
	{'u', &ft_display_arg_u},
	{'c', &ft_display_arg_c},
	{'D', &ft_display_arg_d},
	{'U', &ft_display_arg_u}
	// {'o', &ft_display_arg_o},
	// {'x', &ft_display_arg_x},
	// {'X', &ft_display_arg_xx},
	// {'O', &ft_display_arg_octal},
	// {'p', &ft_display_arg_p},
	// {'b', &ft_display_arg_b}
};

t_type		*ft_new(t_type *lst)
{
	lst->flags = 0;
	lst->mfw = 0;
	lst->pmfw = 0;
	lst->arg_type = 0;
	lst->use = 0;
	lst->next = NULL;
	return (lst);
}

int				ft_printf(char *format, ...)
{
	va_list		list;
	t_type		lst;
	int			j;

	va_start(list, format);
	g_p = 0;
	while (*format)
	{
		ft_new(&lst);
		j = -1;
		if (*format == '%')
		{
			ft_assign_flags(format, &lst);
			while (j++ < 7)
				if (lst.arg_type == g_arg[j].c)
					g_arg[j].f(&lst, list);
			while (!(ft_isalpha(*format)))
				format += 1;
			format += 1;
		}
		g_str[g_p++] = *format++;
	}
	ft_putstr(g_str);
	return (g_p);
}

int				main(void)
{
	ft_printf("Hello %-10d this is %-10s from %-10u %c\n", 120, "Dante", 42, 'Z');
	   printf("Hello %-10d this is %-10s from %-10u %c\n", 120, "Dante", 42, 'Z');
}
