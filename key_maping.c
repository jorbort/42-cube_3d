/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 19:23:31 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	deal_key_2(int key, t_program *game)
{
	if (key == ESC)
		end_game(game);
	if (key == UP
		&& !is_in_bounds(game->player->pos.x, game->player->pos.y
			- (GRID_SIZE / 12), game))
	{
		game->player->pos.y -= (GRID_SIZE / 12);
		print_grid(game);
	}
	else if (key == DOWN
		&& !is_in_bounds(game->player->pos.x, game->player->pos.y
			+ (GRID_SIZE / 12), game))
	{
		game->player->pos.y += (GRID_SIZE / 12);
		print_grid(game);
	}
	return (0);
}

int	deal_key(int key, t_program *game)
{
	if (key == LEFT
		&& !is_in_bounds(game->player->pos.x
			- (GRID_SIZE / 12), game->player->pos.y, game))
	{
		game->player->orientation -= ROT_1;
		print_grid(game);
	}
	else if (key == RIGHT
		&& !is_in_bounds(game->player->pos.x
			+ (GRID_SIZE / 12), game->player->pos.y, game))
	{
		game->player->orientation += ROT_1;
		print_grid(game);
	}
	deal_key_2(key, game);
	return (0);
}
