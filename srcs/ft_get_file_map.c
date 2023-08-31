/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:27:20 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 13:22:34 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_free_and_malloc(char **str, int h)
{
	void	**dest;
	int		i;

	dest = malloc(sizeof(char *) * h);
	i = -1;
	if (!dest)
	{
		while (str[++i])
			free(str[i]);
		free(str);
		return (NULL);
	}
	if (!(*str))
	{
		free(dest);
		return (NULL);
	}
	while (++i < h - 1)
	{
		dest[i] = ft_strdup(str[i]);
		free(str[i]);
	}
	dest[i] = NULL;
	free(str);
	return ((char **)dest);
}

void	ft_get_file(t_game *game, int fd)
{
	int	h;
	int	l;
	int	check;

	check = 0;
	h = 0;
	game->file = malloc(sizeof(char *));
	while (1)
	{
		game->file[h] = get_next_line(fd);
		if (!(game->file[h]))
			break ;
		if (game->file[h][0] == 'F' || game->file[h][0] == 'C'
			|| game->file[h][0] == 'N' || game->file[h][0] == 'S'
			|| game->file[h][0] == 'W' || game->file[h][0] == 'E')
			check++;
		l = ft_strlen(game->file[h]);
		if (l != 1 && game->file[h][l - 1] == '\n')
			game->file[h][l - 1] = '\0';
		h++;
		game->file = ft_free_and_malloc(game->file, h + 1);
		if (check == 6)
			break ;
	}
}

int	ft_get_map_tile_first(t_game *game, int h, int fd)
{
	int	l;

	game->map[h] = get_next_line(fd);
	while (game->map[h][0] == '\n')
	{
		free(game->map[h]);
		game->map[h] = get_next_line(fd);
	}
	l = ft_strlen(game->map[h]);
	if (game->map[h][l - 1] == '\n')
		game->map[h][l - 1] = '\0';
	h++;
	game->map = ft_free_and_malloc(game->map, h + 1);
	return (h);
}

void	ft_get_map_tile(t_game *game, int fd)
{
	int	h;
	int	l;

	h = 0;
	game->map = malloc(sizeof(char *));
	h = ft_get_map_tile_first(game, h, fd);
	while (1)
	{
		game->map[h] = get_next_line(fd);
		if (!(game->map[h]))
			break ;
		l = ft_strlen(game->map[h]);
		if (game->map[h][l - 1] == '\n')
			game->map[h][l - 1] = '\0';
		h++;
		game->map = ft_free_and_malloc(game->map, h + 1);
	}
}
