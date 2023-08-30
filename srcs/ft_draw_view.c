/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:31 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/18 16:39:26 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_color(unsigned char *data, int i)
{
	return ((data[i + 2] << 16) | (data[i + 1] << 8) | (data[i]) | 0);
}

void	ft_draw_wall(t_game *game, int y, int pos, double *a)
{
	t_tex			*temp;
	int				old_x;
	int				old_y;
	int				old_index;

	temp = game->tex;
	while (temp->next)
	{
		if (temp->type == game->type)
			break ;
		temp = temp->next;
	}
	while (++y < a[2])
	{
		old_x = game->posx * temp->img_w;
		old_y = (y - a[0]) * temp->img_h / a[1];
		old_index = (old_y * temp->img_w + old_x) * 4;
		mlx_pixel_put(game->mlx, game->win, pos, y,
			ft_get_color(temp->img_data, old_index));
	}
}

void	ft_draw_view(t_game *game, int pos)
{
	int		y;
	double	a[3];

	a[0] = game->dis.sh * 10 * TILE_SIZE;
	a[1] = game->dis.wh * 10 * TILE_SIZE;
	a[2] = a[0] + a[1];
	y = -1;
	if (pos < 251)
		y = 149;
	while (++y < a[0])
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.ceiling_rgb);
	y = 10 * TILE_SIZE;
	while (--y > a[2])
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.floor_rgb);
	y = a[0];
	if (pos < 251)
		if (a[0] < 150)
			y = 149;
	ft_draw_wall(game, y, pos, a);
}
