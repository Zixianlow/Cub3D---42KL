/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:30:28 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/03 19:22:28 by lzi-xian         ###   ########.fr       */
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

void	draw_view(t_game *game, int pos)
{
	int y = 0;
	double a = game->dis.sh * 10 * TILE_SIZE;
	double b = game->dis.wh * 10 * TILE_SIZE;
	double startx = game->player.x;
	double starty = game->player.y;
	int old_x;
	int old_y;
	int old_index;
	unsigned int color;

	while (startx > 1)
		startx--;
	while (starty > 1)
		starty--;
	if (pos < 251)
		y = 150;
	while(y < a)
	{
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.ceiling_rgb);
		y++;
	}
	y = 10 * TILE_SIZE;
	while(y > a + b)
	{
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.floor_rgb);
		y--;
	}
	y = a;
	if (pos < 251)
	{
		if (a < 150)
			y = 150;
	}
	while(y < a + b)
	{
		old_x = game->posx * game->tex->img_w;
        old_y = (y - a) * game->tex->img_h / b;
        old_index = (old_y * game->tex->img_w + old_x) * 4;
		color = (game->tex->img_data[old_index + 2] << 16) | (game->tex->img_data[old_index + 1] << 8) | game->tex->img_data[old_index];
		mlx_pixel_put(game->mlx, game->win, pos, y, color);
		y++;
	}
}

void	ft_node_dis(t_game *game, double d, double a)
{
	double	i;
	double	j;
	double	diff;

	i = 0;
	diff = a - game->player.angle;
	d *= cos(diff);
	d = fabs(d);
	if (d < 0.75)
		d = 0.75;
	i = 1 / d;
	j = (1 - i) / 2;
	game->dis.sh = j;
	game->dis.wh = i;
	game->dis.fh = j;
}

double ft_get_intersect(t_game *game, double px, double py, double *lx, double *ly)
{
	t_line *temp;
	double x1;
	double y1;
	double x2;
	double y2;
	double x3 = px;
	double y3 = py;
	double x4 = *lx;
	double y4 = *ly;
	double den;
	double t;
	double u;
	double tdis;
	double fdis;
	double tx;
	double ty;
	double fx = -1;
	double fy = -1;

	temp = game->line;
	fdis = -1;
	while (temp->next)
	{
		x1 = temp->ax;
		y1 = temp->ay;
		x2 = temp->bx;
		y2 = temp->by;
		den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
		if (den == 0)
			tdis = -1;
		else
		{
			t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
			u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
			if (t > 0 && t < 1 && u > 0)
			{
				tx = x1 + t * (x2 - x1);
				ty = y1 + t * (y2 - y1);
				tdis = calc_dis(px, py, tx, ty);
			}
			else
				tdis = -1;
		}
		if (fdis == -1)
			fdis = tdis;
		if (tdis != -1 && fdis >= tdis)
		{
			fdis = tdis;
			fx = tx;
			fy = ty;
		}
		temp = temp->next;
	}
	if (fx != -1)
	{
		*lx = fx;
		*ly = fy;
		game->posx = fy;
		while (game->posx > 1)
			game->posx--;
	}
	return (fdis);
}

void	draw_player(t_game *game)
{
	double	line_x;
	double	line_y;
	double	a;
	double	dis;
	int		i;

	i = 0;
	a = game->player.angle - M_PI * 20 / 72;
	while (i < 640)
	{
		if (i % 2 == 1)
			draw_view(game, i);
		else
		{
			line_x = game->player.x + (cos(a) * 10);
			line_y = game->player.y + (sin(a) * 10);
			dis = ft_get_intersect(game, game->player.x, game->player.y,
					&line_x, &line_y);
			ft_node_dis(game, dis, a);
			draw_view(game, i);
		}
		a += M_PI * 0.04 / 72;
		i++;
	}
}
