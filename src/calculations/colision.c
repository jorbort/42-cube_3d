/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 16:41:28 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_in_bounds(int x, int y, t_program *game)
{
	int	max;
	int	may;
	int	mix;
	int	miy;

	max = (x + 4) / GRID_SIZE;
	may = (y + 4) / GRID_SIZE;
	mix = (x - 4) / GRID_SIZE;
	miy = (y - 4) / GRID_SIZE;
	if (game->map->map[may][max] == '1' || game->map->map[may][mix] == '1' ||
		game->map->map[miy][max] == '1' || game->map->map[miy][mix] == '1')
		return (1);
	else
		return (0);
}
