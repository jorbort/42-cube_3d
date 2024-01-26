/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_maping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:43 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 20:08:53 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	mouse_moving(int x, int y, t_program *game)
{
	if (x < (WIN_WIDTH / 2) + 600
		&& !is_in_bounds(game->map->start_x
			- (GRID_SIZE / 12), game->map->start_y, game))
	{
		game->player->orientation -= ROT_1;
		print_grid(game);
	}
	else if (x > (WIN_WIDTH / 2) - 600
		&& !is_in_bounds(game->map->start_x
			- (GRID_SIZE / 12), game->map->start_y, game))
	{
		game->player->orientation += ROT_1;
		print_grid(game);
	}
	return (0);
}
