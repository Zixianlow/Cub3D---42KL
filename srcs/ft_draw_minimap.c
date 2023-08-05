/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:25:48 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/05 17:53:38 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	x2;
	int	y2;
	int	px;
	int	py;

	x = game->player.x - 3;
	x2 = game->player.x + 3;
	y2 = game->player.y + 2;
	px = 0;
	while (x < x2)
	{
		py = 0;
		y = game->player.y - 2;
		while (y < y2)
		{
			if (game->map[x][y] == '1')
				mlx_pixel_put(game->mlx, game->win, px, py, 0);
			else
				px += 25;
			y++;
		}
		py += 25;
		x++;
	}
}
