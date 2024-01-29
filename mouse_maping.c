/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_maping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:43 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 13:26:17 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	mouse_moving_2(int x, int y, t_program *game, int *prev_x)
{
	if (x > (WIN_WIDTH / 2) + 200 && x > *prev_x + 20)
	{
		*prev_x = x;
		game->player->orientation -= ROT_1;
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI * 2) - ROT_1);
	}
	else if (x > (WIN_WIDTH / 2) + 200 && x < *prev_x - 20)
	{
		*prev_x = x;
		game->player->orientation += ROT_1;
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, ROT_1);
	}
	print_grid(game);
}

int	mouse_moving(int x, int y, t_program *game)
{
	static int	prev_x = 0;

	(void) y;
	if (x < (WIN_WIDTH / 2) - 200 && x < prev_x - 20)
	{
		prev_x = x;
		game->player->orientation += ROT_1;
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, ROT_1);
	}
	else if (x < (WIN_WIDTH / 2) - 200 && x > prev_x + 20)
	{
		prev_x = x;
		game->player->orientation -= ROT_1;
		game->player->dir = rotate_vector(game->player->dir,
				game->player->pos, (M_PI * 2) - ROT_1);
	}
	mouse_moving_2(x, y, game, &prev_x);
	return (0);
}
