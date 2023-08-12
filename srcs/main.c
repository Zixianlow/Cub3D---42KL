/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 19:26:04 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_game *game)
{
	ft_draw_player(game);
	ft_draw_minimap(game);
	return (0);
}

int	ft_animate(t_game *game)
{
	game->frame++;
	if (game->frame % 500 == 1)
	{
		mlx_clear_window(game->mlx, game->win);
		render_next_frame(game);
	}
	if (game->frame == 5000)
		game->frame = 0;
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
	if (ft_get_map(&game, av[1]))
		ft_perror_exit("Invalid map path\n", &game, 0);
	ft_get_line(&game);
	game.win = mlx_new_window(game.mlx, MAP_W * TILE_SIZE,
			MAP_H * TILE_SIZE, "cub3d");
	render_next_frame(&game);
	mlx_hook(game.win, 2, (1L << 0), kclose, &game);
	mlx_hook(game.win, 6, (1L << 6), mouse_hook, &game);
	mlx_loop_hook(game.mlx, ft_animate, &game);
	mlx_loop(game.mlx);
}
