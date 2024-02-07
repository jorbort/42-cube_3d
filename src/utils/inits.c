/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:38:50 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/07 13:50:39 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_sprites(t_program *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
		ft_map_error(7);
	game->sprites->es_sprite = malloc(sizeof(t_xpm));
	ft_memset(game->sprites->es_sprite, 0, sizeof(t_xpm));
	game->sprites->no_sprite = malloc(sizeof(t_xpm));
	ft_memset(game->sprites->no_sprite, 0, sizeof(t_xpm));
	game->sprites->so_sprite = malloc(sizeof(t_xpm));
	ft_memset(game->sprites->so_sprite, 0, sizeof(t_xpm));
	game->sprites->we_sprite = malloc(sizeof(t_xpm));
	ft_memset(game->sprites->we_sprite, 0, sizeof(t_xpm));
	if (!game->sprites->es_sprite || !game->sprites->no_sprite || \
		!game->sprites->so_sprite || !game->sprites->we_sprite)
		ft_map_error(7);
}

void	init_structs(t_program *game)
{
	t_data	*new_d;
	t_map	*new_m;

	new_d = malloc(sizeof(t_data));
	if (!new_d)
		ft_map_error(7);
	new_d->mlx = NULL;
	new_d->window = NULL;
	game->data = new_d;
	new_m = malloc(sizeof(t_map));
	if (!new_m)
		ft_map_error(7);
	game->map = new_m;
	game->map->s_direc = NONE;
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_map_error(7);
	game->rays = malloc(sizeof(t_rays));
	game->rays->hit = 0;
	if (!game->rays)
		ft_map_error(7);
	init_sprites(game);
}

void	init_vec(t_program *game)
{
	game->player->pos.x = game->map->start_x;
	game->player->pos.y = game->map->start_y;
	game->player->dir.x = game->map->start_x;
	game->player->dir.y = game->map->start_y;
	game->player->fov = (FOV * M_PI) / 180;
	if (game->map->s_direc == WEST)
	{
		game->player->dir.x -= GRID_SIZE;
		game->player->orientation = M_PI * 2;
	}
	else if (game->map->s_direc == EAST)
	{
		game->player->dir.x += GRID_SIZE;
		game->player->orientation = M_PI;
	}
	else if (game->map->s_direc == SOUTH)
	{
		game->player->dir.y += GRID_SIZE;
		game->player->orientation = M_PI / 2;
	}
	else if (game->map->s_direc == NORTH)
	{
		game->player->dir.y -= GRID_SIZE;
		game->player->orientation = ((3 * M_PI) / 2);
	}
}
