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

void	*get_texture(t_program *game, int flag)
{
	game->rays->r_angle = nor_angle(game->rays->r_angle);
	if (flag == 0)
	{
		if (game->rays->r_angle > M_PI / 2 && game->rays->r_angle < 3 * (M_PI / 2))
			return (game->sprites->es_sprite);
		else
			return (game->sprites->we_sprite);
	}
	else
	{
		if (game->rays->r_angle > 0 && game->rays->r_angle < M_PI)
			return (game->sprites->so_sprite);
		else
			return (game->sprites->no_sprite);
	}
}

double	get_x_o(void	*texture, t_program *game)
{
	double	x_o;

	if (game->rays->flag == 1)
		x_o = (int)fmodf((mlx->ray->horiz_x * \
		(texture->width / TILE_SIZE)), texture->width);
	else
		x_o = (int)fmodf((mlx->ray->vert_y * \
		(texture->width / TILE_SIZE)), texture->width);
	return (x_o);
}

void	draw_wall(t_mlx *mlx, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture(mlx, mlx->ray->flag);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, mlx);
	y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		my_mlx_pixel_put(mlx, mlx->ray->index, t_pix, reverse_bytes \
		(arr[(int)y_o * texture->width + (int)x_o]));
		y_o += factor;
		t_pix++;
	}
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


// void draw_wall(t_program *game, int ray, int t_pix, int b_pix) // draw the wall
// {
// 	while (t_pix < b_pix)
// 		my_mlx_pixel_put(game->img, ray, t_pix++, 0x0000FF);
// }

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
 draw_wall(game, t_pix, b_pix, wall_h); // draw the wall
}

float	control_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

//checkl in **map index is wall is hit = 1
int wall_hit(float x, float y, t_program *game)
{
	long	x_m;
	long	y_m;

	if (x < 0 || y < 0)
		return (1);
	x_m = floor (x / GRID_SIZE);
	y_m = floor (y / GRID_SIZE);
	if ((y_m >= game->map->height || x_m >= game->map->width))
		return (1);
	if (game->map->map[y_m] && x_m < (int)ft_strlen(game->map->map[y_m]))
	{
		if (game->map->map[y_m][x_m] == '1')
			return (3);
	}
	return (0);
}
