/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:08:25 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:29:27 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	check_map(t_program *game)
{
	check_walls(game->map);
	game->map->height = ft_arrlen(game->map->map);
	game->map->width = ft_longest(game->map->map);
	return (true);
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

void	check_identifiers(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map->map[i][0] == 'N' && map->map[i][1] != 'O'
			&& map->map[i][2] != ' ')
			ft_map_error(5);
		if (map->map[i][0] == 'W' && map->map [i][1] != 'E'
			&& map->map[i][2] != ' ')
			ft_map_error(5);
		if (map->map[i][0] == 'S' && map->map [i][1] != 'O'
			&& map->map[i][2] != ' ')
			ft_map_error(5);
		if (map->map[i][0] == 'W' && map->map [i][1] != 'E'
			&& map->map[i][2] != ' ')
			ft_map_error(5);
		if (map->map[i][0] == 'C' && map->map [i][1] != ' ')
			ft_map_error(5);
		if (map->map[i][0] == 'F' && map->map [i][1] != ' ')
			ft_map_error(5);
		if (not_valid_char(map->map[i][0]))
			ft_map_error(5);
		i++;
	}
}

void	parse_map(t_map *map, char *path, t_program *game)
{
	int		i;

	i = -1;
	get_map(map, path);
	while (++i < 6)
		map->map[i] = ft_epurstr(map->map[i]);
	check_identifiers(map);
	get_rgb(map, game->data);
	get_textures(map, game->data, game);
	trim_file(map);
}
