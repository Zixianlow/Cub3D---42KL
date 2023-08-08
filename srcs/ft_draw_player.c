/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:30:28 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 18:49:57 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_node_dis(t_game *game, double d, double a)
{
	double	i;
	double	j;
	double	diff;

	i = 0;
	diff = a - game->player.angle;
	d = sqrt(d);
	d *= cos(diff);
	d = fabs(d);
	if (d < 0.01)
		d = 0.01;
	i = 1.5 / d;
	j = (1 - i) / 2;
	game->dis.sh = j;
	game->dis.wh = i;
	game->dis.fh = j;
}

void	ft_draw_player(t_game *game)
{
	double	line_x;
	double	line_y;
	double	a;
	double	dis;
	int		i;

	i = 0;
	a = game->player.angle - M_PI * 8 / 72;
	while (i < 640)
	{
		line_x = game->player.x + (cos(a) * 10);
		line_y = game->player.y + (sin(a) * 10);
		ft_draw_line(game, game->player.x, game->player.y, a);
		dis = ft_get_intersect(game, game->player.x, game->player.y,
				&line_x, &line_y);
		ft_node_dis(game, dis, a);
		ft_draw_view(game, i);
		a += M_PI * 0.025 / 72;
		i++;
	}
}
