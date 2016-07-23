/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:34:29 by aderragu          #+#    #+#             */
/*   Updated: 2016/07/23 18:28:05 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct		s_list
{
	int				x;
	int				y;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list		*create_list(t_list *begin);
t_list		*create_elem(t_list *begin);
char		*ft_str_alloc_cpy(char *tab, char *tmp);
char		**ft_join2(char **tab, char **tmp);
char		**ft_join(char **tab, char **tmp);
void		recup_map(t_list **begin, char **argv);


#endif
