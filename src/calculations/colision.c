/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 19:25:39 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_in_bounds(t_vector test, t_program *game)
{
	int	max;
	int	may;

	max = (test.x) / GRID_SIZE;
	may = (test.y) / GRID_SIZE;
	printf("%i max %i may \n", max, may);
	if (game->map->map[may][max] == '1' ||
		game->map->map[may][max + 1] == '1' ||
		game->map->map[may + 1][max] == '1' ||
		game->map->map[may - 1][max] == '1' ||
		game->map->map[may][max - 1] == '1')
		return (1);
	else
		return (0);
}

t_vector	test_move_along_angle(t_program *game, double theta, int distance)
{
	t_vector	test_pos;

	test_pos.x = (distance * cos(theta));
	test_pos.y = (distance * sin(theta));
	test_pos.x += game->player->pos.x;
	test_pos.y += game->player->pos.y;
	return (test_pos);
}
