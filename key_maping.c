/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 13:52:33 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	deal_key_3(int key, t_program *game)
{
	if (key == RIGHT
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation, 16), game))
	{
		move_along_angle(game, game->player->orientation, 8);
	}
	else if (key == LEFT
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation + M_PI, 16), game))
	{
		move_along_angle(game, game->player->orientation + M_PI, 8);
	}
	print_grid(game);
	return (0);
}

int	deal_key_2(int key, t_program *game)
{
	if (key == ESC)
		end_game(game);
	if (key == UP
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation + (M_PI / 2), 16), game))
	{
		move_along_angle(game, game->player->orientation + (M_PI / 2), 8);
	}
	else if (key == DOWN
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation + ((3 * M_PI) / 2), 16), game))
	{
		move_along_angle(game, game->player->orientation + ((3 * M_PI) / 2), 8);
	}
	return (0);
}

int	deal_key(int key, t_program *game)
{
	if (key == L_ARROW)
	{
		game->player->orientation += ROT_1;
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, ROT_1);
		printf("%f\n", to_degrees(game->player->orientation));
	}
	else if (key == R_ARROW)
	{
		game->player->orientation -= ROT_1;
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI * 2) - ROT_1);
	}
	deal_key_2(key, game);
	return (0);
}
