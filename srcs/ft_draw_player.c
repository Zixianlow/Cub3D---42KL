/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:30:28 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 18:41:03 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_node_dis(t_game *game, double d, double a)
{
	d = sqrt(d);
	d *= cos(a - game->player.angle);
	d = fabs(d);
	if (d < 0.01)
		d = 0.01;
	game->dis.wh = 1.5 / d;
	game->dis.sh = (1 - game->dis.wh) / 2;
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
		if (i % 2 == 0)
		{
			line_x = game->player.x + (cos(a) * 10);
			line_y = game->player.y + (sin(a) * 10);
			dis = ft_intersect(game, &line_x, &line_y);
			ft_node_dis(game, dis, a);
			ft_draw_line(game, game->player.x, game->player.y, a);
		}
		ft_draw_view(game, 640 - i);
		a += M_PI * 0.025 / 72;
		i++;
	}
}
