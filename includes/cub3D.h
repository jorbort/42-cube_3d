/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:05 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 17:27:14 by jbortolo         ###   ########.fr       */
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
# include <string.h>
# include <ctype.h> 

# define M_PI 3.14159265358979323846264338327950288
# define ROT_1 0.196349540849362
# define FOV 60

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define L_ARROW 123
# define R_ARROW 124
# define ESC 53
# define GRID_SIZE 16
# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000

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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	double		orientation;
	double		fov;
}	t_player;
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
	int		hex_ceil;
	int		hex_floor;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
}	t_data;

typedef struct s_rays
{
	int			index;	
	double		r_angle;
	double		r_length;
	t_vector	end_point_x;
	t_vector	end_point_y;
	bool		flag;
	bool		hit;
}	t_rays;

typedef struct s_xpm
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_xpm;

typedef struct s_sprites
{
	t_xpm	*no_sprite;
	t_xpm	*so_sprite;
	t_xpm	*we_sprite;
	t_xpm	*es_sprite;
}	t_sprites;

typedef struct s_program
{
	t_data		*data;
	t_map		*map;
	t_player	*player;
	t_img		*img;
	t_sprites	*sprites;
	t_rays		*rays;
}	t_program;

//inits.c//
void		init_structs(t_program *game);
//map.c
void		get_map(t_map *map, char *path);
void		ft_map_error(int num_error);
bool		check_map_ext(char *path, char *ext);
bool		check_map(t_program *game);
void		parse_map(t_map *map, char *path, t_program *game);
//map_utils.c
bool		get_rgb(t_map *map, t_data *data);
void		trim_file(t_map *map);
int			ft_arrlen(char **s);
//epurstr
char		*ft_epurstr(char *str);
//keymaping.c
int			deal_key(int key, t_program *game);
int			deal_key_2(int key, t_program *game);
//main.c
int			end_game(t_program *game);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		my_mlx_pixel_put2(t_program *game, int x, int y, int color);
void		print_grid(t_program *game);
//utils.c
void		free_double_arr(char **arr);
bool		not_valid_char(char c);
int			ft_strlen_cub(char *s);
bool		is_invalid(char c);
//textures_handling.c
void		get_textures(t_map *map, t_data *data, t_program *game);
void		get_sprites_pointers(t_sprites *sprites, t_data *data);
void		check_valid_path(t_data *data);
//map_error.c
void		ft_map_error(int num_error);
void		print_error(char *str);
//map_checks.c       
bool		check_walls(t_map *map);
int			is_valid_cell(char **mapa, int row, int col);
//map_utils2.c
bool		check_top_bottom(char **map);
bool		check_sides(char **map);
void		define_direction(char c, t_map *map);
char		**ft_arrdup(char **arr);
bool		is_start_char(char c);
//calc.c
int			ft_longest(char **map);
//colision.h
int			is_in_bounds(t_vector test, t_program *game);
int			test_move_along_angle(t_program *game, double theta, int distance);
//rendering_minimap.c
void		print_grid(t_program *game);
//rendering_minimap_2.c
void		draw_filled_circle(void *win, int xc, int yc);
void		ft_put_2d_walls(t_program *game, t_img *img);
//color_floor_cieling.c
void		color_map(t_program *game, t_img *img);
//raycasting.c
void		init_vec(t_program *game);
void		circle_control(t_program *game, double theta);
t_vector	rotate_vector(t_vector A, t_vector pivot, float theta);
void		move_along_angle(t_program *game, double theta, int distance);
double		to_degrees(double radians);
double		to_radians(int degrees);
//cast_lines.c
void		loop_caster(t_program *game);
//draw_lines.c
void		draw_line(t_img *img, t_program *game, t_vector start, \
			t_vector end);
//cast_walls.c
void		render_wall(t_program *game, int ray);
float		control_angle(float angle);
int			unit_circle(float angle, char c);
int			wall_hit(float x, float y, t_program *game);
int			unit_circle(float angle, char c);

//mouse_maping.c
int			mouse_moving(int x, int y, t_program *game);

#endif