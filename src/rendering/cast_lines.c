/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm < juan-anm@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:40:14 by juanantonio       #+#    #+#             */
/*   Updated: 2024/02/06 00:00:20 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// check the intersection
int	inter_check(float angle, float *inter, float *step, int is_horizon)
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

// get the horizontal intersection
// check x_step value
// check the wall hit whit the pixel value and return hypotenuse length
// if wall hit activate ray flag to cast rays in minimap
float	get_h_inter(t_program *game, float angl)
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
	if ((unit_circle(angl, 'y') && x_step > 0)
		|| (!unit_circle(angl, 'y') && x_step < 0)) 
		x_step *= -1;
	while (!wall_hit(h_x, h_y - pixel, game))
	{
		h_x += x_step;
		h_y += y_step;
	}
		game->rays->end_point_x.x = h_x;
		game->rays->end_point_x.y = h_y;
	if (wall_hit(h_x, h_y - pixel, game) == 3)
		game->rays->hit = 1;
	return (sqrt(pow(h_x - game->player->pos.x, 2)
			+ pow(h_y - game->player->pos.y, 2)));
}

// get the vertical intersection asame functionality as above but vertical 
float	get_v_inter(t_program *game, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = GRID_SIZE; 
	y_step = GRID_SIZE * tan(angl);
	v_x = floor(game->player->pos.x / GRID_SIZE) * GRID_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0); 
	v_y = game->player->pos.y + (v_x - game->player->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0)
		|| (!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (!wall_hit(v_x - pixel, v_y, game))
	{
		v_x += x_step;
		v_y += y_step;
	}
		game->rays->end_point_y.x = v_x;
		game->rays->end_point_y.y = v_y;
	if (wall_hit(v_x, v_y - pixel, game) == 3)
		game->rays->hit = 1;
	return (sqrt(pow(v_x - game->player->pos.x, 2)
			+ pow(v_y - game->player->pos.y, 2)));
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
		render_wall(game, rayito);
		rayito++;
		game->rays->r_angle += (game->player->fov / WIN_WIDTH);
	}
}

