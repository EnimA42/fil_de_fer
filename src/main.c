/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:31:04 by aderragu          #+#    #+#             */
/*   Updated: 2016/09/06 13:57:41 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				key_func(int key, void *param)
{
	printf("%d", key);
	if (key == 53)
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


void ligne(char *image, int col, int xi,int yi,int xf,int yf)
{
	int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
  if ( dx > dy ) {
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) {
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx ) {
        cumul -= dx ;
        y += yinc ; }
      put_pixel(image, x, y, col) ; } }
    else {
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += xinc ; }
      put_pixel(image, x, y, col) ; } }
}

void colonne(char *image, int col, int xi,int yi,int xf,int yf)
{
	int dx,dy,cumul,x,y ;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	cumul = dx / 2;
	y = yi + 1;
	while (y <= yf) 
	{
 		cumul += dx;
		if ( cumul >= dy )
		{
			cumul -= dx;
			y += 1; 
		}
		put_pixel(image, x, y, col);
		y++; 
	}
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
	t_list		*elem;
	t_list		*elem2;

	if (argc == 1)
		return (0);
	begin = create_list(begin);
	begin = recup_map(begin, argv);
	//add_point(begin);
	elem = begin->next;
	data.init = mlx_init();
	data.win = mlx_new_window(data.init, 400, 400, "test");
	data.img = mlx_new_image(data.init, 400, 400);
	image = mlx_get_data_addr(data.img, &c, &l, &e);
	while (elem)
	{
		put_pixel(image, elem->x, elem->y, col);
		if (elem->next && elem->y != elem->next->y - ZOOM)
			ligne(image, col, elem->x, elem->y, elem->next->x, elem->next->y);
		elem2 = elem->next;
		while (elem2 && elem2->x != elem->x && elem2->y != elem2->y + 1)
			elem2 = elem2->next;
		if (elem2)
			ligne(image, col, elem->x, elem->y, elem2->x, elem2->y);
		elem = elem->next;
	}
	mlx_put_image_to_window(data.init, data.win, data.img, 1, 1);
	mlx_key_hook(data.win, key_func, &data);
	mlx_loop(data.init);
	return (0);
}
