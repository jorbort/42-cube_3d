/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm < juan-anm@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:31 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 23:06:53 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_valid_cell(char **mapa, int row, int col)
{
	return (row >= 0 && col < ft_strlen_cub(mapa[row])
		&& col >= 0 && row < ft_arrlen(mapa));
}

void	flood_fill(char **mapa, int y, int x)
{
	while (is_valid_cell(mapa, y, x) && (mapa[y][x] != '1'
		&& mapa[y][x] != 'X' ))
	{
		mapa[y][x] = 'X';
		flood_fill(mapa, y + 1, x);
		flood_fill(mapa, y - 1, x);
		flood_fill(mapa, y, x + 1);
		flood_fill(mapa, y, x - 1);
		flood_fill(mapa, y + 1, x + 1);
		flood_fill(mapa, y - 1, x - 1);
		flood_fill(mapa, y + 1, x - 1);
		flood_fill(mapa, y - 1, x + 1);
	}
}

bool	check_perimeter(char **mapa, int row, int col)
{
	char	**map_copy;

	map_copy = ft_arrdup(mapa);
	if (!map_copy)
		ft_map_error(7);
	flood_fill(map_copy, row, col);
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
			if (is_invalid(map->map[i][j]))
				ft_map_error(5);
			if (is_start_char(map->map[i][j]) && map->s_direc == NONE)
			{
				define_direction(map->map[i][j], map);
				map->start_x = j;
				map->start_y = i;
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
	if (!check_perimeter(map->map, map->start_y, map->start_x))
		ft_map_error(4);
	return (true);
}
