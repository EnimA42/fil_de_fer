/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:33:23 by lbaudran          #+#    #+#             */
/*   Updated: 2016/07/23 18:29:56 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// char		*ft_str_alloc_cpy(char *tab, char *tmp)
// {
// 	tab = (char *)malloc(ft_strlen(tmp) + 1);
// 	ft_bzero(tab, ft_strlen(tmp + 1));
// 	ft_strcpy(tab, tmp);
// 	free(tmp);
// 	return (tab);
// }

// char		**ft_join2(char **tab, char **tmp)
// {
// 	char	**str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str = (char **)malloc(ft_strlen(tmp) + ft_strlen(tab) + 1);
// 	while (tab[i])
// 	{
// 		str[i] = ft_str_alloc_cpy(str[i], tmp[i]);
// 		i++;
// 	}
// 	while (tmp[j])
// 	{
// 		str[i++] = ft_str_alloc_cpy(str[j], tmp[j]);
// 		j++;
// 	}
// 	free(tab);
// 	free(tmp);
// 	return (str);

// }

// char		**ft_join(char **tab, char **tmp)
// {
// 	int		i;
// 	int		y;

// 	i = 0;
// 	y = 0;
// 	if (!tab)
// 	{
// 		tab = (char **)malloc(ft_strlen(tmp) + 1);
// 		while (tmp[i])
// 		{
// 			tab[i] = ft_str_alloc_cpy(tab[i], tmp[i]);
// 			i++;
// 		}
// 		free(tmp);
// 		return (tab);
// 	}
// 	return(ft_join2(tab, tmp));
// }

// void		recup_map(t_list **begin, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	char	**tab;
// 	int		i[2];
// 	t_list	*elem;

// 	fd = open(argv[0], O_RDONLY);
// 	while (get_next_line(fd, &line))
// 		tab = ft_join(tab, ft_strsplit(line, ' '));
// 	while (tab[i[0]])
// 	{
// 		while (tab[i[0]][i[1]])
// 		{
// 			elem = create_elem(begin);
// 			elem->x = i[0];
// 			elem->y = i[1];
// 			i[1]++;
// 		}
// 		i[0]++;
// 		i[1] = 0;
// 	}
// }
