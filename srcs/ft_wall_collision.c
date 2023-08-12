/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:25:31 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 14:33:07 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_decision(t_game *game, double i, double j)
{
	int		x;
	int		y;
	int		c;
	double	a;

	c = 0;
	while (a != 2 * M_PI)
	{
		x = i + 0.2 * cos(a);
		y = j + 0.2 * sin(a);
		if (game->map[x][y] != '1' && game->map[x][y] != '2')
			c++;
		a += M_PI / 2;
	}
	if (c == 4)
	{
		game->player.x = i;
		game->player.y = j;
		return (1);
	}
	return (0);
}

void	ft_slide_type(t_game *game, double a, int type)
{
	int	x;
	int	y;
	int	x2;
	int	y2;

	x = game->player.x;
	y = game->player.y;
	x2 = game->player.x + 0.3;
	y2 = game->player.y + 0.3;
	if (type == 1)
		y2 = game->player.y - 0.3;
	if (type == 2)
	{
		x2 = game->player.x - 0.3;
		y2 = game->player.y - 0.3;
	}
	if (type == 3)
		x2 = game->player.x - 0.3;
	if ((game->map[x2][y] == '1' || game->map[x2][y] == '2')
		&& (game->map[x][y2] == '1' || game->map[x][y2] == '2'))
		return ;
	else if (game->map[x2][y] == '1' || game->map[x2][y] == '2')
		game->player.y += 0.1 * sin(a);
	else if (game->map[x][y2] == '1' || game->map[x][y2] == '2')
		game->player.x += 0.1 * cos(a);
}

void	ft_wall_slide(t_game *game, double a)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (a > M_PI * 1.5)
		ft_slide_type(game, a, 1);
	else if (a > M_PI)
		ft_slide_type(game, a, 2);
	else if (a > M_PI / 2)
		ft_slide_type(game, a, 3);
	else if (a > 0)
		ft_slide_type(game, a, 4);
}

void	ft_wall_collision(t_game *game, int move)
{
	double	a;
	double	i;
	double	j;

	a = game->player.angle + (move * M_PI / 2);
	while (a < 0)
		a += 2 * M_PI;
	while (a >= 2 * M_PI)
		a -= 2 * M_PI;
	i = game->player.x + 0.1 * cos(a);
	j = game->player.y + 0.1 * sin(a);
	if (ft_move_decision(game, i, j))
		return ;
	ft_wall_slide(game, a);
}
