/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 00:35:27 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_in_bounds(int x, int y, t_program *game)
{
	int max = (x + 4) / 16;
	int may = (y + 4) / 16;
	int mix = (x - 4) / 16;
	int miy = (y - 4) / 16;
	
	if (game->map->map[may][max] == '1' || game->map->map[may][mix] == '1' ||
		game->map->map[miy][max] == '1' || game->map->map[miy][mix] == '1')
		return (1);
	else
		return (0);
}
