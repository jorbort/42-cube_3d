/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 01:02:58 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_in_bounds(t_vector test, t_program *game)
{
	int	max;
	int	may;
	int	mix;
	int	miy;

	max = (test.x + 8) / GRID_SIZE;
	may = (test.y + 8) / GRID_SIZE;
	mix = (test.x - 8) / GRID_SIZE;
	miy = (test.y - 8) / GRID_SIZE;
	if (game->map->map[may][max] == '1' || game->map->map[may][mix] == '1' ||
		game->map->map[miy][max] == '1' || game->map->map[miy][mix] == '1')
		return (1);
	else
		return (0);
}

t_vector	test_move_along_angle(t_program *game, double theta, int distance) {
    
	t_vector test_pos;
	(void) game;

	test_pos.x = game->player->pos.x + (distance * cos(theta));
	test_pos.y = game->player->pos.y + (distance * sin(theta));
    return (test_pos);
}