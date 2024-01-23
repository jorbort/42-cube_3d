/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 00:28:11 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

/*bool	check_colission(int key, t_map *map, t_program *game, int mov)
{
	
}*/

int	deal_key(int key, t_program *game)
{

	if (key == LEFT && !is_in_bounds(game->map->start_x - 8, game->map->start_y, game))
	{
		game->map->start_x -= 8;
		print_grid(game);
	}
	else if (key == RIGHT && !is_in_bounds(game->map->start_x + 8, game->map->start_y, game))
	{
		game->map->start_x += 8;
		print_grid(game);
	}
	else if (key == DOWN && !is_in_bounds(game->map->start_x, game->map->start_y + 8, game))
	{
		game->map->start_y += 8;
		print_grid(game);
	}
	else if (key == UP && !is_in_bounds(game->map->start_x, game->map->start_y - 8, game))
	{
		game->map->start_y -= 8;
		print_grid(game);
	}
	if (key == ESC)
		end_game(game);
	return (0);
}
