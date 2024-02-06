/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:33:59 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 13:44:04 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_valid_path(t_data *data)
{
	int	fd[4];
	int	i;

	i = 0;
	fd[0] = open(data->e_texture, O_RDONLY);
	fd[1] = open(data->n_texture, O_RDONLY);
	fd[2] = open(data->w_texture, O_RDONLY);
	fd[3] = open(data->s_texture, O_RDONLY);
	while (i < 4)
	{
		if (fd[i] < 0)
		{
			while (i > 0)
			{
				close(fd[i--]);
			}
			ft_map_error(1);
		}
		i++;
	}
	i = 3;
	while (i > 0)
		close (fd[i--]);
}

void	new_txt(void *mlx, char *path, t_xpm *texture)
{

	texture->mlx_img = \
	mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	if (!texture->mlx_img)
	{
		free(texture);
		ft_map_error(7);
	}
	texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp,
			&texture->line_len, &texture->endian);
}

void	get_sprites_pointers(t_sprites *sprites, t_data *data)
{
	check_valid_path(data);
	new_txt(data->mlx, data->n_texture, sprites->no_sprite);
	new_txt(data->mlx, data->s_texture, sprites->so_sprite);
	new_txt(data->mlx, data->e_texture, sprites->es_sprite);
	new_txt(data->mlx, data->w_texture, sprites->we_sprite);
}

void	get_textures(t_map *map, t_data *data, t_program *game)
{
	int	i;

	(void)game;
	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(map->map[i], "NO", 2))
			data->n_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		else if (!ft_strncmp(map->map[i], "SO", 1))
			data->s_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		else if (!ft_strncmp(map->map[i], "WE", 1))
			data->w_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		else if (!ft_strncmp(map->map[i], "EA", 1))
			data->e_texture = ft_strdup(ft_strchr(map->map[i], ' ') + 1);
		i++;
	}
	get_sprites_pointers(game->sprites, game->data);
}
