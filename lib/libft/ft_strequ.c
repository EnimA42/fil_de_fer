/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:15:38 by aderragu          #+#    #+#             */
/*   Updated: 2015/11/26 19:15:40 by aderragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int	cpt;

	cpt = 0;
	while (s1[cpt] || s2[cpt])
	{
		if (((char*)s1)[cpt] != ((char*)s2)[cpt])
			return (0);
		cpt++;
	}
	return (1);
}
