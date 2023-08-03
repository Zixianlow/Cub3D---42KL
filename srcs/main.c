/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/03 19:21:49 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_player(game);
	return (0);
}

/* 0 = up, 2 = down, 3 = left, 1 = right*/
void	wall_collision(t_game *game, int move)
{
	double	a;
	double	i;
	double	j;
	int		x;
	int		y;

	i = game->player.x;
	j = game->player.y;
	a = game->player.angle + (move * M_PI / 2);
	if (a < 0)
		a += 2 * M_PI;
	if (a > 2 * M_PI)
		a -= 2 * M_PI;
	i = game->player.x + 0.2 * cos(a);
	j = game->player.y + 0.2 * sin(a);
	if (cos(a) > 0)
		x = i + 0.1;
	else
		x = i - 0.1;
	if (sin(a) > 0)
		y = j + 0.1;
	else
		y = j - 0.1;
	if (game->map[x][y] != '1')
	{
		game->player.x = i;
		game->player.y = j;
	}
}

void	ft_slesc_free_n_exit(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free (game->map);
	write (2, "You hit ESC!!!\n", 14);
	exit(0);
}

int	kclose(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_slesc_free_n_exit(game);
	}
	if (keycode == 1)
		wall_collision(game, 2);
	if (keycode == 2)
		wall_collision(game, 1);
	if (keycode == 13)
		wall_collision(game, 0);
	if (keycode == 0)
		wall_collision(game, 3);
	if (keycode == 123)
		game->player.angle -= M_PI / 36;
	if (keycode == 124)
		game->player.angle += M_PI / 36;
	render_next_frame(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	game.tex = NULL;
	game.mlx = mlx_init();
	if (ft_get_map(&game, av[1]))
		return (0);
	ft_get_line(&game);
	game.win = mlx_new_window(game.mlx, MAP_W * TILE_SIZE,
			MAP_H * TILE_SIZE, "cub3d");
	render_next_frame(&game);
	mlx_hook(game.win, 2, (1L << 0), kclose, &game);
	mlx_loop(game.mlx);
}
