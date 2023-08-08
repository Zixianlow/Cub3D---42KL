/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:51:14 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 17:51:27 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_remove_line(t_game *game, int px, int py)
{
	t_line	*temp;

	temp = game->line;
	while (temp->next->next)
	{
		if (temp->next->x == px && temp->next->y == py)
		{
			temp->next = temp->next->next->next->next->next;
			break ;
		}
		temp = temp->next;
	}
}

void	ft_add_line(t_game *game, int px, int py)
{
	ft_node_line1(game, px, py, 2);
	ft_node_line2(game, px, py, 2);
	ft_node_line3(game, px, py, 2);
	ft_node_line4(game, px, py, 2);
}

void	ft_door_line(t_game *game, int px, int py)
{
	if (game->map[px][py])
	{
		if (game->map[px][py] == '2')
		{
			ft_remove_line(game, px, py);
			game->map[px][py] = '3';
		}
		else if (game->map[px][py] == '3')
		{
			ft_add_line(game, px, py);
			game->map[px][py] = '2';
		}
	}
}

void	ft_door_open(t_game *game)
{
	ft_door_line(game, game->player.x + 2, game->player.y);
	ft_door_line(game, game->player.x + 1, game->player.y);
	ft_door_line(game, game->player.x - 2, game->player.y);
	ft_door_line(game, game->player.x - 1, game->player.y);
	ft_door_line(game, game->player.x, game->player.y + 2);
	ft_door_line(game, game->player.x, game->player.y + 1);
	ft_door_line(game, game->player.x, game->player.y - 2);
	ft_door_line(game, game->player.x, game->player.y - 1);
}
