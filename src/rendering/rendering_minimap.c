/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:49:41 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 14:49:36 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_vertical_lines_2_img(t_img *img, char **game_map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y <= (16 * ft_arrlen(game_map)))
	{
		i = 0;
		while (i <= (16 * 24))
		{
			my_mlx_pixel_put(img, i, y, 0x0000FFFF);
			i++;
		}
		y += 16;
	}
}

void	put_horizontal_lines_2_img(t_img *img, char **game_map)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (x <= (16 * 24))
	{
		j = 0;
		while (j <= (16 * ft_arrlen(game_map)))
		{
			my_mlx_pixel_put(img, x, j, 0x0000FFFF);
			j++;
		}
		x += 16;
	}
}

void	put_grid_2_img(t_img *img, char **game_map)
{
	put_vertical_lines_2_img(img, game_map);
	put_horizontal_lines_2_img(img, game_map);
}

void	print_grid(t_program *game)
{
	t_img	img;

	img.img = mlx_new_image(game->data->mlx, 1210, 1010);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_grid_2_img(&img, game->map->map);
	ft_put_2d_walls(game, &img, 16, 16);
	draw_filled_circle(&img, game->map->start_x, game->map->start_y);
	mlx_put_image_to_window(game->data->mlx, game->data->window, img.img, 0, 0);
}
