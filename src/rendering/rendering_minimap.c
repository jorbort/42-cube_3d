/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:49:41 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 16:34:24 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_vertical_lines_2_img(t_img *img, char **game_map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y <= (GRID_SIZE * ft_arrlen(game_map)))
	{
		i = 0;
		while (i <= (GRID_SIZE * ft_longest(game_map)))
		{
			my_mlx_pixel_put(img, i, y, 0X0000E6);
			i++;
		}
		y += GRID_SIZE;
	}
}

void	put_horizontal_lines_2_img(t_img *img, char **game_map)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (x <= (GRID_SIZE * ft_longest(game_map)))
	{
		j = 0;
		while (j <= (GRID_SIZE * ft_arrlen(game_map)))
		{
			my_mlx_pixel_put(img, x, j, 0X0000E6);
			j++;
		}
		x += GRID_SIZE;
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

	img.img = mlx_new_image(game->data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	game->img = &img;
	mlx_clear_window(game->data->mlx, game->data->window);
	color_map(game, &img);
	loop_caster(game);
	put_grid_2_img(&img, game->map->map);
	ft_put_2d_walls(game, &img);
	draw_filled_circle(&img, game->player->pos.x, game->player->pos.y);
	mlx_put_image_to_window(game->data->mlx, game->data->window, img.img, 0, 0);
	mlx_destroy_image(game->data->mlx, img.img);
}
