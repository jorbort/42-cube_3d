/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_floor_cieling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:50:31 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 18:03:12 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	color_map(t_program *game, t_img *img)
{
	int	height;
	int	width;
	int i;
	int j;

	height = ft_arrlen(game->map->map);
	width = ft_longest(game->map->map);
	while (i < (height / 2))
	{
		j = 0;
		while ( j < width)
		{
			my_mlx_pixel_put(img , j, i, game->data->hex_ceil);
		}
	}
	while (i < height)
}
