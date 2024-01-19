/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:05 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/19 12:50:52 by jbortolo         ###   ########.fr       */
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

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_data
{
	char	*map_path;
	void	*mlx;
	void	*window;
	int		c_rgb[3];
	int		f_rgb[3];
}	t_data;

typedef struct s_program
{
	t_data		*data;
	t_map		*map;

}	t_program;

//inits.c//
void	init_structs(t_program *game);

//map.c
void	get_map(t_map *map, char *path);
void	ft_map_error(int num_error);
bool	check_map_ext(char *path, char *ext);
bool	check_map(t_program *game);
void	parse_map(t_map *map, char *path, t_program *game);
//map_utils.c
void	get_rgb(t_map *map, t_data *data);
//epurstr
char	*ft_epurstr(char *str);
//keymaping.c
int		deal_key(int key, t_program *game);
//main.c
int		end_game(t_program *game);

#endif