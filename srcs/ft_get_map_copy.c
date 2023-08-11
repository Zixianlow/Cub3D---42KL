/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:30:10 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 17:30:43 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map2(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->map2 = malloc(sizeof(char *) * i + 1);
	game->map2[i] = 0;
	i = 0;
	while (game->map[i])
	{
		game->map2[i] = ft_strdup(game->map[i]);
		i++;
	}
}

void	ft_makemap(t_game *game, int maxlen)
{
	char	*store;
	int		i;
	int		j;
	int		t;

	i = -1;
	while (game->map2[++i])
	{
		j = 0;
		while (game->map2[i][j])
			j++;
		if (j <= maxlen)
		{
			store = ft_strdup(game->map2[i]);
			free(game->map2[i]);
			game->map2[i] = malloc(sizeof(char) * maxlen + 1);
			game->map2[i][maxlen] = '\0';
		}
		t = -1;
		while (store[++t])
			game->map2[i][t] = store[t];
		j--;
		while (++j < maxlen)
			game->map2[i][j] = 32;
	}
}
