/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:18:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 17:23:15 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_first_last_two_line(t_game *game, char ***final, int maxlen)
{
	int	l;
	int	i;

	i = 0;
	while (game->map2[i])
		i++;
	l = 0;
	while (l < maxlen + 4)
	{
		(*final)[0][l] = 'w';
		(*final)[1][l] = 's';
		(*final)[i + 2][l] = 's';
		(*final)[i + 3][l] = 'w';
		l++;
	}
	(*final)[1][0] = 'w';
	(*final)[i + 2][0] = 'w';
	(*final)[1][l - 1] = 'w';
	(*final)[i + 2][l - 1] = 'w';
}

void	ft_add_line_loop(t_game *game, char ***final, int k, int maxlen)
{
	int	l;

	l = 0;
	(*final)[k][l++] = 'w';
	(*final)[k][l++] = 's';
	while (l < maxlen + 2)
	{
		if (game->map2[k - 2][l - 2] == ' ')
			(*final)[k][l] = 's';
		else
			(*final)[k][l] = game->map2[k - 2][l - 2];
		l++;
	}
	(*final)[k][l++] = 's';
	(*final)[k][l] = 'w';
}

char	**ft_final_line(t_game *game, int maxlen)
{
	char	**final;
	int		i;
	int		k;
	int		l;

	i = 0;
	while (game->map2[i])
		i++;
	final = malloc(sizeof(char *) * (i + 5));
	final[i + 4] = NULL;
	k = -1;
	while (++k < i + 4)
	{
		final[k] = malloc(sizeof(char) * (maxlen + 5));
		final[k][maxlen + 4] = '\0';
	}
	ft_first_last_two_line(game, &final, maxlen);
	k = 1;
	while (++k < i + 2)
		ft_add_line_loop(game, &final, k, maxlen);
	return (final);
}
