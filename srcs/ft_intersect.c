/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:04:41 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 15:50:23 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_v_type(t_game *game, t_line *temp)
{
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
}

void	ft_set_texture_pos(t_game *game)
{
	if (game->type == 1 || game->type == 2 || game->type == 5)
		game->posx = game->v.fy;
	else if (game->type == 3 || game->type == 4 || game->type == 6)
		game->posx = game->v.fx;
	while (game->posx > 1)
		game->posx--;
}

double	ft_intersect(t_game *game, double *lx, double *ly)
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
		ft_get_tdis(game, lx, ly, &game->v);
		ft_set_v_type(game, temp);
		temp = temp->next;
	}
	if (game->v.fx != -1)
	{
		*lx = game->v.fx;
		*ly = game->v.fy;
		ft_set_texture_pos(game);
	}
	return (game->v.fdis);
}
