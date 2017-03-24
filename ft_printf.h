/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:34:57 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 06:31:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# define SIZE list->content_size
# define FLAGS lst->flags
# define CONTENT list->content
# define PMFW lst->pmfw
# define MFW lst->mfw

char	g_str[10000];
int		g_p;

typedef struct		s_type
{
	short			flags;
	int				mfw;
	int				pmfw;
	char			arg_type;
	int				use;
	struct s_type	*next;
}					t_type;

typedef void		(*g_func_arg)(t_type *, va_list);

typedef struct		s_arg
{
	char			c;
	g_func_arg		f;
}					t_arg;

void				ft_flags(char *f, t_type *list);
void				*ft_mfw(char *f, t_type *list);
void				*ft_pmfw(char *f, t_type *list);
void				*ft_arg_type(char *f, t_type *list);
void				ft_assign_flags(char *f, t_type *list);
t_type				*ft_new(t_type *lst);
char				ft_char(va_list list);
char				*ft_char_star(va_list list);
char				*ft_int(va_list list);
char				*ft_longlong(va_list list);
char				*ft_long(va_list list);
void				ft_display_arg_s(t_type *lst, va_list list);
void				ft_display_arg_d(t_type *lst, va_list list);
void				ft_display_arg_u(t_type *lst, va_list list);
void				ft_display_arg_c(t_type *lst, va_list list);
void				ft_display_arg_o(t_type *lst, va_list list);
void				ft_display_arg_x(t_type *lst, va_list list);
void				ft_display_arg_xx(t_type *lst, va_list list);
void				ft_display_arg_octal(t_type *lst, va_list list);
void				ft_display_arg_lint(t_type *lst, va_list list);
void				ft_display_arg_lu(t_type *lst, va_list list);
void				ft_display_arg_p(t_type *lst, va_list list);
void				ft_display_arg_b(t_type *lst, va_list list);
int					ft_real_size(t_type *lst, t_list *list);
t_type				*ft_new_type(t_type *lst);
// char				*ft_chartostr(int c);
void				ft_itostr(int n);
void				ft_itoustr(unsigned int n);
#endif
