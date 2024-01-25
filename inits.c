/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:38:50 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 19:53:58 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	init_structs(t_program *game)
{
	t_data	*new_d;
	t_map	*new_m;

	new_d = malloc(sizeof(t_data));
	new_d->mlx = NULL;
	new_d->window = NULL;
	game->data = new_d;
	new_m = malloc(sizeof(t_map));
	new_m->s_direc = NONE;
	game->map = new_m;
	game->player = malloc(sizeof(t_player));
}

void	init_vec(t_program *game)
{
	game->player->pos.x = game->map->start_x;
	game->player->pos.y = game->map->start_y;
	if (game->map->s_direc == NORTH)
		game->player->orientation = M_PI / 2;
	else if (game->map->s_direc == SOUTH)
		game->player->orientation = ((3 * M_PI) / 2);
	else if (game->map->s_direc == EAST)
		game->player->orientation = 0;
	else if (game->map->s_direc == WEST)
		game->player->orientation = M_PI;
}
