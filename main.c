/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:33:10 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/26 11:25:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int main()
{
  int n;
  // setlocale(LC_ALL, "");
	// n = printf("%-30.30f %-10.30f %-30.10f\n", -1212.2512312312, 12.2512312312, 12.2512312312);
	// n = ft_printf("%-30.30f %-10.30f %-30.10f\n", -1212.2512312312, 12.2512312312, 12.2512312312);
	// printf("\n");
	// n = printf("%30.30e %#10.30e %30.10e\n", -125645363.25, -12.25, -122.251);
	// printf("%d\n", n);
	// n = ft_printf("%30.30e %#10.30e %30.10e\n", -125645363.25, -12.25, -122.251);
	// printf("%d\n", n);
	// n = printf("%10.12g %#10.30g %0.10g\n", -12345678.234567, -12.25, -12.25);
	// printf("%d\n", n);
	// n = ft_printf("%30.30e %#10.30e %30.10e\n", -125645363.25, -12.25, -122.251);
	// printf("%d\n", n);
	n = printf("%50.100e %10.30g %0.10g\n", -0.000234567, -0.001451225, 0.1225);
	// printf("%d\n", n);
	n = ft_printf("%50.100e %10.30g %0.10g\n", -0.000234567, -0.001451225, 0.1225);
	// printf("%d\n", n);
	// n =	printf("%10.30g\n", -12.25);
	// printf("%d\n", n);
	// n =	ft_printf("%10.30g\n", -12.25);
	// printf("%d\n", n);
	n = printf("%30.30g\n", 123456789.123456789101112);
		printf("%d\n", n);
	n = ft_printf("%30.30g\n", 123456789.123456789101112);
		printf("%d\n", n);
	n = printf("%30.10g\n",  1221.2545);
	n = ft_printf("%30.10g\n", 1221.2545);
	// n = printf("%30.10e\n",  -122.251);
	// printf("%d\n", n);
	// n = ft_printf("%30.10e\n",  -122.251);
  // printf("%d\n", n);
  // n = printf("%#300.10%\n");
	// printf("%d\n", n);
  // n = ft_printf("%#300.10%\n");
    // printf("%d\n", n);
	// printf("%#010X\n",1254);
	// ft_printf("%#010X\n",1254);
// //   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
 // n = printf("Voici le string : [%f %e %g ]\n", 12.34, 12334.334, 1203.3434340);
 // printf("%d\n", n);
 // n = ft_printf("Voici le string : [%f %e %g ]\n", 12.34, 12334.334, 1203.3434340);
// printf("%d\n", n);
// n = printf("Voici le string : [%C %C %S %C %C]\n", 140, L'ੳ', L"ੳੳੳੳੳ", 244, 130);
// printf("%d\n", n);
// printf("\n");
// n = ft_printf("Voici le string : [%C %C %S %C %C]\n", 140, L'ੳ', L"ੳੳੳੳੳ", 244, 130);
// printf("%d\n", n);
 // printf("\n");
 return (0);

}
//
// void		ft_display_arg_g_dash(t_type *lst, double n)
// {
// 	ft_flags_sign(lst, n);
//
// 	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
// 	{
// 		ft_memset_g_set(g_str, '0', PMFW - SIZE);
// 		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
// 			ft_putstr_float_g(n, lst);
// 		ft_display_mfw(lst);
// 		ft_memset_g_set(g_str, ' ', MFW - PMFW);
// 	}
// 	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
// 	{
// 		ft_memset_g_set(g_str, '0', PMFW - SIZE);
// 		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
// 			ft_putstr_float_g(n, lst);
// 	}
// 	else if (MFW > SIZE && PMFW < SIZE)
// 	{
// 		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
// 			ft_putstr_float_g(n, lst);
// 		ft_display_mfw(lst);
// 		ft_memset_g_set(g_str, ' ', MFW - SIZE);
// 	}
// 	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
// 		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
// 			ft_putstr_float_g(n, lst);
// }
