/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:16:31 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/20 17:11:59 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
		if (!is_valid_char(map->map[0][j]))
			return (false);
		if (map->map[0][i] == ' ' && !is_valid_char(map->map[1][i]))
			return (false);
		if (map->map[0][i] == ' ' && !is_valid_char(map->map[0][i + 1]))
			return (false);
		i++;
	}
	i = ft_arrlen(map->map) - 1;
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
/*bool	check_sides(t_map *map)
{
	 int	i;
	 int	j;

	 i = 0;
	 j = 0;
	 while (map->map[i])
	 {
		while(map->map[i][j])
		{
			if (!is_valid_char(map->map[i][j]))
			i++;
		}
		j++;
	 }
}*/

bool	check(char **map)
{
	static int	i = 0;
	static int	j = 0;

	while (map[i])
	{
		while (map[i][j])
		{
			while (map[i][j] == ' ' || map[i][j] == '\t')
				j++;
			if (i == 0 || i == (ft_arrlen(map) - 1))
				if (!is_valid_char(map[i][j]))
					return (false);
			
		}
	}

}

bool	check_walls(t_map *map)
{
	if (!check_top_bottom(map))
		ft_map_error(4);
	/*if (!check_sides(map))
		ft_map_error(4);*/
	return (true);
}
