/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42barcelona.    +#+  +:+       +#+        */
/*                                       			+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:50 by juan-anm          #+#    #+#             */
/*   Updated: 2024/02/02 18:18:20 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void draw_wall(t_program *game, int ray, int t_pix, int b_pix) // draw the wall
{
	while (t_pix < b_pix)
		my_mlx_pixel_put(game->img, ray, t_pix++, 0x0000FF);
}

void render_wall(t_program *game, int ray) // render the wall
{
	double wall_h;
	double b_pix;
	double t_pix;

game->rays->r_length *= cos(control_angle(game->rays->r_angle - game->player->orientation)); // fix the fisheye
 wall_h = (GRID_SIZE /game->rays->r_length) * ((WIN_WIDTH / 2) / tan(game->player->fov / 2)); // get the wall height
 b_pix = (WIN_HEIGHT / 2) + (wall_h / 2); // get the bottom pixel
 t_pix = (WIN_HEIGHT / 2) - (wall_h / 2); // get the top pixel
 if (b_pix > WIN_HEIGHT) // check the bottom pixel
	b_pix = WIN_HEIGHT;
 if (t_pix < 0) // check the top pixel
	t_pix = 0;
 draw_wall(game, ray, t_pix, b_pix); // draw the wall
}