/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:42:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 15:42:38 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_gun_pic(t_game *game)
{
	int	img_h;
	int	img_w;

	game->gun.gun1 = mlx_xpm_file_to_image(game->mlx,
			"./assets/gun1.xpm", &img_w, &img_h);
	game->gun.gun2 = mlx_xpm_file_to_image(game->mlx,
			"./assets/gun2.xpm", &img_w, &img_h);
	game->gun.gun3 = mlx_xpm_file_to_image(game->mlx,
			"./assets/gun3.xpm", &img_w, &img_h);
	game->gun.gun4 = mlx_xpm_file_to_image(game->mlx,
			"./assets/gun4.xpm", &img_w, &img_h);
}
