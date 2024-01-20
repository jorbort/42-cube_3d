/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_maping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:25:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/20 13:11:51 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	deal_key(int key, t_program *game)
{
	/*if (key == LEFT || key == 0)
		move(map, map->sprites.player, LEFT);
	else if (key == RIGHT || key == 2)
		move(map, map->sprites.player, RIGHT);
	else if (key == DOWN || key == 1)
		move(map, map->sprites.player, DOWN);
	else if (key == UP || key == 13)
		move(map, map->sprites.player, UP);*/
	if (key == ESC)
		end_game(game);
	return (0);
}
