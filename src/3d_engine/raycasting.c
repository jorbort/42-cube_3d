/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 20:05:23 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_vector	rotate_vector(t_vector pivot, t_vector v, double theta)
{
    double		cos_theta;
    double		sin_theta;
	double		new_x;
	t_vector	rotated_vector;
	double		new_y;

	cos_theta = cos(theta);
	sin_theta = sin(theta);
	new_x = (v.x - pivot.x) * cos_theta - (v.y - pivot.y) * sin_theta + pivot.x;
    new_y = (v.x - pivot.x) * sin_theta + (v.y - pivot.y) * cos_theta + pivot.y;
    rotated_vector.x = new_x;
	rotated_vector.y = new_y;
    return (rotated_vector);
}
