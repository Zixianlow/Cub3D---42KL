/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:16:32 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 16:16:45 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_char(char ch)
{
	if (ch == ' ')
		return (0);
	if (ch == '0')
		return (0);
	if (ch == '1')
		return (0);
	if (ch == '2')
		return (0);
	if (ch == 'N')
		return (0);
	if (ch == 'E')
		return (0);
	if (ch == 'S')
		return (0);
	if (ch == 'W')
		return (0);
	return (1);
}

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_check_char(game->map[i][j]))
				return (1);
		}
	}
	return (0);
}
