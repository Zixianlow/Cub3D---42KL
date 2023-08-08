/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:18 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 20:42:15 by cping-xu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (game->file[h][0] == 'F' || game->file[h][0] == 'C' || game->file[h][0] == 'N' ||\
		game->file[h][0] == 'S' || game->file[h][0] == 'W' || game->file[h][0] == 'E')
		{
			check++;
		}
		l = ft_strlen(game->file[h]);
		if (game->file[h][l - 1] == '\n')
			game->file[h][l - 1] = '\0';
		h++;
		// game->file = ft_free_and_malloc(game->file, h + 1);
		if (check == 6)
			break;
	}
	game->file[h] = 0;
}

int	check_element(t_game *game)
{
	int	i;
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	while (game->file[i])
	{
		if (game->file[i][0] == 'F')
			a++;
		else if (game->file[i][0] == 'C')
			b++;
		else if (game->file[i][0] == 'N')
			c++;
		else if (game->file[i][0] == 'S')
			d++;
		else if (game->file[i][0] == 'W')
			e++;
		else if (game->file[i][0] == 'E')
			f++;
		i++;
	}
	if (a == 1 && b == 1 && c == 1 && d == 1\
	&& e == 1 && f == 1)
		return (1);
	return (0);
}

void	ft_get_floor_rgb(t_game *game, int fd, char  *line)
{
	// char	*line;
	int		i;
	int		j;

	// check first alpha is F or not (F 220,100,0) and is it the only one
	// line = get_next_line(fd);
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

void	ft_get_ceiling_rgb(t_game *game, int fd, char *line)
{
	// char	*line;
	int		i;
	int		j;

	// check first alpha is C or not (C 225,30,0) and is it the only one
	// line = get_next_line(fd);
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
	dest = malloc(sizeof(char *) * h);
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
	game->map = malloc(sizeof(char *));
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

int	getlen(t_game *game)
{
	int	i;
	int	j;
	int	maxlen;

	i = 0;
	maxlen = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			j++;
		}
		if (j > maxlen)
		{
			maxlen = j;
		}
		i++;
	}
	return (maxlen);
}

void	makemap(t_game *game, int maxlen)
{
	char	*store;
	int	i;
	int	j;
	int	temp;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			j++;
		}
		if (j <= maxlen)
		{
			store = ft_strdup(game->map[i]);
			free(game->map[i]);
			game->map[i] = malloc(sizeof(char) * maxlen + 1);
			game->map[i][maxlen] = '\0';
		}
		temp = 0;
		while (store[temp])
		{
			game->map[i][temp] = store[temp];
			temp++;
		}
		while (j < maxlen)
		{
			game->map[i][j] = 32;
			j++;
		}
		i++;
	}
}

char	**addline(t_game *game, int maxlen)
{
	char	**final;
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	while(game->map[i])
	{
		i++;
	}
	final = malloc(sizeof(char *) * (i + 5));
	final[i + 4] = NULL;
	while (j < i + 4)
	{
		final[j] = malloc(sizeof(char) * (maxlen + 5));
		final[j][maxlen + 4] = '\0';
		j++;
	}
	k = 0;
	l = 0;
	while (l < maxlen + 4)
	{
		final[k][l] = 'w';
		final[k + 1][l] = 's';
		final[i + 2][l] = 's';
		final[i + 3][l] = 'w';
		l++;
	}
	final[k + 1][0] = 'w';
	final[i + 2][0] = 'w';
	final[k + 1][l - 1] = 'w';
	final[i + 2][l - 1] = 'w';
	k = 2;
	while (k < i + 2)
	{
		l = 0;
		final[k][l] = 'w';
		l++;
		final[k][l] = 's';
		l++;
		while (l < maxlen + 2)
		{
			if (game->map[k - 2][l - 2] == ' ')
				final[k][l] = 's';
			else
				final[k][l] = game->map[k - 2][l - 2];
			l++;
		}
		final[k][l] = 's';
		l++;
		final[k][l] = 'w';
		k++;
	}
	// i = 0;
	// while (game->map[i])
	// {
	// 	k = 0;
	// 	while (game->map[i][k])
	// 	{
	// 		printf("%c", game->map[i][k]);
	// 		k++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// // printf("%c", game->map[i][k]);
	// i = 0;
	// while(final[i])
	// {
	// 	printf("%s\n", final[i]);
	// 	i++;
	// }
	return (final);
}


int	check_valid(char **final)
{
	int	i;
	int	k;

	i = 0;
	while (final[i])
	{
		k = 0;
		while (final[i][k])
		{
			if (final[i][k] == 's')
			{
				if (final[i][k - 1] == '2' || final[i][k - 1] == '0')
					return (0);
				else if (final[i][k + 1] == '2' || final[i][k + 1] == '0')
					return (0);
				else if (final[i + 1][k + 1] == '2' || final[i + 1][k + 1] == '0')
					return (0);
				else if (final[i - 1][k + 1] == '2' || final[i - 1][k + 1] == '0')
					return (0);
				else if (final[i + 1][k - 1] == '2' || final[i + 1][k - 1] == '0')
					return (0);
				else if (final[i - 1][k - 1] == '2' || final[i - 1][k - 1] == '0')
					return (0);
				else if (final[i + 1][k] == '2' || final[i + 1][k] == '0')
					return (0);
				else if (final[i - 1][k] == '2' || final[i - 1][k] == '0')
					return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_get_map(t_game *game, char *path)
{
	int	i;
	int	fd;
	int maxlen;
	char	**final;
	char	*path_f;
	char	*path_c;

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
	// get_next_line(fd);
	ft_get_file(game, fd);
	if (!(check_element(game)))
	{
		printf("invalid element");
		exit(0);
	}
	ft_get_texture_path(game, fd);
	path_f = check_f(game);
	ft_get_floor_rgb(game, fd, path_f);
	path_c = check_c(game);
	ft_get_ceiling_rgb(game, fd, path_c);
	// get_next_line(fd);
	ft_get_map_tile(game, fd);
	maxlen = getlen(game);
	makemap(game, maxlen);
	final = addline(game, maxlen);
	if (!(check_valid(final)))
	{
		printf("invalid map");
		exit(0);
	}
	close(fd);
	return (0);
}
