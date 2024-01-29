/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 18:44:43 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// t_vector	rotate_vector(t_vector pivot, t_vector v, double theta)
// {
//     double		cos_theta;
//     double		sin_theta;
// 	double		new_x;
// 	t_vector	rotated_vector;
// 	double		new_y;

// 	cos_theta = cos(theta);
// 	sin_theta = sin(theta);
// 	new_x = (v.x - pivot.x) * cos_theta - (v.y - pivot.y) * sin_theta + pivot.x;
//     new_y = (v.x - pivot.x) * sin_theta + (v.y - pivot.y) * cos_theta + pivot.y;
//     rotated_vector.x = new_x;
// 	rotated_vector.y = new_y;
//     return (rotated_vector);
// }
// Function to calculate the dot product of two vectors
float dot_product(float x1, float y1, float x2, float y2) {
    return x1 * x2 + y1 * y2;
}

// Function to calculate the cross product of two vectors
float cross_product(float x1, float y1, float x2, float y2) {
    return x1 * y2 - x2 * y1;
}

// Function to rotate vector A around vector b by an angle of theta degrees
t_vector rotate_vector(t_vector A, t_vector pivot, float theta)
{
    t_vector result;

	theta *= -1;
	result.x = round((A.x - pivot.x) * cos(theta) - (A.y - pivot.y) * sin(theta) + pivot.x);
	result.y = round((A.x - pivot.x) * sin(theta) + (A.y - pivot.y) * cos(theta) + pivot.y);
	return (result);
}

// Function to move along an angle
void	move_along_angle(t_program *game, double theta, int distance)
{
	int	x;
	int	y;

	x = distance * cos(theta);
	y = distance * sin(theta);
	game->player->pos.y += x;
	game->player->pos.x += y;
	game->player->dir.y += x;
	game->player->dir.x += y;
	return ;
}

void	circle_control(t_program *game, double theta)
{
	game->player->orientation += theta;
	if (game->player->orientation > 2 * M_PI)
		game->player->orientation -= 2 * M_PI;
	else if (game->player->orientation < 0)
		game->player->orientation += 2 * M_PI;
}