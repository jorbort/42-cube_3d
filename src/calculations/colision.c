/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:22:32 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 11:34:28 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_in_bounds(int x, int y, t_program *game)
{
	int	max;
	int	may;
	int	mix;
	int	miy;

	max = (x + 4) / 16;
	may = (y + 4) / 16;
	mix = (x - 4) / 16;
	miy = (y - 4) / 16;
	if (game->map->map[may][max] == '1' || game->map->map[may][mix] == '1' ||
		game->map->map[miy][max] == '1' || game->map->map[miy][mix] == '1')
		return (1);
	else
		return (0);
}
