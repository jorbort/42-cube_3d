/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:14 by juanantonio       #+#    #+#             */
/*   Updated: 2024/01/27 12:12:56 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void draw_line(t_img *img, t_program *game, t_vector start, t_vector end)
{
    (void)game;
	int dx = start.x - end.x;
    int dy = start.y - end.y;
    int steps;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
    float x_increment = (float)dx / (float)steps;
    float y_increment = (float)dy / (float)steps;

    float x = start.x;
    float y = start.y;

    int i = 0;
    while (i <= steps)
	{
        my_mlx_pixel_put(img, x, y, 0x0000FFFF);
        x += x_increment;
        y += y_increment;
	i++;
    }
}

void loop_caster(t_program *game)
{
	//double i;
//	double increments;
	//double theta;
//	t_vector vec;

	// i = (M_PI / 180) * (to_degrees(game->player->orientation) + 45);
	// increments = (M_PI / 180) * 60 / WIN_WIDTH;
	// while (i > (M_PI / 180) * (to_degrees(game->player->orientation) - 45))
	// {
		//vec = rotate_vector(game->player->pos, game->player->dir, i);
		draw_line(game->img, game, game->player->pos, game->player->dir);
	//	i = i - increments;
	// }
}

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}
