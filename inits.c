/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:38:50 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/20 13:11:49 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	init_structs(t_program *game)
{
	t_data	*new_d;
	t_map	*new_m;

	new_d = malloc(sizeof(t_data));
	new_d->mlx = NULL;
	new_d->window = NULL;
	game->data = new_d;
	new_m = malloc(sizeof(t_map));
	game->map = new_m;
}
