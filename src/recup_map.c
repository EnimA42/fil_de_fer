/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:33:23 by lbaudran          #+#    #+#             */
/*   Updated: 2016/09/08 12:28:11 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*void		rotation(t_list *begin, int z)
{
	double m_rot_x[3][3];

	m_rot_x[0][0] = 1;
	m_rot_x[0][1] = 
	m_rot_x[0][2] = 
	m_rot_x[1][0] = 
	m_rot_x[1][1] = 
	m_rot_x[1][2] = 
	m_rot_x[2][0] = 
	m_rot_x[2][1] =
	m_rot_x[2][2] =  
}
*/
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
//		rotation(begin, ft_atoi(tmp[i]));
		elem->x = (z_vue * ((i * ZOOM) - 200)) / (z_vue - ft_atoi(tmp[i])) + z_vue;
		elem->y = (z_vue * ((y * ZOOM) - 200)) / (z_vue - ft_atoi(tmp[i])) + z_vue;
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

	elem = begin->next;

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
		if (elem->down)
		{
	 	printf("elem->x = %d //elem->down = %d", elem->base_x, elem->down->base_x);
	 	printf("elem->y = %d //elem->down = %d", elem->base_y, elem->down->base_y);
		}
	 	printf("\n");
	 	elem = elem->next;
	 }
	return (begin);
}
