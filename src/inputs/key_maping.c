/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/01 18:16:25 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	deal_key_3(int key, t_program *game)
{
	double	ori;

	ori = game->player->orientation;
	if (key == UP && !test_move_along_angle(game, ori, GRID_SIZE / 2))
	{
		move_along_angle(game, ori, GRID_SIZE / 4);
	}
	else if (key == DOWN && !test_move_along_angle \
		(game, ori + M_PI, GRID_SIZE / 2))
	{
		move_along_angle(game, ori + M_PI, GRID_SIZE / 4);
	}
	print_grid(game);
	return (0);
}

int	deal_key_2(int key, t_program *game)
{
	double	ori;

	ori = game->player->orientation;
	if (key == ESC)
		end_game(game);
	else if (key == RIGHT && !test_move_along_angle \
		(game, ori + (M_PI / 2), GRID_SIZE / 2))
	{
		move_along_angle(game, ori + (M_PI / 2), GRID_SIZE / 4);
	}
	else if (key == LEFT && !test_move_along_angle \
		(game, ori + ((3 * M_PI) / 2), GRID_SIZE / 2))
	{
		move_along_angle(game, ori + ((3 * M_PI) / 2), GRID_SIZE / 4);
	}
	deal_key_3(key, game);
	return (0);
}

int	deal_key(int key, t_program *game)
{
	if (key == R_ARROW)
	{
		circle_control(game, M_PI / 16);
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI / 16));
		printf("%f\n", to_degrees(game->player->orientation));
	}
	else if (key == L_ARROW)
	{
		circle_control(game, (M_PI / 16) * -1);
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI * 2) - (M_PI / 16));
	}
	deal_key_2(key, game);
	return (0);
}
