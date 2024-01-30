/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:14 by juanantonio       #+#    #+#             */
/*   Updated: 2024/01/30 01:09:53 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
        my_mlx_pixel_put(img,round(x), round(y), 0x0000FFFF);
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
	t_player	play;
	t_vector	A;
	t_vector	C;
	t_vector	D,H,J;
	int			ya;
	double		xa;

	play = *game->player;
	if (play.orientation >= 0 && play.orientation <= M_PI)
	{
		A.y = floor(play.pos.y / GRID_SIZE) * GRID_SIZE - 1;
		ya = - GRID_SIZE;
	}
	else
	{
		A.y = floor(play.pos.y / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		ya = GRID_SIZE;
	}
	A.x = play.pos.x + (play.pos.y - A.y)/tan(play.orientation);
	xa = GRID_SIZE / tan(play.orientation);
	C.x = A.x + xa;
	C.y = A.y + ya;
	D.x = C.x + xa;
	D.y = C.y + ya;
	H.x = D.x + xa;
	H.y = D.y + ya;
	J.x = H.x + xa;
	J.y = H.y + ya;
	draw_line(game->img, game, game->player->pos, D);
	//	i = i - increments;
	// }
	t_vector	B;

	if (play.orientation <= (3 * M_PI) / 2 && play.orientation >= M_PI / 2)
	{
		B.x = floor(play.pos.x / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		xa = -GRID_SIZE;
	}
	else
	{
		B.x = floor(play.pos.x / GRID_SIZE) * (GRID_SIZE) - 1;
		xa = GRID_SIZE;
	}
	B.y = play.pos.y + (play.pos.x - B.x) * tan(play.orientation);
	ya = GRID_SIZE * tan(play.orientation);
	//	draw_line(game->img, game, game->player->pos, B);


}

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	to_radians(int degrees)
{
	return ((M_PI / 180) * degrees);
}
