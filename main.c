/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbortolo <jbortolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:32:20 by jbortolo          #+#    #+#             */
/*   Updated: 2024/02/06 14:29:44 by jbortolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put2(t_program *game, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIN_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= WIN_HEIGHT)
		return ;
	mlx_pixel_put(game->img, game->img->img, x, y, color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	end_game(t_program *game)
{
	mlx_clear_window(game->data->mlx, game->data->window);
	mlx_destroy_window(game->data->mlx, game->data->window);
	ft_printf("GAME ENDED\n");
	exit(1);
	return (0);
}

void	start_game(t_program *game, char *map_path)
{
	game->data->mlx = mlx_init();
	parse_map(game->map, map_path, game);
	if (check_map(game) == true)
	{
		game->data->window = mlx_new_window(game->data->mlx,
				WIN_WIDTH, WIN_HEIGHT, "cub3D");
		game->map->start_x *= (GRID_SIZE);
		game->map->start_x += (GRID_SIZE / 2);
		game->map->start_y *= (GRID_SIZE);
		game->map->start_y += (GRID_SIZE / 2);
		init_vec(game);
		get_sprites_pointers(game->sprites, game->data);
		print_grid(game);
		mlx_hook(game->data->window, 17, 0, end_game, game);
		mlx_hook(game->data->window, 3, 1L << 1, deal_key, game);
		mlx_hook(game->data->window, 2, 1L << 0, deal_key, game);
		mlx_hook(game->data->window, 6, 1L << 7, mouse_moving, game);
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
