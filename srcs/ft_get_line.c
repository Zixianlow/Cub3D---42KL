/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:57:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 12:30:11 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_game *game, int i, int j, char ch)
{
	game->player.x = i + 0.5;
	game->player.y = j + 0.5;
	if (ch == 'N')
		game->player.angle = M_PI;
	else if (ch == 'E')
		game->player.angle = M_PI / 2;
	else if (ch == 'S')
		game->player.angle = 0;
	else if (ch == 'W')
		game->player.angle = M_PI * 1.5;
}

void	ft_check_tile(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		ft_node_line1(game, i, j, 1);
		ft_node_line2(game, i, j, 1);
		ft_node_line3(game, i, j, 1);
		ft_node_line4(game, i, j, 1);
	}
	if (game->map[i][j] == '2')
	{
		ft_node_line1(game, i, j, 2);
		ft_node_line2(game, i, j, 2);
		ft_node_line3(game, i, j, 2);
		ft_node_line4(game, i, j, 2);
	}
}

void	ft_get_line(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_check_tile(game, i, j);
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'S' || game->map[i][j] == 'W')
			{
				if (c > 0)
					ft_perror_exit("Multiple start position", game, 3);
				ft_init_player(game, i, j, game->map[i][j]);
				game->map[i][j] = '0';
				c++;
			}
			j++;
		}
		i++;
	}
}
