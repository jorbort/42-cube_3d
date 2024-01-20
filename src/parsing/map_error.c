/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:43:34 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/20 13:11:07 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_error(char *str)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
}

void	ft_map_error(int num_error)
{
	if (num_error == 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror(" ");
	}
	if (num_error == 2)
		print_error(INVALID_CHAR);
	if (num_error == 3)
		print_error(RGB_RANGE);
	if (num_error == 4)
		print_error(PERIMETER_ERROR);
	if (num_error == 5)
		print_error(INVALID_CHAR);
	exit(1);
}
