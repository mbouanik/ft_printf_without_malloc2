/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_c_uni.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:45:55 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/23 15:46:34 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg_uni g_arg_c_uni[] = {
	{0, &ft_display_arg_c_uni_7},
	{1, &ft_display_arg_c_uni_7},
	{2, &ft_display_arg_c_uni_7},
	{3, &ft_display_arg_c_uni_7},
	{4, &ft_display_arg_c_uni_7},
	{5, &ft_display_arg_c_uni_7},
	{6, &ft_display_arg_c_uni_7},
	{7, &ft_display_arg_c_uni_7},
	{8, &ft_display_arg_c_uni_11},
	{9, &ft_display_arg_c_uni_11},
	{10, &ft_display_arg_c_uni_11},
	{11, &ft_display_arg_c_uni_11},
	{12, &ft_display_arg_c_uni_16},
	{13, &ft_display_arg_c_uni_16},
	{14, &ft_display_arg_c_uni_16},
	{15, &ft_display_arg_c_uni_16},
	{16, &ft_display_arg_c_uni_16},
	{17, &ft_display_arg_c_uni_21},
	{18, &ft_display_arg_c_uni_21},
	{19, &ft_display_arg_c_uni_21},
	{20, &ft_display_arg_c_uni_21},
	{21, &ft_display_arg_c_uni_21}
};

void		ft_display_arg_c_uni(t_type *lst, va_list list)
{
	short		j;
	wchar_t		s;

	s = va_arg(list, wchar_t);
	SIZE = ft_strlen_b(s);
	if (MB_CUR_MAX < 4 && s > 127 && s < 256)
	{
		ft_memset_g_set(g_str, s, 1);
		ft_putstr_g(g_str);
		g_p = 0;
		g_size = 1;
		return ;
	}
	if (MB_CUR_MAX < 4 && s > 255)
	{
		g_size = -1;
		return ;
	}
	j = -1;
	while (g_arg_c_uni[j].c != SIZE && ++j < 22)
		if (g_arg_c_uni[j].c == SIZE)
			g_arg_c_uni[j].f(s, lst);
}