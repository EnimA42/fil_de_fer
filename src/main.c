/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:31:04 by aderragu          #+#    #+#             */
/*   Updated: 2016/07/23 19:05:15 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				key_func(int key, void *param)
{
	if (key == 12)
	{
		mlx_destroy_window(((t_data*)param)->init, ((t_data*)param)->win);
		exit(1);
	}
	return (1);
}

int 			main(int argc, char **argv)
{
	t_data		data;
	t_list		*begin;

	data.init = mlx_init();
	data.win = mlx_new_window(data.init, 400, 400, "test");
	mlx_key_hook(data.win, key_func, &data);
	mlx_loop(data.init);
	if (argc == 1)
		return(0);
	begin = create_list(begin);
	//recup_map(begin, argv);
	return (0);
}
