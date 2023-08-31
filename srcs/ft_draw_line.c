/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:49:46 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 11:46:29 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_y_increment(double delta_y, double step)
{
	return (delta_y / step);
}

double	ft_x_increment(double delta_x, double step)
{
	return (delta_x / step);
}

double	ft_dy(t_game *game, double a, double y1)
{
	return ((game->player.y + sin(a) - y1) * 16);
}

double	ft_dx(t_game *game, double a, double x1)
{
	return ((game->player.x + cos(a) - x1) * 16);
}

void	ft_draw_line(t_game *game, double x1, double y1, double a)
{
	double	step;
	double	x;
	double	y;
	int		i;

	step = fmax(fabs(ft_dx(game, a, x1)), fabs(ft_dy(game, a, y1)));
	x = 75;
	y = 125;
	i = 0;
	while (i <= step)
	{
		if (x >= 0 && x <= 150 && y >= 0 && y <= 250)
			mlx_pixel_put(game->mlx, game->win, y, x, 0xFF0000);
		x += ft_x_increment(ft_dx(game, a, x1), step);
		y += ft_y_increment(ft_dy(game, a, y1), step);
		i++;
	}
}
