/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:51:14 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/09 17:30:44 by lzi-xian         ###   ########.fr       */
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
	int	m;
	int	l;

	m = 0;
	while (game->map[m])
		m++;
	if (game->player.x + 2 < m)
		ft_door_line(game, game->player.x + 2, game->player.y);
	if (game->player.x + 1 < m)
		ft_door_line(game, game->player.x + 1, game->player.y);
	if (game->player.x - 2 >= 0)
		ft_door_line(game, game->player.x - 2, game->player.y);
	if (game->player.x - 1 >= 0)
		ft_door_line(game, game->player.x - 1, game->player.y);
	l = ft_strlen(game->map[(int)game->player.x]);
	if (game->player.y + 2 < l)
		ft_door_line(game, game->player.x, game->player.y + 2);
	if (game->player.y + 1 < l)
		ft_door_line(game, game->player.x, game->player.y + 1);
	if (game->player.y - 2 >= 0)
		ft_door_line(game, game->player.x, game->player.y - 2);
	if (game->player.y - 1 >= 0)
		ft_door_line(game, game->player.x, game->player.y - 1);
}
