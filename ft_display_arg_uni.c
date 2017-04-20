/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_uni.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:22:23 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/20 18:02:44 by mbouanik         ###   ########.fr       */
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

t_arg_str_uni g_arg_str_uni[] = {
	{0, &ft_display_arg_c_uni_7_arg},
	{1, &ft_display_arg_c_uni_7_arg},
	{2, &ft_display_arg_c_uni_7_arg},
	{3, &ft_display_arg_c_uni_7_arg},
	{4, &ft_display_arg_c_uni_7_arg},
	{5, &ft_display_arg_c_uni_7_arg},
	{6, &ft_display_arg_c_uni_7_arg},
	{7, &ft_display_arg_c_uni_7_arg},
	{8, &ft_display_arg_c_uni_11_arg},
	{9, &ft_display_arg_c_uni_11_arg},
	{10, &ft_display_arg_c_uni_11_arg},
	{11, &ft_display_arg_c_uni_11_arg},
	{12, &ft_display_arg_c_uni_16_arg},
	{13, &ft_display_arg_c_uni_16_arg},
	{14, &ft_display_arg_c_uni_16_arg},
	{15, &ft_display_arg_c_uni_16_arg},
	{16, &ft_display_arg_c_uni_16_arg},
	{17, &ft_display_arg_c_uni_21_arg},
	{18, &ft_display_arg_c_uni_21_arg},
	{19, &ft_display_arg_c_uni_21_arg},
	{20, &ft_display_arg_c_uni_21_arg},
	{21, &ft_display_arg_c_uni_21_arg}
};

void		ft_display_arg_c_uni(t_type *lst, va_list list)
{
	short		j;
	wchar_t		s;

	s = va_arg(list, wchar_t);
	SIZE = ft_strlen_b(s);
	j = -1;
	while (g_arg_c_uni[j].c != SIZE && ++j < 22)
		if (g_arg_c_uni[j].c == SIZE)
			g_arg_c_uni[j].f(s, lst);
}

void		ft_display_arg_str_uni_c(wchar_t s)
{
	short		j;
	int			size;

	size = ft_strlen_b(s);
	j = -1;
	while (g_arg_str_uni[j].c != size && ++j < 22)
		if (g_arg_str_uni[j].c == size)
			g_arg_str_uni[j].f(s);
}

void		ft_putstr_uni(wchar_t *s, t_type *lst)
{
	while (SIZE-- && *s)
		ft_display_arg_str_uni_c(*s++);
}

void		ft_display_arg_str_uni_no_dash(t_type *lst, wchar_t *s)
{
	if (MFW > 0)
	{
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW);
		else
			ft_memset_g_set(g_str, ' ', MFW);
		if (PMFW != -1)
			ft_putstr_uni(s, lst);
	}
	else
	{
		if (PMFW != -1)
			ft_putstr_uni(s, lst);
	}
}

void		ft_precision(wchar_t *s, t_type *lst)
{
	int accu;
	int i;
	int j;

	i = 0;
	j = 0;
	accu = 0;
	while (PMFW > 0 && s[j])
	{
		i = ft_strlen_b(s[j]);
		if (i >= 1 && i <= 7 && (accu += 1))
			PMFW -= 1;
		else if (i >= 8 && i <= 11 && (accu += 1))
			PMFW -= 2;
		else if (i >= 12 && i <= 16 && (accu += 1))
			PMFW -= 3;
		else if (i >= 17 && i <= 21 && (accu += 1))
			PMFW -= 4;
		j++;
	}
	if (PMFW < 0)
		accu -= 1;
	if (accu <= SIZE)
		SIZE = accu;
}

void		ft_display_arg_str_uni(t_type *lst, va_list list)
{
	wchar_t		*s;
	int			b;

	s = va_arg(list, wchar_t *);
	if (s == NULL && PMFW != -1)
	{
		ft_memcpy_g(g_str, "(null)", 6);
		return ;
	}
	SIZE = ft_strlen_uni(s);
	if (PMFW > 0)
		ft_precision(s, lst);
	b = ft_size_uni(s, lst);
	if (PMFW != -1)
		MFW -= b;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
	{
		if (PMFW != -1)
			ft_putstr_uni(s, lst);
		if (MFW > 0)
			ft_memset_g_set(g_str, ' ', MFW);
	}
	else
		ft_display_arg_str_uni_no_dash(lst, s);
}
