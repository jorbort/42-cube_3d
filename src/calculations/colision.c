/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 20:16:40 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_in_bounds(t_vector test, t_program *game)
{
	int	max;
	int	may;

	max = (test.x) / GRID_SIZE;
	may = (test.y) / GRID_SIZE;
	if (game->map->map[may][max] == '1')
		return (1);
	else
		return (0);
}

int	test_move_along_angle(t_program *game, double theta, int distance)
{
	t_vector	test_pos;

	test_pos.x = round(distance * cos(theta));
	test_pos.y = round(distance * sin(theta));
	test_pos.x += game->player->pos.x;
	test_pos.y += game->player->pos.y;
	if (is_in_bounds(test_pos, game))
		return (1);
	else
		return (0);
}
