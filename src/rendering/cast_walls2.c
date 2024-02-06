/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_walls2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:39:48 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 15:43:39 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	wall_hit(float x, float y, t_program *game)
{
	long	x_m;
	long	y_m;

	if (x < 0 || y < 0)
		return (1);
	x_m = floor (x / GRID_SIZE);
	y_m = floor (y / GRID_SIZE);
	if ((y_m >= game->map->height || x_m >= game->map->width))
		return (1);
	if (game->map->map[y_m] && x_m < (int)ft_strlen(game->map->map[y_m]))
	{
		if (game->map->map[y_m][x_m] == '1')
			return (3);
	}
	return (0);
}

float	control_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}
