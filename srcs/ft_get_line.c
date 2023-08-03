/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:57:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/02 17:27:56 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_node_line1(t_game *game, int i, int j)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->ax = i;
	node->ay = j;
	node->bx = i + 1;
	node->by = j;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
		{
			if (temp->ay == node->ay && temp->by == node->by
				&& temp->bx == node->ax)
			{
				temp->bx = node->bx;
				free(node);
				return ;
			}
			temp = temp->next;
		}
		temp->next = node;
	}
}

void	ft_node_line2(t_game *game, int i, int j)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->ax = i;
	node->ay = j;
	node->bx = i;
	node->by = j + 1;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
		{
			if (temp->ax == node->ax && temp->bx == node->bx
				&& temp->by == node->ay)
			{
				temp->by = node->by;
				free(node);
				return ;
			}
			temp = temp->next;
		}
		temp->next = node;
	}
}

void	ft_node_line3(t_game *game, int i, int j)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->ax = i + 1;
	node->ay = j;
	node->bx = i + 1;
	node->by = j + 1;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
		{
			if (temp->ax == node->ax && temp->bx == node->bx
				&& temp->by == node->ay)
			{
				temp->by = node->by;
				free(node);
				return ;
			}
			temp = temp->next;
		}
		temp->next = node;
	}
}

void	ft_node_line4(t_game *game, int i, int j)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->ax = i;
	node->ay = j + 1;
	node->bx = i + 1;
	node->by = j + 1;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
		{
			if (temp->ay == node->ay && temp->by == node->by
				&& temp->bx == node->ax)
			{
				temp->bx = node->bx;
				free(node);
				return ;
			}
			temp = temp->next;
		}
		temp->next = node;
	}
}

void	ft_init_player(t_game *game, int i, int j, char ch)
{
	game->player.x = i;
	game->player.y = j;
	if (ch == 'N')
		game->player.angle = 0;
	else if (ch == 'E')
		game->player.angle = M_PI / 4;
	else if (ch == 'S')
		game->player.angle = M_PI / 2;
	else if (ch == 'W')
		game->player.angle = M_PI * 3 / 4;
}

void	ft_get_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				ft_node_line1(game, i, j);
				ft_node_line2(game, i, j);
				ft_node_line3(game, i, j);
				ft_node_line4(game, i, j);
			}
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'S' || game->map[i][j] == 'W')
				ft_init_player(game, i, j, game->map[i][j]);
			j++;
		}
		i++;
	}
}
