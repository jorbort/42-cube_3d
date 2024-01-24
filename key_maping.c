/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 19:35:35 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	deal_key_2(int key, t_program *game)
{
	if (key == ESC)
		end_game(game);
	if (key == UP
		&& !is_in_bounds(game->map->start_x, game->map->start_y
			- (GRID_SIZE / 12), game))
	{
		game->map->start_y -= (GRID_SIZE / 12);
		print_grid(game);
	}
	else if (key == DOWN
		&& !is_in_bounds(game->map->start_x, game->map->start_y
			+ (GRID_SIZE / 12), game))
	{
		game->map->start_y += (GRID_SIZE / 12);
		print_grid(game);
	}
	return (0);
}

int	deal_key(int key, t_program *game)
{
	if (key == LEFT
		&& !is_in_bounds(game->map->start_x
			- (GRID_SIZE / 12), game->map->start_y, game))
	{
		game->map->start_x -= (GRID_SIZE / 12);
		print_grid(game);
	}
	else if (key == RIGHT
		&& !is_in_bounds(game->map->start_x
			+ (GRID_SIZE / 12), game->map->start_y, game))
	{
		game->map->start_x += (GRID_SIZE / 12);
		print_grid(game);
	}
	deal_key_2(key, game);
	return (0);
}
