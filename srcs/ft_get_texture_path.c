/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:29:05 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/07 18:06:46 by lzi-xian         ###   ########.fr       */
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

void	ft_get_texture_path(t_game *game, int fd)
{
	int		i;
	int		j;
	char	*path;

	i = 1;
	while (i < 5)
	{
		j = 0;
		path = get_next_line(fd);
		while (path[j])
		{
			if (path[j] == '\n')
			{
				path[j] = '\0';
				break ;
			}
			j++;
		}
		ft_node_texture(game, path + 3, i);
		i++;
		free(path);
	}
	ft_node_texture(game, "./assets/door.xpm", 5);
	ft_node_texture(game, "./assets/door.xpm", 6);
}
