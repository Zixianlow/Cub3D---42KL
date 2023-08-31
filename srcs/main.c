/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 13:17:30 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_animate(t_game *game)
{
	game->frame++;
	game->gunframe++;
	if (game->frame % 5 == 1 && game->gunframe < 50)
	{
		mlx_clear_window(game->mlx, game->win);
		render_next_frame(game, game->gunframe / 10);
	}
	if (game->gunframe == 10000)
		game->gunframe = 2500;
	if (game->frame == 10000)
		game->frame = 0;
	return (0);
}

int	exit_hook(t_game *game)
{
	ft_perror_exit("You close the terminal!!!\n", game, 4);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_perror_exit("Please use: ./cub3d (valid_map_path)\n", &game, 0);
	game.tex = NULL;
	game.line = NULL;
	game.mlx = mlx_init();
	game.frame = 0;
	game.type = 0;
	game.guntype = 1;
	game.gunframe = 2500;
	if (ft_get_map(&game, av[1]))
		ft_perror_exit("Invalid map path\n", &game, 0);
	ft_get_line(&game);
	ft_get_gun_pic(&game);
	game.win = mlx_new_window(game.mlx, MAP_W * TILE_SIZE,
			MAP_H * TILE_SIZE, "cub3d");
	render_next_frame(&game, 1);
	mlx_hook(game.win, 17, (1L << 0), exit_hook, &game);
	mlx_hook(game.win, 2, (1L << 0), kclose, &game);
	mlx_hook(game.win, 6, (1L << 6), mouse_hook, &game);
	mlx_loop_hook(game.mlx, ft_animate, &game);
	mlx_loop(game.mlx);
}
