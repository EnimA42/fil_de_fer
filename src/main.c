/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:31:04 by aderragu          #+#    #+#             */
/*   Updated: 2016/07/23 18:41:03 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				key_func(int key, void *param)
{
	printf("je rentre %d\n", key);
	return (1);
}

int 			main()
{
	void		*mlx_i;
	void		*win;
	t_list		*begin;

	begin = create_list(begin);
	recup_map(&begin, argv);
	mlx_i = mlx_init();
	win = mlx_new_window(mlx_i, 400, 400, "test");
	mlx_key_hook(win, key_func, 0);
	mlx_loop(mlx_i);
	return (0);
}
