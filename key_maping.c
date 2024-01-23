/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 13:26:10 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

bool	check_colission(int key, t_map *map, t_program *game, int mov)
{
	
}

int	deal_key(int key, t_program *game)
{
	if (key == LEFT)
	{
		if (check_colission(key, game->map, game, (game->map->cell_wi / 10)))
			game->map->start_x -= (game->map->cell_wi / 10);
		print_grid(game);
	}
	else if (key == RIGHT)
	{
		game->map->start_x += (game->map->cell_wi / 10);
		print_grid(game);
	}
	else if (key == DOWN)
	{
		game->map->start_y += (game->map->cell_he / 10);
		print_grid(game);
	}
	else if (key == UP)
	{
		game->map->start_y -= (game->map->cell_he / 10);
		print_grid(game);
	}
	if (key == ESC)
		end_game(game);
	return (0);
}
