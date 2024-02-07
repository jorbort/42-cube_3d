/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/07 17:42:00 by juan-anm         ###   ########.fr       */
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
	int			i;	

	i = 0;
	while (i <= distance)
	{
		test_pos.x = round(i * cos(theta));
		test_pos.y = round(i * sin(theta));
		test_pos.x += game->player->pos.x;
		test_pos.y += game->player->pos.y;
		if (is_in_bounds(test_pos, game))
			return (1);
		i++;
	}
	return (0);
}
