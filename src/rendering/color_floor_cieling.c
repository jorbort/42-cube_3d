/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_floor_cieling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:50:31 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 19:55:47 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rgb_2_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	get_ceiling_floor_color(t_data *data)
{
	data->hex_ceil = rgb_2_hex(data->c_rgb[0], data->c_rgb[1], data->c_rgb[2]);
	data->hex_floor = rgb_2_hex(data->f_rgb[0], data->f_rgb[1], data->f_rgb[2]);
}

void	put_ceil(t_program *game, t_img *img, int *i)
{
	int	j;

	j = 0;
	while (*i < (WIN_HEIGHT / 2))
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, j, *i, game->data->hex_ceil);
			j++;
		}
		*i += 1;
	}
}

void	put_floor(t_program *game, t_img *img, int *i)
{
	int	j;

	j = 0;
	while (*i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, j, *i, game->data->hex_floor);
			j++;
		}
		*i += 1;
	}
}

void	color_map(t_program *game, t_img *img)
{
	int	i;

	i = 0;
	get_ceiling_floor_color(game->data);
	put_ceil(game, img, &i);
	put_floor(game, img, &i);
}
