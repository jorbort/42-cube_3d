/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:31 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/22 16:20:12 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_valid_cell(char **mapa, int row, int col)
{
	return (row >= 0 && col < ft_strlen_cub(mapa[row])
		&& col >= 0 && row < ft_arrlen(mapa));
}

void	flood_fill(char **mapa, int x, int y)
{
	while (is_valid_cell(mapa, x, y) && (mapa[x][y] != '1'
		&& mapa[x][y] != 'X' ))
	{
		mapa[x][y] = 'X';
		flood_fill(mapa, x + 1, y);
		flood_fill(mapa, x - 1, y);
		flood_fill(mapa, x, y + 1);
		flood_fill(mapa, x, y - 1);
	}
}

bool	check_perimeter(char **mapa, int row, int col)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = ft_arrdup(mapa);
	if (!map_copy)
		ft_map_error(7);
	flood_fill(map_copy, row, col);
	while (map_copy[i])
		printf("%s\n", map_copy[i++]);
	if (!check_top_bottom(map_copy))
	{
		free_double_arr(map_copy);
		return (false);
	}
	if (!check_sides(map_copy))
	{
		free_double_arr(map_copy);
		return (false);
	}
	free_double_arr(map_copy);
	return (true);
}

void	get_starting_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_start_char(map->map[i][j]) && map->s_direc == NONE)
			{
				define_direction(map->map[i][j], map);
				map->start_x = i;
				map->start_y = j;
			}
			else if (is_start_char(map->map[i][j]) && map->s_direc != NONE)
				ft_map_error(6);
			j++;
		}
		i++;
	}
}

bool	check_walls(t_map *map)
{
	get_starting_pos(map);
	if (!check_perimeter(map->map, map->start_x, map->start_y))
		ft_map_error(4);
	return (true);
}
