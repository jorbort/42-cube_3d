/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:33:59 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/20 13:11:09 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_textures(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(map->map[i], "NO", 2))
			data->n_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		else if (!ft_strncmp(map->map[i], "SO", 1))
			data->s_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		else if (!ft_strncmp(map->map[i], "WE", 1))
			data->w_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		else if (!ft_strncmp(map->map[i], "EA", 1))
			data->e_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		i++;
	}
}
