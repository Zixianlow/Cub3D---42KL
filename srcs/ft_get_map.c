/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 13:08:38 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line(char *s)
{
	int	i;

	i = 0;
	if (s[i] == 32)
	{
		while (s[i] == 32)
			i++;
		if (s[i])
			return (1);
	}
	else if (s[i] != '\n')
		return (1);
	return (0);
}

int	ft_getlen(t_game *game)
{
	int	i;
	int	j;
	int	maxlen;

	i = -1;
	maxlen = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j > maxlen)
			maxlen = j;
	}
	game->map_i = i;
	return (maxlen);
}

void	ft_get_game_elment(t_game *game, int fd)
{
	ft_get_texture_path(game);
	ft_get_floor_rgb(game, ft_check_cf(game, 'F'));
	ft_get_ceiling_rgb(game, ft_check_cf(game, 'C'));
	ft_get_map_tile(game, fd);
	ft_map2(game);
	ft_makemap(game, ft_getlen(game));
}

int	ft_get_map(t_game *game, char *path)
{
	int		i;
	int		fd;
	char	**final;

	i = 0;
	while (path[i])
		i++;
	if (i < 5)
		return (1);
	if (path[i - 1] != 'b' || path[i - 2] != 'u')
		return (1);
	if (path[i - 3] != 'c' || path[i - 4] != '.')
		return (1);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		ft_perror_exit("Error opening map file\n", game, 0);
	ft_get_file(game, fd);
	if (!(ft_check_element(game)))
		ft_perror_exit("Invalid element count\n", game, 1);
	ft_get_game_elment(game, fd);
	final = ft_final_line(game, ft_getlen(game));
	if (!(ft_check_valid(game, &final)))
		ft_perror_exit("Map is invalid", game, 3);
	close(fd);
	return (0);
}
