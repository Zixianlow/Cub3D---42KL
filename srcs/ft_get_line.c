/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:57:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/06 14:24:53 by lzi-xian         ###   ########.fr       */
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
	node->type = 3;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
			temp = temp->next;
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
	node->type = 1;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
			temp = temp->next;
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
	node->type = 2;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
			temp = temp->next;
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
	node->type = 4;
	node->next = NULL;
	if (!temp)
		game->line = node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

void	ft_init_player(t_game *game, int i, int j, char ch)
{
	game->player.x = i + 0.5;
	game->player.y = j + 0.5;
	if (ch == 'E')
		game->player.angle = 0;
	else if (ch == 'S')
		game->player.angle = M_PI / 2;
	else if (ch == 'W')
		game->player.angle = M_PI;
	else if (ch == 'N')
		game->player.angle = M_PI * 1.5;
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
