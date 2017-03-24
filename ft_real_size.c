/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:00:28 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/24 02:08:59 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int			ft_real_size(t_type *lst, t_list *list)
// {
// 	int i;
//
// 	i = 0;
// 	if (lst->arg_type == 'c' && lst->pmfw > 1)
// 		lst->pmfw = 1;
// 	if (lst->mfw > list->content_size && lst->pmfw > list->content_size && lst->arg_type == 's')
// 		i = lst->mfw;
// 	else if (lst->mfw > lst->pmfw && lst->mfw > list->content_size)
// 		i = lst->mfw;
// 	else if (lst->pmfw > list->content_size && lst->mfw > list->content_size && lst->mfw == lst->pmfw)
// 		i = lst->pmfw;
// 	else if (lst->pmfw > lst->mfw && lst->pmfw > list->content_size)
// 		i = lst->pmfw;
// 	else
// 		i = list->content_size;
// 	// if ((*(char *)lst->content != '-')) &&
// 	// (list->pmfw >= lst->content_size)) //|| ((list->pmfw < lst->content_size) || list->pmfw == 0))
// 		// i += 1;
// 	return (i);
// }
