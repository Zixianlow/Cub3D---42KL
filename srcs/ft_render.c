/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:41:00 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:42 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_gun(t_game *game, int type)
{
	if (type == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->gun.gun1, 300, 380);
	if (type == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->gun.gun2, 300, 380);
	if (type == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->gun.gun3, 300, 380);
	if (type == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->gun.gun4, 300, 380);
	if (type == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->gun.gun1, 300, 380);
}

int	render_next_frame(t_game *game, int type)
{
	ft_draw_player(game);
	ft_draw_minimap(game);
	ft_put_gun(game, type);
	return (0);
}
