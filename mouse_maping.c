/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_maping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantoniomartinezmorales <juanantonio    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:43 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/29 00:40:29 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	mouse_moving(int x, int y, t_program *game)
{
	(void) y;
	if (x < (WIN_WIDTH / 2) + 600)
	{
		game->player->orientation -= ROT_1;
		print_grid(game);
	}
	else if (x > (WIN_WIDTH / 2) - 600)
	{
		game->player->orientation += ROT_1;
		print_grid(game);
	}
	return (0);
}
