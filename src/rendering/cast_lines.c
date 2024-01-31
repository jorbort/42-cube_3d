/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:14 by juanantonio       #+#    #+#             */
/*   Updated: 2024/01/31 01:24:43 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void draw_line(t_img *img, t_program *game, t_vector start, t_vector end)
{
    (void)game;
    int dx = end.x - start.x;
    int dy = end.y - start.y;
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
        my_mlx_pixel_put(img, round(x), round(y), 0x0000FFFF);
        x += x_increment;
        y += y_increment;
        i++;
    }
}

void loop_caster(t_program *game)
{
	t_player	play;
	t_vector	A;
	// t_vector	C;
	int			ya;
	double		xa;

	play = *game->player;
	if (play.orientation >= 0 && play.orientation <= M_PI)
	{
		A.y = floor(play.pos.y / GRID_SIZE) * (GRID_SIZE + GRID_SIZE);
		ya = -GRID_SIZE;
		play.orientation = play.orientation - M_PI;
	}
	else
	{
		A.y = floor(play.pos.y / GRID_SIZE) * GRID_SIZE - 1;
		ya = GRID_SIZE;
	}
	A.x = floor(play.pos.x + (play.pos.y - A.y)/tan(play.orientation));
	xa = floor(GRID_SIZE / tan(play.orientation));
	// C.x = A.x + xa;
	// C.y = A.y + ya;
	if (A.x / GRID_SIZE > game->map->width - 1 || A.y / GRID_SIZE > game->map->height - 2 || A.x / GRID_SIZE < 0 || A.y / GRID_SIZE < 0)
		return ;
	while (game->map->map[A.y / GRID_SIZE][A.x / GRID_SIZE] != '1')
	{
		A.x = floor(A.x + xa);
		A.y = floor(A.y + ya);
		printf("%i x %i y \n", A.x / GRID_SIZE, A.y / GRID_SIZE);
		if (A.x / GRID_SIZE > game->map->width - 1 || A.y / GRID_SIZE > game->map->height - 2 || A.x / GRID_SIZE < 0 || A.y / GRID_SIZE < 0)
			return ;
	}
		draw_line(game->img, game, game->player->pos, A);
		//if (game->map->map[A.y / GRID_SIZE][A.x / GRID_SIZE] != '1')
}

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	to_radians(int degrees)
{
	return ((M_PI / 180) * degrees);
}
