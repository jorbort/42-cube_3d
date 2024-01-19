/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:08:25 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/19 13:23:21 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_map(t_program *game)
{
	(void) game;
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

void	ft_map_error(int num_error)
{
	if (num_error == 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		perror(" ");
	}
	if (num_error == 2)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("invalid map", STDERR_FILENO);
	}
	if (num_error == 3)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd("invalid rgb : must be a value from 0 to 255", STDERR_FILENO);
	}
	exit(1);
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
}
