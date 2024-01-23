/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:05 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/23 18:54:40 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

# define INVALID_CHAR "Map: invalid chars in  map"
# define RGB_RANGE "Invalid rgb: [0 - 255]"
# define PERIMETER_ERROR "Invalid map perimeter"
# define REAPEATED_START "More than one starting position"
# define MALLOC_ERROR "Failed malloc"

typedef enum s_direc
{
	NONE = 0,
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direc;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vec
{
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_left_x;
	double	plane_left_y;
	double	plane_right_x;
	double	plane_right_y;
	double	fr_time;
	double	prev_fr_time;
}	t_vec;
typedef struct s_map
{
	char	**map;
	int		start_x;
	int		start_y;
	int		height;
	int		width;
	int		cell_wi;
	int		cell_he;
	t_direc	s_direc;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		c_rgb[3];
	int		f_rgb[3];
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
}	t_data;

typedef struct s_program
{
	t_data		*data;
	t_map		*map;
	t_vec		*vector;

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
bool	get_rgb(t_map *map, t_data *data);
void	trim_file(t_map *map);
int		ft_arrlen(char **s);
//epurstr
char	*ft_epurstr(char *str);
//keymaping.c
int		deal_key(int key, t_program *game);
//main.c
int		end_game(t_program *game);

void	print_grid(t_program *game);

//utils.c
void	free_double_arr(char **arr);
bool	not_valid_char(char c);
int		ft_strlen_cub(char *s);
//textures_handling.c
void	get_textures(t_map *map, t_data *data);
//map_error.c
void	ft_map_error(int num_error);
void	print_error(char *str);
//map_checks.c
bool	check_walls(t_map *map);
int	is_valid_cell(char **mapa, int row, int col);
//map_utils2.c
bool	check_top_bottom(char **map);
bool	check_sides(char **map);
void	define_direction(char c, t_map *map);
char	**ft_arrdup(char **arr);
bool	is_start_char(char c);
//calc.c
void	calc_true_start(t_program *game);
//colision.h
int		circle_colision(int circleX, int circleY, int radius, t_program *game);

#endif