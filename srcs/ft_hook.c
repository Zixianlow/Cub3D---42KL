/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:53:50 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 17:54:40 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_wall_collision(t_game *game, int move)
{
	double	a;
	double	i;
	double	j;
	int		x;
	int		y;

	i = game->player.x;
	j = game->player.y;
	a = game->player.angle + (move * M_PI / 2);
	i = game->player.x + 0.1 * cos(a);
	j = game->player.y + 0.1 * sin(a);
	if (cos(a) > 0)
		x = i + 0.2;
	else
		x = i - 0.2;
	if (sin(a) > 0)
		y = j + 0.2;
	else
		y = j - 0.2;
	if (game->map[x][y] != '1' && game->map[x][y] != '2')
	{
		game->player.x = i;
		game->player.y = j;
	}
}

void	ft_esc_free_n_exit(t_game *game)
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
		ft_esc_free_n_exit(game);
	}
	if (keycode == 1)
		ft_wall_collision(game, 2);
	if (keycode == 2)
		ft_wall_collision(game, 1);
	if (keycode == 13)
		ft_wall_collision(game, 0);
	if (keycode == 0)
		ft_wall_collision(game, 3);
	if (keycode == 3)
		ft_door_open(game);
	if (keycode == 123)
		game->player.angle -= M_PI / 72;
	if (keycode == 124)
		game->player.angle += M_PI / 72;
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	static int	prev_x = -1;
	int			dx;

	(void) y;
	if (prev_x == -1)
		prev_x = x;
	dx = x - prev_x;
	if (abs(dx) > 5)
	{
		game->player.angle += M_PI * dx / 720;
		prev_x = x;
	}
	return (0);
}
