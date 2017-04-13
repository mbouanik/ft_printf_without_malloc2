/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:49:40 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:19:41 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg[] = {
	{'s', &ft_display_arg_s},
	{'c', &ft_display_arg_c},
	{'p', &ft_display_arg_p},
	{'b', &ft_display_arg_b},
	{'d', &ft_display_arg_d},
	{'i', &ft_display_arg_d},
	{'D', &ft_display_arg_dd},
	{'x', &ft_display_arg_x},
	{'X', &ft_display_arg_xx},
	{'o', &ft_display_arg_o},
	{'O', &ft_display_arg_octal},
	{'u', &ft_display_arg_u},
	{'U', &ft_display_arg_uu},
};

void			ft_new(t_type *lst)
{
	lst->flags = 0;
	lst->mfw = 0;
	lst->pmfw = 0;
	lst->mod = 0;
	lst->size = 0;
	lst->arg_type = 0;
}

int				ft_printf(char *format, ...)
{
	va_list		list;
	t_type		lst;
	short		j;

	va_start(list, format);
	g_size = 0;
	g_p = 0;
	ft_memset_g_set_zero(g_str, 0, BUFF_SIZE);
	while (*format)
	{
		ft_cp_until(g_str, &format, '%');
		ft_new(&lst);
		j = -1;
		if (*format == '%' && (format++))
		{
			ft_assign_flags(&format, &lst);
			while (lst.arg_type != g_arg[j].c && j++ < 13)
				if (lst.arg_type == g_arg[j].c)
					g_arg[j].f(&lst, list);
		}
	}
	ft_putstr_g(g_str);
	va_end(list);
	return (g_size += g_p);
}
