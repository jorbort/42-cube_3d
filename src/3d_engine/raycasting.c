/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/30 00:01:18 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// Function to rotate vector A around vector b by an angle of theta degrees
t_vector	rotate_vector(t_vector A, t_vector pivot, float theta)
{
	t_vector	res;

	theta *= -1;
	res.x = round((A.x - pivot.x) * cos(theta) - (A.y - pivot.y) \
		* sin(theta) + pivot.x);
	res.y = round((A.x - pivot.x) * sin(theta) + (A.y - pivot.y) \
		* cos(theta) + pivot.y);
	return (res);
}

// Function to move along an angle
void	move_along_angle(t_program *game, double theta, int distance)
{
	int	x;
	int	y;

	x = distance * cos(theta);
	y = distance * sin(theta);
	game->player->pos.y += x;
	game->player->pos.x += y;
	game->player->dir.y += x;
	game->player->dir.x += y;
	return ;
}

//Check theta limits
void	circle_control(t_program *game, double theta)
{
	game->player->orientation += theta;
	if (game->player->orientation > 2 * M_PI)
		game->player->orientation -= 2 * M_PI;
	else if (game->player->orientation < 0)
		game->player->orientation += 2 * M_PI;
}