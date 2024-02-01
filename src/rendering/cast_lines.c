/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:14 by juanantonio       #+#    #+#             */
/*   Updated: 2024/02/01 18:09:54 by juanantonio      ###   ########.fr       */
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

float	control_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	unit_circle(float angle, char c) // check the unit circle
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int inter_check(float angle, float *inter, float *step, int is_horizon) // check the intersection
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += GRID_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += GRID_SIZE;
			return (-1);
		}
	*step *= -1;
	}
	return (1);
}

int wall_hit(float x, float y, t_program *game) // check the wall hit
{
	long	x_m;
	long	y_m;

	if (x < 0 || y < 0)
		return (1);
	x_m = floor (x / GRID_SIZE); // get the x position in the map
	y_m = floor (y / GRID_SIZE); // get the y position in the map
	if ((y_m >= game->map->height || x_m >= game->map->width))
		return (1);
	if (game->map->map[y_m] && x_m < (int)ft_strlen(game->map->map[y_m]))
	{
		if (game->map->map[y_m][x_m] == '1')
			return (3);
	}
	return (0);
}


float get_h_inter(t_program *game, float angl) // get the horizontal intersection
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = GRID_SIZE;
	x_step = GRID_SIZE / tan(angl);
	h_y = floor(game->player->pos.y / GRID_SIZE) * GRID_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = game->player->pos.x + (h_y - game->player->pos.y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
		x_step *= -1;
	while (!wall_hit(h_x, h_y - pixel, game)) // check the wall hit whit the pixel value
 	{
		h_x += x_step;
		h_y += y_step;
		game->rays->end_point_x.x = h_x;
		game->rays->end_point_x.y = h_y;
	}
	if (wall_hit(h_x, h_y - pixel, game) == 3)
		game->rays->hit = 1;
 	return (sqrt(pow(h_x - game->player->pos.x, 2) + pow(h_y - game->player->pos.y, 2))); // get the distance
}

float get_v_inter(t_program *game, float angl) // get the vertical intersection
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = GRID_SIZE; 
	y_step = GRID_SIZE * tan(angl);
	v_x = floor(game->player->pos.x / GRID_SIZE) * GRID_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
	v_y = game->player->pos.y + (v_x - game->player->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
		y_step *= -1;
	while (!wall_hit(v_x - pixel, v_y, game)) // check the wall hit whit the pixel value
	{
		v_x += x_step;
		v_y += y_step;
		game->rays->end_point_y.x = v_x;
		game->rays->end_point_y.y = v_y;
	}
	if (wall_hit(v_x, v_y - pixel, game) == 3)
		game->rays->hit = 1;
	return (sqrt(pow(v_x - game->player->pos.x, 2) + pow(v_y - game->player->pos.y, 2))); // get the distance
}

void loop_caster(t_program *game)
{
	double	hori_intersec;
	double	vert_intersec;
	int		rayito;

	rayito = 0;
	game->rays->r_angle = game->player->orientation - (game->player->fov / 2);
	while (rayito < WIN_WIDTH)
	{
		game->rays->flag = 0;
		game->rays->hit = 0;
		hori_intersec = get_h_inter(game, control_angle(game->rays->r_angle));
		vert_intersec = get_v_inter(game, control_angle(game->rays->r_angle));
		if (vert_intersec <= hori_intersec)
		{
			game->rays->r_length = vert_intersec;
		}
		else
		{
			game->rays->r_length = hori_intersec;
			game->rays->flag = 1;
		}
		if (game->rays->end_point_y.x < WIN_WIDTH && game->rays->end_point_y.y < WIN_HEIGHT && 
			game->rays->end_point_y.x >= 0 && game->rays->end_point_y.y >= 0)
		{
			if (vert_intersec <= hori_intersec)
				draw_line(game->img, game, game->player->pos, game->rays->end_point_y);
		}	
		if (game->rays->end_point_x.x < WIN_WIDTH && game->rays->end_point_x.y < WIN_HEIGHT && 
			game->rays->end_point_x.x >= 0 && game->rays->end_point_x.y >= 0)
		{
			if (vert_intersec > hori_intersec)
				draw_line(game->img, game, game->player->pos, game->rays->end_point_x);
		}
		//render_wall(mlx, ray);
		rayito++;
		game->rays->r_angle += (game->player->fov / WIN_WIDTH);
	}
}

double	to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	to_radians(int degrees)
{
	return ((M_PI / 180) * degrees);
}
