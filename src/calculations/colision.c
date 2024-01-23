/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 18:42:02 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_in_bounds(int x, int y, t_program *game)
{
	x = ceil(((x - (game->map->cell_wi / 2)) / game->map->cell_wi));
	y = ceil(((y - (game->map->cell_he / 2)) / game->map->cell_he));
	printf("x%d - y %d \n", x + 1, y + 1);
	return (game->map->map[y][x] == '0');
}

int	circle_colision(int circleX, int circleY, int radius, t_program *game)
{
    int minX = circleX - radius;
    int maxX = circleX + radius;
    int minY = circleY - radius;
    int maxY = circleY + radius;

	return (is_in_bounds(minX, minY, game) && is_in_bounds(maxX, maxY, game));
}
