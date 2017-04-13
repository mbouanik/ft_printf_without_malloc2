/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:34:57 by mbouanik          #+#    #+#             */
/*   Updated: 2017/04/13 07:15:31 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# define FLAGS lst->flags
# define PMFW lst->pmfw
# define MFW lst->mfw
# define MOD lst->mod
# define SIZE lst->size
# define BUFF_SIZE 80
# define BASE 0x0101010101010101

char	g_str[BUFF_SIZE];
short	g_p;
int		g_size;
int		g_i;

typedef struct		s_type
{
	short			flags;
	int				mfw;
	int				pmfw;
	short			mod;
	int				size;
	char			arg_type;
}					t_type;

typedef void		(*t_func_arg)(t_type *, va_list);
typedef void		(*t_func_flag)(t_type *);

typedef struct		s_arg
{
	short			c;
	t_func_arg		f;
}					t_arg;

typedef struct		s_flag
{
	short			c;
	t_func_flag		f;
}					t_flag;

void				ft_assign_flags(char **f, t_type *lst);
void				ft_display_arg_s(t_type *lst, va_list list);
void				ft_display_arg_d(t_type *lst, va_list list);
void				ft_display_arg_dd(t_type *lst, va_list list);
void				ft_display_arg_u(t_type *lst, va_list list);
void				ft_display_arg_uu(t_type *lst, va_list list);
void				ft_display_arg_c(t_type *lst, va_list list);
void				ft_display_arg_o(t_type *lst, va_list list);
void				ft_display_arg_x(t_type *lst, va_list list);
void				ft_display_arg_xx(t_type *lst, va_list list);
void				ft_display_arg_octal(t_type *lst, va_list list);
void				ft_display_arg_lint(t_type *lst, va_list list);
void				ft_display_arg_lu(t_type *lst, va_list list);
void				ft_display_arg_p(t_type *lst, va_list list);
void				ft_display_arg_b(t_type *lst, va_list list);
void				ft_display_arg_u_us(t_type *lst, va_list list);
void				ft_display_arg_d_intm(t_type *lst, va_list list);
void				ft_display_arg_d_schar(t_type *lst, va_list list);
void				ft_display_arg_d_short(t_type *lst, va_list list);
void				ft_display_arg_o_uchar(t_type *lst, va_list list);
void				ft_display_arg_o_uintm(t_type *lst, va_list list);
void				ft_display_arg_o_us(t_type *lst, va_list list);
void				ft_display_arg_u_uchar(t_type *lst, va_list list);
void				ft_display_arg_u_uintm(t_type *lst, va_list list);
void				ft_display_arg_x_uchar(t_type *lst, va_list list);
void				ft_display_arg_x_uintm(t_type *lst, va_list list);
void				ft_display_arg_x_us(t_type *lst, va_list list);
void				ft_display_arg_xx_uchar(t_type *lst, va_list list);
void				ft_display_arg_xx_uintm(t_type *lst, va_list list);
void				ft_display_arg_xx_us(t_type *lst, va_list list);
void				ft_display_arg_pur(t_type *lst);
void				ft_itostr(int n);
void				ft_longtoa(long n);
void				ft_itoustr(unsigned long n);
void				ft_putstr_octal(unsigned int n);
void				ft_putstr_lo(uint64_t n);
void				ft_memset_g(void *b, int c, size_t len);
void				ft_memcpy_g(void *dest, const void *src, size_t n);
void				ft_putstr_hexa(uintmax_t n);
void				ft_putstr_x(uintmax_t n);
void				ft_putstr_b(uintmax_t n);
void				ft_flags_sign(t_type *lst, long n);
int					ft_isalpha(int c);
int					ft_atoi(char **str);
int					ft_isdigit(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_putstr_g(char *str);
int					ft_strlen_b(long long n);
int					ft_strlen_hexa(unsigned long long int n);
size_t				ft_strlen_num(long long int n);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isprint(int c);
void				ft_size(t_type *lst, int size);
void				*ft_memset_g_set(void *b, int c, size_t len);
void				*ft_memset_g_set_zero(void *b, int c, size_t len);
void				ft_size_s(void);
void				ft_cp_until(char *dest, char **src, char c);
int					ft_isdigit_s(int c);
size_t				ft_strlen_o(long long int n);
void				ft_display_arg_d_mod(t_type *lst, va_list list);
void				ft_display_arg_o_mod(t_type *lst, va_list list);
void				ft_display_arg_x_mod(t_type *lst, va_list list);
void				ft_display_arg_xx_mod(t_type *lst, va_list list);
void				ft_display_arg_u_mod(t_type *lst, va_list list);
void				ft_hash(t_type *lst);
void				ft_minus(t_type *lst);
void				ft_blank(t_type *lst);
void				ft_zero(t_type *lst);
void				ft_plus(t_type *lst);
void				ft_check_size(t_type *lst, int n);
void				ft_check_size_o(t_type *lst, long int n);
void				ft_check_size_hexa(t_type *lst, unsigned int n);

#endif
