/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:29:05 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/11 20:54:16 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_node_texture(t_game *game, char *path, int i)
{
	t_tex	*temp;
	t_tex	*node;

	temp = game->tex;
	node = malloc(sizeof(t_tex));
	node->img = mlx_xpm_file_to_image
		(game->mlx, path, &node->img_w, &node->img_h);
	node->img_data = (unsigned char *)mlx_get_data_addr
		(node->img, &node->bits_per_pixel, &node->size_line, &node->endian);
	node->type = i;
	node->next = NULL;
	if (!temp)
		game->tex = node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i] || !str1[i] || !str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_texture_check_set(t_game *game, int i, int *c, int type)
{
	int		k;
	int		fd;
	char	*path;

	path = ft_strdup(game->file[i]);
	k = 2;
	while (path[k] == ' ')
		k++;
	fd = open(path + k, O_RDWR);
	if (fd == -1)
	{
		free(path);
		return (1);
	}
	close(fd);
	ft_node_texture(game, path + k, type);
	free(path);
	(*c)++;
	return (0);
}

int	ft_get_texture_path_loop(t_game *game, int i, int *c)
{
	if (!(ft_strncmp(game->file[i], "NO ", 3)))
	{
		if (ft_texture_check_set(game, i, c, 1))
			return (1);
	}
	else if (!(ft_strncmp(game->file[i], "SO ", 3)))
	{
		if (ft_texture_check_set(game, i, c, 2))
			return (1);
	}
	else if (!(ft_strncmp(game->file[i], "WE ", 3)))
	{
		if (ft_texture_check_set(game, i, c, 3))
			return (1);
	}
	else if (!(ft_strncmp(game->file[i], "EA ", 3)))
	{
		if (ft_texture_check_set(game, i, c, 4))
			return (1);
	}
	return (0);
}

void	ft_get_texture_path(t_game *game, int fd)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	c = 0;
	while (game->file[++i])
	{
		if (ft_get_texture_path_loop(game, i, &c))
			break ;
	}
	if (c != 4)
		ft_perror_exit("Invalid texture found", game, 2);
	ft_node_texture(game, "./assets/door.xpm", 5);
	ft_node_texture(game, "./assets/door.xpm", 6);
}
