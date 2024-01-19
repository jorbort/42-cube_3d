/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:31 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/19 20:21:32 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_char(char c)
{
	if (c != ' ' && c != '1')
		return (false);
	return (true);
}

bool	check_top_bottom(t_map *map)
{
	static int	i = 0;
	static int	j = 0;

	while (map->map[0][i])
	{
		if (!is_valid_char(map->map[i][j]))
			return (false);
		if (map->map[0][i] == ' ' && !is_valid_char(map->map[1][i]))
			return (false);
		if (map->map[0][i] == ' ' && !is_valid_char(map->map[0][i + 1]))
			return (false);
		i++;
	}
	i = ft_arrlen(map->map);
	while (map->map[i][j])
	{
		if (!is_valid_char(map->map[i][j]))
			return (false);
		if (map->map[i][j] == ' ' && !is_valid_char(map->map[i - 1][j]))
			return (false);
		if (map->map[i][j] == ' ' && !is_valid_char(map->map[i][j + 1]))
			return (false);
		j++;
	}
	return (true);
}

bool	check_walls(t_map *map)
{
	if (!check_top(map))
		return (false);
	if (!check_sides(map))
		return (false);
	return (true);
}
