/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_minimap_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:55:14 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 14:49:35 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	fill_square(int i, int j, int he, int wi, t_img *img)
{
	int	x;
	int	y;
	int	xlim;
	int	ylim;

	y = he * i;
	x = wi * j;
	xlim = x + wi;
	ylim = y + he;
	while (x <= xlim)
	{
		y = he * i;
		while (y <= ylim)
		{
			my_mlx_pixel_put(img, x, y, 0x000FFFFF);
			y++;
		}
		x++;
	}
}

void	ft_put_2d_walls(t_program *game, t_img *img, int he, int wi)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < ft_arrlen(game->map->map))
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == '1')
				fill_square(i, j, he, wi, img);
			j++;
		}
		i++;
	}
}

void	draw_horisontal_lines(void *win, int xc, int yc, int y)
{
	int	radius;
	int	i;

	radius = 2;
	i = xc - radius;
	while (i <= xc + radius)
	{
		my_mlx_pixel_put(win, i, yc + y, 0xFF0000);
		my_mlx_pixel_put(win, i, yc - y, 0xFF0000);
		i++;
	}
}

void	draw_cuadrant_lines(void *win, int xc, int yc, int y)
{
	int			i;
	static int	radius = 2;

	i = xc - y;
	while (i <= xc + y)
	{
		my_mlx_pixel_put(win, i, yc + radius, 0xFF0000);
		my_mlx_pixel_put(win, i, yc - radius, 0xFF0000);
		i++;
	}
}

void	draw_filled_circle(void *win, int xc, int yc)
{
	int	y;
	int	err;
	int	radius;

	y = 0;
	err = 0;
	radius = 2;
	while (radius >= y)
	{
		draw_horisontal_lines(win, xc, yc, y);
		draw_cuadrant_lines(win, xc, yc, y);
		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			radius -= 1;
			err -= 2 * radius + 1;
		}
	}
}
