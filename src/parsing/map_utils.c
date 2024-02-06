/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:41:15 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 18:45:55 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_arrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	trim_file(t_map *map)
{
	char	**tmp;
	int		i;
	int		j;

	i = 6;
	j = 0;
	tmp = malloc(sizeof(char **) * ft_arrlen(map->map) - 5);
	if (!tmp)
		ft_map_error(4);
	while (map->map[i])
	{
		tmp[j] = ft_strdup(map->map[i]);
		j++;
		i++;
	}
	tmp[j] = NULL;
	free_double_arr(map->map);
	map->map = tmp;
}

int	ft_atrgb(char *s)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i])
		return (-1);
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')
				return (-1);
			i++;
		}
		if (!ft_isdigit(s[i]))
			return (-1);
		if (s[i] >= '0' && s[i] <= '9')
			ret = (ret * 10) + (s[i] - '0');
		i++;
	}
	return (ret);
}

void	atoi_rgb(int *rgb, char **str)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		free_double_arr(str);
		ft_map_error(3);
	}
	while (i < 3)
	{
		if (!str[i] || ft_strlen(str[i]) > 4)
		{
			free_double_arr(str);
			ft_map_error(3);
		}
		rgb[i] = ft_atrgb(str[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free_double_arr(str);
			ft_map_error(3);
		}
		i++;
	}
}

bool	get_rgb(t_map *map, t_data *data)
{
	char	**tmp;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(map->map[i], "C", 1))
		{
			tmp = ft_split(ft_strchr(map->map[i], 32) + 1, ',');
			atoi_rgb(data->c_rgb, tmp);
			free_double_arr(tmp);
		}
		else if (!ft_strncmp(map->map[i], "F", 1))
		{
			tmp = ft_split(ft_strchr(map->map[i], 32) + 1, ',');
			atoi_rgb(data->f_rgb, tmp);
			free_double_arr(tmp);
		}
		i++;
	}
	return (false);
}
