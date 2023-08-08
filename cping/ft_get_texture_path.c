/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:29:05 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/08 21:03:30 by lzi-xian         ###   ########.fr       */
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
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_get_texture_path(t_game *game, int fd)
{
	int		i;
	int		j;
	int		c;
	char	*path;

	i = 0;
	c = 0;
	while (game->file[i])
	{
		if (!(ft_strncmp(game->file[i], "NO ", 3)))
		{
			path = ft_strdup(game->file[i]);
			if ((open(path + 3, O_RDWR)) == -1)
			{
				free(path);
				break;
			}
			ft_node_texture(game, path + 3, 1);
			free(path);
			c++;
		}
		else if (!(ft_strncmp(game->file[i], "SO ", 3)))
		{
			path = ft_strdup(game->file[i]);
			if ((open(path + 3, O_RDWR)) == -1)
			{
				free(path);
				break;
			}
			ft_node_texture(game, path + 3, 2);
			free(path);
			c++;
		}
		else if (!(ft_strncmp(game->file[i], "WE ", 3)))
		{
			path = ft_strdup(game->file[i]);
			if ((open(path + 3, O_RDWR)) == -1)
			{
				free(path);
				break;
			}
			ft_node_texture(game, path + 3, 3);
			free(path);
			c++;
		}
		else if (!(ft_strncmp(game->file[i], "EA ", 3)))
		{
			path = ft_strdup(game->file[i]);
			if ((open(path + 3, O_RDWR)) == -1)
			{
				free(path);
				break;
			}
			ft_node_texture(game, path + 3, 4);
			free(path);
			c++;
		}
		i++;
	}
	if (c != 4)
	{
		printf("invalid texture");
		exit(0);
	}
	ft_node_texture(game, "./assets/door.xpm", 5);
	ft_node_texture(game, "./assets/door.xpm", 6);
}

char	*check_f(t_game *game)
{
	char	*path;
	int	check;
	int	i;

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
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0]== 'C')
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