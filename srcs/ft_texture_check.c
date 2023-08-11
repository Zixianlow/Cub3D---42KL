/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:51:11 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 17:25:29 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*check_f(t_game *game)
{
	char	*path;
	int		check;
	int		i;

	check = 0;
	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == 'F')
		{
			path = ft_strdup(game->file[i]);
			check++;
		}
		i++;
	}
	if (check == 1)
		return (path);
	return (0);
}

char	*check_c(t_game *game)
{
	char	*path;
	int		check;
	int		i;

	check = 0;
	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == 'C')
		{
			path = ft_strdup(game->file[i]);
			check++;
		}
		i++;
	}
	if (check == 1)
		return (path);
	return (0);
}

void	ft_get_floor_rgb(t_game *game, int fd, char *line)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	j = i + 1;
	while (line[j] && line[j] != ',')
		j++;
	k = 1;
	while (line[k] == ' ')
		k++;
	game->fc.fr = ft_atoi(line + k);
	game->fc.fg = ft_atoi(line + i + 1);
	game->fc.fb = ft_atoi(line + j + 1);
	game->fc.floor_rgb = (game->fc.fr << 16 | game->fc.fg << 8 | game->fc.fb);
	free(line);
}

void	ft_get_ceiling_rgb(t_game *game, int fd, char *line)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	j = i + 1;
	while (line[j] && line[j] != ',')
		j++;
	k = 1;
	while (line[k] == ' ')
		k++;
	game->fc.cr = ft_atoi(line + k);
	game->fc.cg = ft_atoi(line + i + 1);
	game->fc.cb = ft_atoi(line + j + 1);
	game->fc.ceiling_rgb = (game->fc.cr << 16 | game->fc.cg << 8 | game->fc.cb);
	free(line);
}
