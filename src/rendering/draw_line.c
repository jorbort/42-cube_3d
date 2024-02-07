/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm < juan-anm@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:41:58 by juanantonio       #+#    #+#             */
/*   Updated: 2024/02/07 01:15:26 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_line(t_img *img, t_program *game, t_vector start, t_vector end)
{
	(void)game;

	int	dx = end.x - start.x;
	int	dy = end.y - start.y;
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
