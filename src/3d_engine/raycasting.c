/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:24 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/25 18:37:05 by juan-anm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


t_vector rotate_vector(t_vector pivot, t_vector v ,double theta)
{
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    double newX = (v.x - pivot.x) * cosTheta - (v.y - pivot.y) * sinTheta + pivot.x;
    double newY = (v.x - pivot.x) * sinTheta + (v.y - pivot.y) * cosTheta + pivot.y;

    t_vector rotatedVector = {newX, newY};
    return (rotatedVector);
}
