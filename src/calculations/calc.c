/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:06:28 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 13:08:19 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_longest(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > len)
			len = j;
		i++;
	}
	return (len);
}

void	calc_true_start(t_program *game)
{
	game->map->height = ft_arrlen(game->map->map);
	game->map->width = ft_longest(game->map->map);
	if (game->map->width > game->map->height)
	{
		game->map->cell_wi = 1200 / game->map->width;
		game->map->cell_he = 1000 / game->map->width;
		game->map->start_x = ((game->map->start_x * game->map->cell_wi) / 10)
			+ (game->map->cell_wi / 2);
		game->map->start_y = ((game->map->start_y * game->map->cell_he) / 10)
			+ (game->map->cell_he / 2);
	}
	else
	{
		game->map->cell_wi = 1200 / game->map->height;
		game->map->cell_he = 1000 / game->map->height;
		game->map->start_x = ((game->map->start_x * game->map->cell_wi) / 10)
			+ (game->map->cell_wi / 2);
		game->map->start_y = ((game->map->start_y * game->map->cell_he) / 10)
			+ (game->map->cell_he / 2);
	}
}

