/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:57:15 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 15:41:12 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_node_line1(t_game *game, int i, int j, int type)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->x = i;
	node->y = j;
	node->ax = i;
	node->ay = j;
	node->bx = i + 1;
	node->by = j;
	if (type == 1)
		node->type = 3;
	else if (type == 2)
		node->type = 6;
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

void	ft_node_line2(t_game *game, int i, int j, int type)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->x = i;
	node->y = j;
	node->ax = i;
	node->ay = j;
	node->bx = i;
	node->by = j + 1;
	if (type == 1)
		node->type = 1;
	else if (type == 2)
		node->type = 5;
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

void	ft_node_line3(t_game *game, int i, int j, int type)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->x = i;
	node->y = j;
	node->ax = i + 1;
	node->ay = j;
	node->bx = i + 1;
	node->by = j + 1;
	if (type == 1)
		node->type = 2;
	else if (type == 2)
		node->type = 5;
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

void	ft_node_line4(t_game *game, int i, int j, int type)
{
	t_line	*temp;
	t_line	*node;

	temp = game->line;
	node = malloc(sizeof(t_line));
	node->x = i;
	node->y = j;
	node->ax = i;
	node->ay = j + 1;
	node->bx = i + 1;
	node->by = j + 1;
	if (type == 1)
		node->type = 4;
	else if (type == 2)
		node->type = 6;
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
	if (ch == 'N')
		game->player.angle = M_PI;
	else if (ch == 'E')
		game->player.angle = M_PI * 1.5;
	else if (ch == 'S')
		game->player.angle = 0;
	else if (ch == 'W')
		game->player.angle = M_PI / 2;
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
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'S' || game->map[i][j] == 'W')
			{	
				ft_init_player(game, i, j, game->map[i][j]);
				game->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
