/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:55:50 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 17:43:32 by lzi-xian         ###   ########.fr       */
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
