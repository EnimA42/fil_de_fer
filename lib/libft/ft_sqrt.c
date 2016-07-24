/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:47:22 by aderragu          #+#    #+#             */
/*   Updated: 2015/12/23 11:48:10 by aderragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_sqrt(int nb)
{
	float	cnt;
	float	res;

	res = 0;
	cnt = 1;
	if (nb <= 0)
		return (0);
	while (cnt * cnt < nb * 10000)
	{
		cnt++;
		res++;
	}
	return (res / 100);
}