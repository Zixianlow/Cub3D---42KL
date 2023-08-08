/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:04:41 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 19:53:33 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_dis(double px, double py, double tx, double ty)
{
	double	x;
	double	y;

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

void	ft_get_tdis(double px, double py, double *lx, double *ly, t_inter *v)
{
	double	t;
	double	u;
	double	den;

	den = (v->x[0] - v->x[2]) * (py - (*ly))
		- (v->x[1] - v->x[3]) * (px - (*lx));
	if (den == 0)
		v->tdis = -1;
	else
	{
		t = ((v->x[0] - px) * (py - (*ly)) - (v->x[1] - py) * (px - (*lx))) / den;
		u = -((v->x[0] - v->x[2]) * (v->x[1] - py) - (v->x[1] - v->x[3]) * (v->x[0] - px)) / den;
		if (t > 0 && t < 1 && u > 0)
		{
			v->tx = v->x[0] + t * (v->x[2] - v->x[0]);
			v->ty = v->x[1] + t * (v->x[3] - v->x[1]);
			v->tdis = calc_dis(px, py, v->tx, v->ty);
		}
		else
			v->tdis = -1;
	}
}

double	ft_get_intersect(t_game *game, double px, double py, double *lx, double *ly)
{
	t_line	*temp;

	temp = game->line;
	game->v.fdis = -1;
	game->v.fx = -1;
	game->v.fy = -1;
	while (temp)
	{
		game->v.x[0] = temp->ax;
		game->v.x[1] = temp->ay;
		game->v.x[2] = temp->bx;
		game->v.x[3] = temp->by;
		ft_get_tdis(px, py, lx, ly, &game->v);
		if (game->v.fdis == -1)
		{
			game->v.fdis = game->v.tdis;
			game->type = temp->type;
		}
		if (game->v.tdis != -1 && game->v.fdis >= game->v.tdis)
		{
			game->v.fdis = game->v.tdis;
			game->v.fx = game->v.tx;
			game->v.fy = game->v.ty;
			game->type = temp->type;
		}
		temp = temp->next;
	}
	if (game->v.fx != -1)
	{
		*lx = game->v.fx;
		*ly = game->v.fy;
		if (game->type == 1 || game->type == 2 || game->type == 5)
			game->posx = game->v.fy;
		else if (game->type == 3 || game->type == 4 || game->type == 6)
			game->posx = game->v.fx;
		while (game->posx > 1)
			game->posx--;
	}
	return (game->v.fdis);
}
