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

int		rotation(t_list *begin, int z)
{
	double	m_rot_x[3][3];
	t_list	*tmp;
	int		x;
	int		y;
	int		ret_z;

	x = tmp->x;
	y = tmp->y;
	tmp = begin->next;
	m_rot_x[0][0] = 1;
	m_rot_x[0][1] = 0;
	m_rot_x[0][2] = 0;
	m_rot_x[1][0] = 0;
	m_rot_x[1][1] = cos(90);
	m_rot_x[1][2] = -sin(90);
	m_rot_x[2][0] = 0;
	m_rot_x[2][1] = sin(90);
	m_rot_x[2][2] = cos(90);
	while (tmp)
	{
		tmp->x = m_rot_x[0][0] * tmp->x + m_rot_x[0][1] * tmp->y + m_rot_x[0][2] * z;
		tmp->y = m_rot_x[1][0] * tmp->x + m_rot_x[1][1] * tmp->y + m_rot_x[1][2] * z;
		ret_z = m_rot_x[2][0] * tmp->x + m_rot_x[2][1] * tmp->y + m_rot_x[2][2] * z;;
		tmp = tmp->next;
	}
	return (ret_z);
}

t_list		*ft_join(t_list *begin, char **tmp, int y)
{
	int		i;
	t_list *elem;
	int z_vue = 200;
	int z;

	i = 0;
	while (tmp[i])
	{
		elem = create_elem(begin);
		elem->base_x = i;
		elem->base_y = y;
		z = rotation(begin, ft_atoi(tmp[i]));
		elem->x = (z_vue * ((i * ZOOM) - 200)) / (z_vue - z) + z_vue;
		elem->y = (z_vue * ((y * ZOOM) - 200)) / (z_vue - z) + z_vue;
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
	// while (elem)
	// {
	// 	printf("elem->x = %d ", elem->base_x);
	// 	printf("elem->y = %d ", elem->base_y);
	// 	printf("\n");
	// 	elem = elem->next;
	// }
	return (begin);
}
