/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:10:51 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/30 21:10:28 by lzi-xian         ###   ########.fr       */
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
	int	a[7];

	a[6] = -1;
	while (++a[6] < 6)
		a[a[6]] = 0;
	a[6] = -1;
	while (game->file[++a[6]])
	{
		if (!(ft_strncmp(game->file[a[6]], "F ", 2)))
			a[0]++;
		else if (!(ft_strncmp(game->file[a[6]], "C ", 2)))
			a[1]++;
		else if (!(ft_strncmp(game->file[a[6]], "NO ", 3)))
			a[2]++;
		else if (!(ft_strncmp(game->file[a[6]], "SO ", 3)))
			a[3]++;
		else if (!(ft_strncmp(game->file[a[6]], "EA ", 3)))
			a[4]++;
		else if (!(ft_strncmp(game->file[a[6]], "WE ", 3)))
			a[5]++;
		else if (ft_check_line(game->file[a[6]]))
			break ;
	}
	return (ft_check_all_one(a));
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
	if (ft_check_map(game))
		return (0);
	ft_free_map2_final(game, final);
	return (1);
}
