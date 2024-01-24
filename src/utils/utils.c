/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:34:01 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/24 15:53:11 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

bool	not_valid_char(char c)
{
	if (c != 'W' && c != 'N' && c != 'E' && c != 'S' && c != 'F' && c != 'C')
		return (true);
	return (false);
}

bool	is_invalid(char c)
{
	if (c != 'W' && c != 'N' && c != 'E' && c != 'S' && c != 'F'
		&& c != 'C' && c != '0' && c != '1' && c != ' ')
		return (true);
	return (false);
}

int	ft_strlen_cub(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}
