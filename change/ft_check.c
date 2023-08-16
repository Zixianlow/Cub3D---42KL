/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:10:51 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 20:35:33 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_all_one(int *a)
{
	return (a[0] == 1 && a[1] == 1 && a[2] == 1
		&& a[3] == 1 && a[4] == 1 && a[5] == 1);
}

int	ft_check_element(t_game *game)
{
	int	i;
	int	a[6];

	i = -1;
	while (++i < 6)
		a[i] = 0;
	i = -1;
	while (game->file[++i])
	{
		if (game->file[i][0] == 'F')
			a[0]++;
		else if (game->file[i][0] == 'C')
			a[1]++;
		else if (game->file[i][0] == 'N')
			a[2]++;
		else if (game->file[i][0] == 'S')
			a[3]++;
		else if (game->file[i][0] == 'W')
			a[4]++;
		else if (game->file[i][0] == 'E')
			a[5]++;
	}
	if (ft_check_all_one(a))
		return (1);
	return (0);
}

int	ft_check_valid_pad(char **final, int i, int k)
{
	if (final[i][k - 1] == '2' || final[i][k - 1] == '0')
		return (1);
	else if (final[i][k + 1] == '2' || final[i][k + 1] == '0')
		return (1);
	else if (final[i + 1][k + 1] == '2' || final[i + 1][k + 1] == '0')
		return (1);
	else if (final[i - 1][k + 1] == '2' || final[i - 1][k + 1] == '0')
		return (1);
	else if (final[i + 1][k - 1] == '2' || final[i + 1][k - 1] == '0')
		return (1);
	else if (final[i - 1][k - 1] == '2' || final[i - 1][k - 1] == '0')
		return (1);
	else if (final[i + 1][k] == '2' || final[i + 1][k] == '0')
		return (1);
	else if (final[i - 1][k] == '2' || final[i - 1][k] == '0')
		return (1);
	return (0);
}

void	ft_free_map2_final(t_game *game, char **final)
{
	int	i;

	i = -1;
	while (game->map2[++i])
		free(game->map2[i]);
	free(game->map2);
	i = -1;
	while (final[++i])
		free(final[i]);
	free(final);
}

int	ft_check_valid(t_game *game, char **final)
{
	int	i;
	int	k;

	i = -1;
	while (final[++i])
	{
		k = -1;
		while (final[i][++k])
		{
			if (final[i][k] == 's')
			{
				if (ft_check_valid_pad(final, i, k))
				{
					ft_free_map2_final(game, final);
					return (0);
				}
			}
		}
	}
	ft_free_map2_final(game, final);
	return (1);
}
