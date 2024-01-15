/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:38:50 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/15 19:35:03 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		ft_putendl_fd("el mapa  no es valido", STDERR_FILENO);
	}
	exit(1);
}

void	get_map(t_map *map, char *path)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*temp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_map_error(1);
	while (line)
	{
		line = get_next_line_gnl(fd);
		if (!line || line == '\n')
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

void	init_structs(t_map *map, t_data *data, char *path)
{
	data = malloc(sizeof(t_data));
	map = malloc(sizeof(t_map));
	if (!check_map_ext(path, ".cub"))
	{
		ft_putendl_fd("invalid file extesion", STDERR_FILENO);
		exit(1);
	}
	data->map_path = ft_strdup(path);
	get_map(map, path);
}
