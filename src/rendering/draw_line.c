/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:41:58 by juanantonio       #+#    #+#             */
/*   Updated: 2024/02/07 13:56:00 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_line(t_img *img, t_line *line, t_vector start, t_vector end)
{
	int	i;

	line = malloc(sizeof(t_line));
	i = 0;
	line->dx = end.x - start.x;
	line->dy = end.y - start.y;
	if (abs(line->dx) > abs(line->dy))
		line->steps = abs(line->dx);
	else
		line->steps = abs(line->dy);
	line->x_increment = (float)line->dx / (float)line->steps;
	line->y_increment = (float)line->dy / (float)line->steps;
	line->x = start.x;
	line->y = start.y;
	while (i <= line->steps)
	{
		my_mlx_pixel_put(img, round(line->x), round(line->y), 0x0000FFFF);
		line->x += line->x_increment;
		line->y += line->y_increment;
		i++;
	}
}
