/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:15:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/22 16:10:49 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_start_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

void	define_direction(char c, t_map *map)
{
	if (c == 'N')
		map->s_direc = NORTH;
	if (c == 'S')
		map->s_direc = SOUTH;
	if (c == 'W')
		map->s_direc = WEST;
	if (c == 'E')
		map->s_direc = EAST;
}

char	**ft_arrdup(char **arr)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	if (!tmp)
		return (NULL);
	while (arr[i])
	{
		tmp[i] = ft_strdup(arr[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

bool	check_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == 'X')
			return (false);
		i++;
	}
	i = 0;
	while (map[i])
	{
		j = ft_strlen_cub(map[i]) - 1;
		if (map[i][j] == 'X')
			return (false);
		i++;
	}
	return (true);
}

bool	check_top_bottom(char **map)
{
	int	j;
	int	i;

	j = 0;
	i = ft_arrlen(map) - 1;
	while (map[0][j])
	{
		if (map[0][j] == 'X')
			return (false);
		j++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == 'X')
			return (false);
		j++;
	}
	return (true);
}
