/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 00:25:03 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	deal_key(int key, t_program *game)
{
	if (key == LEFT)// || key == 0)
	{
		game->map->start_x -= 10;
		print_grid(game);
	}
	else if (key == RIGHT)// || key == 2)
	{
		game->map->start_x += 10;
		print_grid(game);
	}
	else if (key == DOWN)// || key == 1)
	{
		game->map->start_y += 10;
		print_grid(game);
	}
	else if (key == UP)// || key == 13)
	{
		game->map->start_y -= 10;
		print_grid(game);
	}
	if (key == ESC)
		end_game(game);
	return (0);
}
