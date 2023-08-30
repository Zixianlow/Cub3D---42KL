/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/20 16:00:53 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_change_pos(t_game *game, double i, double j)
{
	game->player.x = i;
	game->player.y = j;
	game->player.x = i;
	game->player.y = j;
	mlx_clear_window(game->mlx, game->win);
	render_next_frame(game, 0);
	return (1);
}
