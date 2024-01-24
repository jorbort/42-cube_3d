/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:41 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 17:59:43 by jbortolo         ###   ########.fr       */
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
