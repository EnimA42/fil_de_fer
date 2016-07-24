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

int				put_pixel(char *image, int x, int y, int color)
{

	image[0 + x * 4 + y * 1600] = color >> 0;
	image[1 + x * 4 + y * 1600] = color >> 8;
	image[2 + x * 4 + y * 1600] = color >> 16;
	image[3 + x * 4 + y * 1600] = color >> 24;
	return (1);
}

int 			main(int argc, char **argv)
{
	t_data		data;
	t_list		*begin;
	char		*image;
	int			c = 0x00FFFFFF;
	int			col = 0x00FFFF00;
	int			l = 400;
	int			e = 0;
	int			x = 0;
	int			y = 0;

	data.init = mlx_init();
	data.win = mlx_new_window(data.init, 400, 400, "test");
	data.img = mlx_new_image(data.init, 400, 400);
	image = mlx_get_data_addr(data.img, &c, &l, &e);
	while (y < 400)
	{
		while (x < 400)
		{
			put_pixel(image, x, y, col);
			x++;

		}
		y++;
		x = 0;
		if (y > 100 && y < 200)
			col = 0x00FF0000;
		if (y >= 200 && y < 300)
			col = 0x000000FF;
		if (y >= 300)
			col = 0x0000FF00;
	}
	mlx_put_image_to_window(data.init, data.win, data.img, 1, 1);
	mlx_key_hook(data.win, key_func, &data);
	mlx_loop(data.init);
	if (argc == 1)
		return(0);
	begin = create_list(begin);
	//recup_map(begin, argv);
	return (0);
}
