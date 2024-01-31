/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:14 by juanantonio       #+#    #+#             */
/*   Updated: 2024/01/31 19:35:29 by juan-anm         ###   ########.fr       */
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

// void loop_caster(t_program *game)
// {
// 	t_player	play;
// 	t_vector	A;
// 	//t_vector 	new;
// 	// t_vector	C;
// 	int			ya;
// 	double		xa;

// 	play = *game->player;
// 	if (play.orientation >= 0 && play.orientation <= M_PI)
// 	{
// 		A.y = floor(play.pos.y / GRID_SIZE);
// 		A.y *= (GRID_SIZE + GRID_SIZE);
// 		ya = -GRID_SIZE;
// 	}
// 	else
// 	{
// 		A.y = floor(play.pos.y / GRID_SIZE);
// 		A.y *= (GRID_SIZE - 1);
// 		ya = GRID_SIZE;
// 		play.orientation = play.orientation + M_PI;
// 	}
// 	A.x = play.pos.x + (play.pos.y - A.y) / tan(play.orientation);
// 	xa = (GRID_SIZE / tan(play.orientation));
// 	if (A.x / GRID_SIZE > game->map->width - 1 || A.y / GRID_SIZE > game->map->height - 2 || A.x / GRID_SIZE < 0 || A.y / GRID_SIZE < 0)
// 		return ;
// 	int strlen = ft_strlen(game->map->map[A.y /GRID_SIZE]);
// 	while (strlen > A.x / GRID_SIZE && game->map->map[A.y / GRID_SIZE][A.x / GRID_SIZE] != '1')
// 	{
// 		A.x = A.x + xa;
// 		A.y = A.y - ya;
// 		strlen = ft_strlen(game->map->map[A.y /GRID_SIZE]);
// 		if (A.x / GRID_SIZE < game->map->width - 1 && A.y / GRID_SIZE < game->map->height - 2 && A.x / GRID_SIZE > 0 && A.y / GRID_SIZE > 0)
// 		{
// 			if (strlen > A.x / GRID_SIZE )
// 			{
// 				draw_line(game->img, game, game->player->pos, A);
// 				printf("%f x %f y \n", floor(A.x / GRID_SIZE), floor(A.y / GRID_SIZE));
// 			}	//new = A;
// 		}
// 		if (A.x / GRID_SIZE > game->map->width - 1 || A.y / GRID_SIZE > game->map->height - 2 || A.x / GRID_SIZE < 0 || A.y / GRID_SIZE < 0)
// 		 	break ;
// 	}
// }

void loop_caster(t_program *game)
{

	
}

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	to_radians(int degrees)
{
	return ((M_PI / 180) * degrees);
}
