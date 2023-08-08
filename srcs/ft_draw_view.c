/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:31 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 18:45:35 by lzi-xian         ###   ########.fr       */
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
	unsigned int	color;

	temp = game->tex;
	while (temp->next)
	{
		if (temp->type != game->type)
			temp = temp->next;
		else
			break ;
	}
	while (++y < a[0] + a[1])
	{
		old_x = game->posx * temp->img_w;
		old_y = (y - a[0]) * temp->img_h / a[1];
		if (old_y >= 0 && old_x >= 0)
		{
			old_index = (old_y * temp->img_w + old_x) * 4;
			color = ft_get_color(temp->img_data, old_index);
			mlx_pixel_put(game->mlx, game->win, pos, y, color);
		}
	}
}

void	ft_draw_view(t_game *game, int pos)
{
	int		y;
	double	a[2];

	y = -1;
	a[0] = game->dis.sh * 10 * TILE_SIZE;
	a[1] = ceil(game->dis.wh * 10 * TILE_SIZE);
	if (pos < 251)
		y = 150;
	while (a[1] < 640 && ++y < a[0])
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.ceiling_rgb);
	y = 10 * TILE_SIZE + 1;
	while (a[0] < 640 && --y > a[0] + a[1])
		mlx_pixel_put(game->mlx, game->win, pos, y, game->fc.floor_rgb);
	y = a[0] - 1;
	if (pos < 251)
		if (a[0] < 150)
			y = 149;
	ft_draw_wall(game, y, pos, a);
}
