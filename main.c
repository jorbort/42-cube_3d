/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:32:20 by jbortolo          #+#    #+#             */
/*   Updated: 2024/01/22 19:40:20 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	ft_longest(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > len)
			len = j;
		i++;
	}
	return (len);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_grid(t_program *game)
{
	t_img	img;

	int wi;
	int he;

	game->map->height = ft_arrlen(game->map->map);
	
	game->map->width = ft_longest(game->map->map);
	if (game->map->width > game->map->height)
		{
			wi = 1200 / game->map->width;
			he = 1000 / game->map->width;
		}
	else 
	{
		{
			wi = 1200 / game->map->height;
			he = 1000 / game->map->height;
		}
	}

	img.img = mlx_new_image(game->data->mlx, 1210, 1010);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	int x = 0, y = 0, i= 0, j = 0;

	while (y <= 1000)
    {
        i = 0;
        while (i <= 1200)
        {
            my_mlx_pixel_put(&img, i, y, 0x0000FFFF);
            i++;
        }
        y += he;
    }

	while (x <= 1200)
    {
        j = 0;
        while (j <= 1000)
        {
            my_mlx_pixel_put(&img, x, j, 0x0000FFFF);
            j++;
        }
        x += wi;
    }
	
	mlx_put_image_to_window(game->data->mlx, game->data->window, img.img, 0, 0);
}


int	end_game(t_program *game)
{
	//destroy_image(game);
	mlx_clear_window(game->data->mlx, game->data->window);
	mlx_destroy_window(game->data->mlx, game->data->window);
	ft_printf("GAME ENDED\n");
	exit(1);
	return (0);
}

void	start_game(t_program *game, char *map_path)
{
	parse_map(game->map, map_path, game);
	if (check_map(game) == true)
	{
		game->data->mlx = mlx_init();
		game->data->window = mlx_new_window(game->data->mlx,
				1300, 1100, "cub3D");
		print_grid(game);
		mlx_hook(game->data->window, 17, 0, end_game, game);
		mlx_key_hook(game->data->window, deal_key, game);
		mlx_loop(game->data->mlx);
	}
}

int	main(int argc, char **argv)
{
	t_program	game;

	if (argc != 2)
	{
		ft_putendl_fd("ERROR", STDERR_FILENO);
		ft_putendl_fd("Enter only one argument", STDERR_FILENO);
		exit(1);
	}
	if (!check_map_ext(argv[1], ".cub"))
	{
		ft_putendl_fd("Invalid file extesion", STDERR_FILENO);
		exit(1);
	}
	init_structs(&game);
	start_game(&game, argv[1]);
}
