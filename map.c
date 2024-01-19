/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:08:25 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/19 18:53:54 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_map(t_program *game)
{
	count_assets(game);
	if (!check_walls(game->map))
		ft_map_error(4);
	if (!check_assets(game))
		ft_map_error(5);
}

bool	check_map_ext(char *path, char *ext)
{
	int	i;
	int	j;
	int	k;

	i = ft_strlen(ext);
	j = ft_strlen(path);
	k = 4;
	while (k > 0)
	{
		if (ext[i] != path[j])
		{
			return (false);
		}
		i--;
		j--;
		k--;
	}
	return (true);
}

void	get_map(t_map *map, char *path)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*temp;

	line = "";
	all_lines = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_map_error(1);
	while (line)
	{
		line = get_next_line_gnl(fd);
		if (!line)
			break ;
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	close(fd);
	if (all_lines[0] == '\0')
		ft_map_error(2);
	map->map = ft_split(all_lines, '\n');
	free(all_lines);
}

void	parse_map(t_map *map, char *path, t_program *game)
{
	int		i;

	i = -1;
	get_map(map, path);
	while (++i < 6)
		map->map[i] = ft_epurstr(map->map[i]);
	get_rgb(map, game->data);
	get_textures(map, game->data);
	trim_file(map);
}
