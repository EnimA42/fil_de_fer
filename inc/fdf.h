/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:34:29 by aderragu          #+#    #+#             */
/*   Updated: 2016/09/06 13:59:00 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <fcntl.h>
#include <libft.h>
#include <stdio.h>

typedef struct		s_list
{
	int				x;
	int				y;
	int				base_x;
	int				base_y;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct 		s_data
{
	void			*init;
	void			*win;
	void			*img;
}					t_data;

t_list				*create_list(t_list *begin);
t_list				*create_elem(t_list *begin);
t_list				*add_point(t_list *begin)

t_list				*ft_join(t_list *begin, char **tmp, int y);
t_list				*recup_map(t_list *begin, char **argv);

#endif
