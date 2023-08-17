/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:53:50 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 17:26:56 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_walk_turn(int keycode, t_game *game)
{
	if (keycode == 1)
		ft_wall_collision(game, 2);
	if (keycode == 2)
		ft_wall_collision(game, 3);
	if (keycode == 13)
		ft_wall_collision(game, 0);
	if (keycode == 0)
		ft_wall_collision(game, 1);
	if (keycode == 123)
	{
		game->player.angle += M_PI / 72;
		ft_change_pos(game, game->player.x, game->player.y);
	}
	if (keycode == 124)
	{
		game->player.angle -= M_PI / 72;
		ft_change_pos(game, game->player.x, game->player.y);
	}
}

int	kclose(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_perror_exit("You hit ESC!!!\n", game, 4);
	}
	if (keycode == 3)
		ft_door_open(game);
	if (keycode == 5)
		game->gunframe = 0;
	ft_walk_turn(keycode, game);
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
		game->player.angle -= M_PI * dx / 1440;
		prev_x = x;
		ft_change_pos(game, game->player.x, game->player.y);
	}
	return (0);
}
