/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:47:58 by lbaudran          #+#    #+#             */
/*   Updated: 2016/07/26 18:11:38 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_list		*create_list(t_list *begin)
{
	begin = (t_list *)malloc(1 * sizeof(t_list));
	begin->prev = NULL;
	begin->next = NULL;
	begin->x = 0;
	begin->y = 0;
	return (begin);
}

t_list		*create_elem(t_list *begin)
{
	t_list	*elem;

	elem = begin;
	while (elem->next)
		elem = elem->next;
	elem->next = (t_list *)malloc(1 * sizeof(t_list));
	elem->next->x = 0;
	elem->next->y = 0;
	elem->next->prev = elem;
	elem->next->next = NULL;
	return (elem->next);
}
