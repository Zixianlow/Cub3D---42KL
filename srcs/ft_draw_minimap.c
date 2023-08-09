/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:25:48 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/09 17:40:02 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_y(t_game *game, double my)
{
	return ((int)(game->player.y - my / 25 + 5));
}

int	get_x(t_game *game, double mx)
{
	return ((int)(game->player.x + mx / 25 - 3));
}

void	ft_color_minimap(t_game *game, int mx, int my)
{
	int	l;

	l = ft_strlen(game->map[get_x(game, mx)]);
	if (get_y(game, my) <= l
		&& game->map[get_x(game, mx)][get_y(game, my)])
	{
		if (game->map[get_x(game, mx)][get_y(game, my)] == '2')
			mlx_pixel_put(game->mlx, game->win, my, mx, 0x0000FF);
		else if (game->map[get_x(game, mx)][get_y(game, my)] != '0'
			&& game->map[get_x(game, mx)][get_y(game, my)] != '3')
			mlx_pixel_put(game->mlx, game->win, my, mx, 0xFFFFFF);
	}
	else
		mlx_pixel_put(game->mlx, game->win, my, mx, 0xFFFFFF);
}

void	ft_draw_minimap(t_game *game)
{
	double	mx;
	double	my;
	int		l;
	int		m;

	m = 0;
	while (game->map[m])
		m++;
	mx = 0;
	while (mx <= 150)
	{
		my = 0;
		while (my <= 250)
		{
			if (get_x(game, mx) >= 0 && get_y(game, my) >= 0
				&& get_x(game, mx) <= m && game->map[get_x(game, mx)])
				ft_color_minimap(game, mx, my);
			else
				mlx_pixel_put(game->mlx, game->win, my, mx, 0xFFFFFF);
			my++;
		}
		mx++;
	}
}
