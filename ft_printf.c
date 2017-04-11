/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:49:40 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/11 04:54:00 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_arg g_arg[] = {
	{115, &ft_display_arg_s},
	{99, &ft_display_arg_c},
	{112, &ft_display_arg_p},
	{98, &ft_display_arg_b},
	{100, &ft_display_arg_d},
	{105, &ft_display_arg_d},
	{68, &ft_display_arg_dd},
	{120, &ft_display_arg_x},
	{88, &ft_display_arg_xx},
	{111, &ft_display_arg_o},
	{79, &ft_display_arg_octal},
	{117, &ft_display_arg_u},
	{85, &ft_display_arg_uu},
	{208, &ft_display_arg_d_intm},
	{316, &ft_display_arg_d_intm},
	{206, &ft_display_arg_d_intm},
	{222, &ft_display_arg_d_intm},
	{204, &ft_display_arg_d_short},
	{308, &ft_display_arg_d_schar},
	{213, &ft_display_arg_d_intm},
	{321, &ft_display_arg_d_intm},
	{211, &ft_display_arg_d_intm},
	{227, &ft_display_arg_d_intm},
	{209, &ft_display_arg_d_short},
	{313, &ft_display_arg_d_schar},
	{176, &ft_display_arg_d_intm},
	{284, &ft_display_arg_d_intm},
	{174, &ft_display_arg_d_intm},
	{190, &ft_display_arg_d_intm},
	{172, &ft_display_arg_u_us},
	{276, &ft_display_arg_u_us},
	{228, &ft_display_arg_x_uintm},
	{336, &ft_display_arg_x_uintm},
	{226, &ft_display_arg_x_uintm},
	{242, &ft_display_arg_x_uintm},
	{224, &ft_display_arg_x_us},
	{328, &ft_display_arg_x_uchar},
	{196, &ft_display_arg_xx_uintm},
	{304, &ft_display_arg_xx_uintm},
	{194, &ft_display_arg_xx_uintm},
	{210, &ft_display_arg_xx_uintm},
	{192, &ft_display_arg_xx_us},
	{296, &ft_display_arg_xx_uchar},
	{215, &ft_display_arg_o_us},
	{219, &ft_display_arg_o_uintm},
	{327, &ft_display_arg_o_uintm},
	{217, &ft_display_arg_o_uintm},
	{233, &ft_display_arg_o_uintm},
	{319, &ft_display_arg_o_uchar},
	{287, &ft_display_arg_o_uintm},
	{295, &ft_display_arg_o_uintm},
	{185, &ft_display_arg_o_uintm},
	{201, &ft_display_arg_o_uintm},
	{183, &ft_display_arg_o_us},
	{187, &ft_display_arg_o_uchar},
	{225, &ft_display_arg_u_uint},
	{333, &ft_display_arg_u_uint},
	{223, &ft_display_arg_u_uint},
	{239, &ft_display_arg_u_uint},
	{221, &ft_display_arg_u_us},
	{325, &ft_display_arg_u_uchar},
	{189, &ft_display_arg_u_uint},
	{293, &ft_display_arg_u_us},
	{193, &ft_display_arg_u_uint},
	{301, &ft_display_arg_u_uint},
	{191, &ft_display_arg_u_uint},
	{207, &ft_display_arg_u_uint}
};

void			ft_new(t_type *lst)
{
	lst->flags = 0;
	lst->mfw = 0;
	lst->pmfw = 0;
	lst->mod = 0;
	lst->deep = 0;
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
		if (*format == '%')
		{
			ft_assign_flags(&format, &lst);
			while (lst.mod != g_arg[j].c && j++ < 66)
				if (lst.mod == g_arg[j].c)
					g_arg[j].f(&lst, list);
		}
	}
	ft_putstr_g(g_str);
	va_end(list);
	return (g_size += g_p);
}

// int main (void)
// {
// 	ft_printf("%lp\n", 42);
// 	printf("%lp\n", 42);
// }
