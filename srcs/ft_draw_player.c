/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:30:28 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 17:11:18 by lzi-xian         ###   ########.fr       */
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

int	ft_get_color(unsigned char *data, int i)
{
	return ((data[i + 2] << 16) | (data[i + 1] << 8) | (data[i]) | 0);
}

void	draw_view(t_game *game, int pos)
{
	int y = 0;
	double a = game->dis.sh * 10 * TILE_SIZE;
	double b = ceil(game->dis.wh * 10 * TILE_SIZE);
	double startx = game->player.x;
	double starty = game->player.y;
	t_tex	*temp;
	int old_x;
	int old_y;
	int old_index;
	unsigned int color;

	temp = game->tex;
	while (temp->next)
	{
		if (temp->type != game->type)
			temp = temp->next;
		else
			break ;
	}
	while (startx > 1)
		startx--;
	while (starty > 1)
		starty--;
	if (pos < 251)
		y = 150;
	while (b < 640 && y < a)
	{
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.ceiling_rgb);
		y++;
	}
	y = 10 * TILE_SIZE;
	while (b < 640 && y > a + b)
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
	while (y < a + b)
	{
		old_x = game->posx * temp->img_w;
		old_y = (y - a) * temp->img_h / b;
		if (old_y >= 0 && old_x >= 0)
		{
			old_index = (old_y * temp->img_w + old_x) * 4;
			color = ft_get_color(temp->img_data, old_index);
			mlx_pixel_put(game->mlx, game->win, pos, y, color);
		}
		y++;
		// if (y > 640)
		// 	break ;
	}
}

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
	while (temp)
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
		{
			fdis = tdis;
			game->type = temp->type;
		}
		if (tdis != -1 && fdis >= tdis)
		{
			fdis = tdis;
			fx = tx;
			fy = ty;
			game->type = temp->type;
		}
		temp = temp->next;
	}
	if (fx != -1)
	{
		*lx = fx;
		*ly = fy;
		if (game->type == 1 || game->type == 2 || game->type == 5)
			game->posx = fy;
		else if (game->type == 3 || game->type == 4 || game->type == 6)
			game->posx = fx;
		while (game->posx > 1)
			game->posx--;
	}
	return (fdis);
}

void draw_line(t_game *game, double x1, double y1, double a)
{
    double delta_x = (game->player.x + cos(a) - x1) * 16;
    double delta_y = (game->player.y + sin(a) - y1) * 16;
    double step = fmax(fabs(delta_x), fabs(delta_y));
    double x_increment = delta_x / step;
    double y_increment = delta_y / step;
    double x = 75;
    double y = 125;

    int i = 0;
	while (i <= step)
	{
		if (x >= 0 && x <= 150 && y >= 0 && y <= 250)
			mlx_pixel_put(game->mlx, game->win, y, x, 0xFF0000);
		x += x_increment;
		y -= y_increment;
		i++;
	}
}

void	draw_player(t_game *game)
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
		draw_line(game, game->player.x, game->player.y, a);
		dis = ft_get_intersect(game, game->player.x, game->player.y,
				&line_x, &line_y);
		ft_node_dis(game, dis, a);
		draw_view(game, i);
		a += M_PI * 0.025 / 72;
		i++;
	}
}
