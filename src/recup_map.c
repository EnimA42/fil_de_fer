/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:33:23 by lbaudran          #+#    #+#             */
/*   Updated: 2016/09/09 12:36:40 by lbaudran         ###   ########.fr       */
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

t_list		*ft_join(t_list *begin, char **tmp, int y, t_data *data)
{
	int		i;
	t_list	*elem;
//	ZOOM = (MAX_LONGUEUR || MAX_LARGEUR) / 800;
	int z;
	i = 0;
	while (tmp[i])
	{
		elem = create_elem(begin);
		elem->base_x = i;
		elem->base_y = y;
//		z = rotation(begin, ft_atoi(tmp[i]));
		elem->z = ft_atoi(tmp[i]);
//		elem->x = (z_vue * ((i * ZOOM) - 800)) / (z_vue - elem->z) + z_vue;
//		elem->y = (z_vue * ((y * ZOOM) - 800)) / (z_vue - elem->z) + z_vue;
		i++;
	}// probleme pour zoom,hauteur calcule apres
	if (data->i != 0 && i != data->i)
		exit (write(1, "Error map", 9));
	data->i = i;
	free (tmp);
	return (begin);
}

t_list		*calcul_coord(t_list *begin, t_data *data)
{
	t_list		*elem;
//	int			zoom = data->i / 800; mauvais calcul
	int zoom = 800 / data->i;
	int			z_vue = 800;
	elem = begin->next;
	while (elem)
	{
		elem->x = (z_vue * ((elem->base_x * zoom) - 800)) / (z_vue - elem->z) + z_vue;
		elem->y = (z_vue * ((elem->base_y * zoom) - 800)) / (z_vue - elem->z) + z_vue;
		elem = elem->next;
	}
	return (begin);
}

t_list		*recup_map(t_list *begin, char **argv, t_data *data)
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
		begin = ft_join(begin, tmp, y, data);
		y++;
	}
	if (data->i < y)
		data->i = y;
	calcul_coord(begin, data);
	return (begin);
}
