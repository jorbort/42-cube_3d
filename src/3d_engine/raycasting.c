/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 19:19:23 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_vec(t_program *game)
{
	game->vector->player_x = game->map->start_x;
	game->vector->player_y = game->map->start_y;
	game->vector->dir_x = 0;
	game->vector->dir_y = 1;
	game->vector->plane_right_x = 0;
	game->vector->plane_right_y = 0.66;
	game->vector->fr_time = 0;
	game->vector->prev_fr_time = 0;

}

void	cast_ray(t_program *game)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		x;
	int		w;

	w = ft_longest(game->map->map);
	while (x < w)
	{
		camera_x = 2 * x / (double)w - 1;
		ray_dir_x = game->vector->dir_x + game->vector->plane_right_x * camera_x;
		ray_dir_y = game->vector->dir_y + game->vector->plane_right_y * camera_x;
	}

}