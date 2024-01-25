/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 01:24:59 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_vec(t_program *game)
{
	game->player->pos.x = game->map->start_x;
	game->player->pos.y = game->map->start_y;
	if (game->map->s_direc == NORTH || game->map->s_direc == SOUTH)
	{
		game->player->dir.x = game->player->pos.x;
		if (game->map->s_direc == NORTH)
			game->player->dir.y = game->player->pos.y + GRID_SIZE * 3;
		else
			game->player->dir.y = game->player->pos.y - GRID_SIZE * 3;
	}
	else if (game->map->s_direc == EAST || game->map->s_direc == WEST)
	{
		game->player->dir.y = game->player->pos.y;
		if (game->map->s_direc == WEST)
			game->player->dir.x = game->player->pos.x + GRID_SIZE * 3;
		else
			game->player->dir.x = game->player->pos.x - GRID_SIZE * 3;
	}
}
t_vector rotate_vector(t_vector pivot, t_vector v ,double theta)
{
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    double newX = (v.x - pivot.x) * cosTheta - (v.y - pivot.y) * sinTheta + pivot.x;
    double newY = (v.x - pivot.x) * sinTheta + (v.y - pivot.y) * cosTheta + pivot.y;

    t_vector rotatedVector = {newX, newY};
    return (rotatedVector);
}
