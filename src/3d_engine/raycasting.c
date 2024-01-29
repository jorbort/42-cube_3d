/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 00:30:36 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	// Convert angle to radians
   // float theta_radians = theta_degrees * M_PI / 180.0;
    
    // Calculate dot product of b and A
   // float dot = dot_product(pivot.x, pivot.y, A.x, A.y);
    
    // Calculate cross product of b and A
   // float cross = cross_product(pivot.x, pivot.y, A.x, A.y);
    
    // Calculate new position of A
	theta *= -1;
	result.x = (A.x - pivot.x) * cos(theta) - (A.y - pivot.y) * sin(theta) + pivot.x;
	result.y = (A.x - pivot.x) * sin(theta) + (A.y - pivot.y) * cos(theta) + pivot.y;
	return (result);
}

// Function to calculate the magnitude of a vector
double magnitude(t_vector vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

// Function to normalize a vector
t_vector normalize(t_vector vec) {
    double mag = magnitude(vec);
    t_vector normalized;
    normalized.x = vec.x / mag;
    normalized.y = vec.y / mag;
    return normalized;
}

// Function to move along an angle
void	move_along_angle(t_program *game, double theta, int distance) {
    
	int x = distance * cos(theta);
	int y = distance * sin(theta);;
	game->player->pos.y += x;
    game->player->pos.x += y;
	game->player->dir.y += x;
	game->player->dir.x += y;
    return ;
}

