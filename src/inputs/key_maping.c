/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 19:26:25 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	deal_key_3(int key, t_program *game)
{
	if (key == RIGHT
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation, GRID_SIZE), game))
	{
		move_along_angle(game, game->player->orientation, 8);
	}
	else if (key == LEFT
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation + M_PI, GRID_SIZE), game))
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
	else if (key == UP
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation + (M_PI / 2), GRID_SIZE), game))
	{
		move_along_angle(game, game->player->orientation + (M_PI / 2), 8);
	}
	else if (key == DOWN
		&& !is_in_bounds(test_move_along_angle(game,
				game->player->orientation + ((3 * M_PI) / 2), GRID_SIZE), game))
	{
		move_along_angle(game, game->player->orientation + ((3 * M_PI) / 2), 8);
	}
	deal_key_3(key, game);
	return (0);
}

int	deal_key(int key, t_program *game)
{
	if (key == L_ARROW)
	{
		circle_control(game, M_PI / 16);
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI / 16));
		printf("%f\n", to_degrees(game->player->orientation));
	}
	else if (key == R_ARROW)
	{
		circle_control(game, (M_PI / 16) * -1);
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI * 2) - (M_PI / 16));
	}
	deal_key_2(key, game);
	return (0);
}
