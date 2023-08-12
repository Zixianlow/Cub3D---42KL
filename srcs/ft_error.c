/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:03:56 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 13:29:08 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_game_map_line(t_game *game)
{
	int	i;

	i = -1;
	while (game->line)
	{
		free(game->line);
		game->line = game->line->next;
	}
	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
}

void	ft_free_game_tex(t_game *game)
{
	while (game->tex)
	{
		mlx_destroy_image(game->mlx, game->tex->img);
		free(game->tex);
		game->tex = game->tex->next;
	}
}

void	ft_free_game_file(t_game *game)
{
	int	i;

	i = -1;
	while (game->file[++i])
		free(game->file[i]);
	free(game->file);
}

void	ft_perror_exit(char *s, t_game *game, int type)
{
	if (type > 0)
		ft_free_game_file(game);
	if (type > 1)
		ft_free_game_tex(game);
	if (type > 2)
		ft_free_game_map_line(game);
	write(2, s, ft_strlen(s));
	exit(0);
}
