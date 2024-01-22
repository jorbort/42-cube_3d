/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:15:16 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/22 14:39:10 by jbortolo         ###   ########.fr       */
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

char	**arrdup(char **arr)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char **) * ft_arrlen(arr));
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
