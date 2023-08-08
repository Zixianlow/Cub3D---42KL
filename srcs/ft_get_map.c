/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/07 21:32:20 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_floor_rgb(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		j;

	line = get_next_line(fd);
	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	j = i + 1;
	while (line[j] && line[j] != ',')
		j++;
	game->fc.fr = ft_atoi(line + 2);
	game->fc.fg = ft_atoi(line + i + 1);
	game->fc.fb = ft_atoi(line + j + 1);
	game->fc.floor_rgb = (game->fc.fr << 16 | game->fc.fg << 8 | game->fc.fb);
	free(line);
}

void	ft_get_ceiling_rgb(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		j;

	line = get_next_line(fd);
	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	j = i + 1;
	while (line[j] && line[j] != ',')
		j++;
	game->fc.cr = ft_atoi(line + 2);
	game->fc.cg = ft_atoi(line + i + 1);
	game->fc.cb = ft_atoi(line + j + 1);
	game->fc.ceiling_rgb = (game->fc.cr << 16 | game->fc.cg << 8 | game->fc.cb);
	free(line);
}

char	**ft_free_and_malloc(char **str, int h)
{
	void	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char **) * h);
	if (!dest)
	{
		while (str[i])
			free(str[i++]);
		free(str);
		return (NULL);
	}
	if (!(*str))
	{
		free(dest);
		return (NULL);
	}
	while (i < h - 1)
	{
		dest[i] = ft_strdup(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return ((char **)dest);
}

void	ft_get_map_tile(t_game *game, int fd)
{
	int	h;
	int	l;

	h = 0;
	game->map = malloc(sizeof(char **));
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

int	ft_get_map(t_game *game, char *path)
{
	int	i;
	int	fd;

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
		exit(0);
	ft_get_texture_path(game, fd);
	get_next_line(fd);
	ft_get_floor_rgb(game, fd);
	ft_get_ceiling_rgb(game, fd);
	get_next_line(fd);
	ft_get_map_tile(game, fd);
	close(fd);
	return (0);
}
