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

static int	get_px_color(t_xpm *img, int x, int y)
{
	char	*byte;

	byte = img->addr + ((y * img->line_len) + (x * img->bpp / 8));
	return (*(unsigned int *)byte);
}

t_xpm	*get_texture(t_program *game, int flag)
{
	game->rays->r_angle = control_angle(game->rays->r_angle);
	if (flag == 0)
	{
		if (game->rays->r_angle > M_PI / 2
			&& game->rays->r_angle < 3 * (M_PI / 2))
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

double	get_x_o(t_xpm	*texture, t_program *game)
{
	double	x_o;

	if (game->rays->flag == 1)
		x_o = (int)fmodf(((game->rays->end_point_x.x) * \
		(texture->width / GRID_SIZE)), texture->width);
	else
		x_o = (int)fmodf((game->rays->end_point_y.y * \
		(texture->width / GRID_SIZE)), texture->width);
	return (x_o);
}

void	draw_wall(t_program *game, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	t_xpm			*texture;
	double			factor;

	texture = get_texture(game, game->rays->flag);
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, game);
	y_o = (t_pix - (WIN_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		my_mlx_pixel_put(game->img, game->rays->index, t_pix,
			get_px_color(texture, x_o, y_o));
		y_o += factor;
		t_pix++;
	}
}

void	render_wall(t_program *game, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	game->rays->r_length *= cos(control_angle
			(game->rays->r_angle - game->player->orientation));
	wall_h = (GRID_SIZE / game->rays->r_length) * ((WIN_WIDTH / 2)
			/ tan(game->player->fov / 2));
	b_pix = (WIN_HEIGHT / 2) + (wall_h / 2);
	t_pix = (WIN_HEIGHT / 2) - (wall_h / 2);
	if (b_pix > WIN_HEIGHT)
		b_pix = WIN_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	game->rays->index = ray;
	draw_wall(game, t_pix, b_pix, wall_h);
}
