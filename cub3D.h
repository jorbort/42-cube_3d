/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:05 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/15 19:34:41 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_data
{
	char	*map_path;
}	t_data;

typedef struct s_program
{
	struct t_program	*data;
	struct t_map		*map;

}	t_program;

#endif