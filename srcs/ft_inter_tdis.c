/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_tdis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:46:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 15:46:44 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_dis(t_game *game, double tx, double ty)
{
	double	x;
	double	y;
	double	px;
	double	py;

	px = game->player.x;
	py = game->player.y;
	if (px > tx)
		x = px - tx;
	else
		x = tx - px;
	if (py > ty)
		y = py - ty;
	else
		y = ty - py;
	return (x * x + y * y);
}

void	ft_set_v(t_inter *v, t_game *game, double t)
{
	v->tx = v->x[0] + t * (v->x[2] - v->x[0]);
	v->ty = v->x[1] + t * (v->x[3] - v->x[1]);
	v->tdis = calc_dis(game, v->tx, v->ty);
}

void	ft_get_tdis(t_game *game, double *lx, double *ly, t_inter *v)
{
	double	t;
	double	u;
	double	px;
	double	py;
	double	den;

	px = game->player.x;
	py = game->player.y;
	den = (v->x[0] - v->x[2]) * (py - (*ly))
		- (v->x[1] - v->x[3]) * (px - (*lx));
	if (den == 0)
		v->tdis = -1;
	else
	{
		t = ((v->x[0] - px) * (py - (*ly))
				- (v->x[1] - py) * (px - (*lx))) / den;
		u = -((v->x[0] - v->x[2]) * (v->x[1] - py)
				- (v->x[1] - v->x[3]) * (v->x[0] - px)) / den;
		if (t > 0 && t < 1 && u > 0)
			ft_set_v(v, game, t);
		else
			v->tdis = -1;
	}
}
