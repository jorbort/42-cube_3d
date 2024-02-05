/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:06:28 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/04 23:38:15 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_longest(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > len)
			len = j;
		i++;
	}
	return (len);
}

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	to_radians(int degrees)
{
	return ((M_PI / 180) * degrees);
}