/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:31:04 by aderragu          #+#    #+#             */
/*   Updated: 2016/07/23 18:28:38 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		main(int argc, char **argv)
{
	t_list	*begin;
	void	*mlx_i;
	void	*win;

	begin = create_list(begin);
	recup_map(&begin, argv);
	mlx_i = mlx_init();
	win = mlx_new_window(mlx_i, 400, 400, "test");
	mlx_loop(mlx_i);
	return (0);
}
