/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:25:48 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/06 14:21:03 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_y(t_game *game, int my)
{
	return ((int)(game->player.y + my / 50 - 1.5));
}

int	get_x(t_game *game, int mx)
{
	return ((int)(game->player.x + mx / 50 - 2.5));
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;
	int	mx;
	int	my;

	mx = 0;
	while (mx < 250)
	{
		my = 0;
		while (my < 150)
		{
			if (get_x(game, mx) >= 0 && get_y(game, my) >= 0){
				if (get_x(game, mx) <= 4  && get_y(game, my) <= 4){
					if (game->map[get_x(game, mx)][get_y(game, my)])
					{if (game->map[get_x(game, mx)][get_y(game, my)] == '1')
						mlx_pixel_put(game->mlx, game->win, mx, my, 0xffffff);
					else if (game->map[get_x(game, mx)][get_y(game, my)] == '0')
						mlx_pixel_put(game->mlx, game->win, mx, my, 0x000000);
						}}}
			my++;
		}
		mx++;
	}
}
