/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:33:23 by lbaudran          #+#    #+#             */
/*   Updated: 2016/07/26 17:58:24 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_list		*ft_join(t_list *begin, char **tmp, int y)
{
	int		i;
	t_list *elem;
	int z_vue = 200;

	i = 0;
	while (tmp[i])
	{
		elem = create_elem(begin);
		elem->base_x = i;
		elem->base_y = y;
		elem->x = (z_vue * ((i*15) - 200)) / (z_vue + ft_atoi(tmp[i])) + z_vue;
		elem->y = (z_vue * ((y*15) - 200)) / (z_vue + ft_atoi(tmp[i])) + z_vue;
//		elem->x = (1 * ((i * 10) - 200 + 1)) / (1 + ft_atoi(tmp[i])) + 301;
//		elem->y = (1 * ((y * 10)- 200 + 1)) / (1 + ft_atoi(tmp[i])) + 301;
		i++;
	}
	free (tmp);
	return (begin);
}

t_list		*recup_map(t_list *begin, char **argv)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		y;
	t_list	*elem;

	elem = begin;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		begin = ft_join(begin, tmp, y);
		y++;
	}
	while (elem)
	{
		printf("elem->x = %d ", elem->base_x);
		printf("elem->y = %d ", elem->base_y);
		printf("\n");
		elem = elem->next;
	}
	return (begin);
}
