/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:03:56 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 19:09:42 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_game_gun(t_game *game)
{
	mlx_destroy_image(game->mlx, game->gun.gun1);
	mlx_destroy_image(game->mlx, game->gun.gun2);
	mlx_destroy_image(game->mlx, game->gun.gun3);
	mlx_destroy_image(game->mlx, game->gun.gun4);
}

void	ft_free_game_map_line(t_game *game)
{
	int		i;
	t_line	*temp;

	i = -1;
	while (game->line)
	{
		temp = game->line;
		game->line = game->line->next;
		free(temp);
	}
	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
}

void	ft_free_game_tex(t_game *game)
{
	t_tex	*temp;

	while (game->tex)
	{
		mlx_destroy_image(game->mlx, game->tex->img);
		temp = game->tex;
		game->tex = game->tex->next;
		free(temp);
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
	if (type > 3)
		ft_destroy_game_gun(game);
	write(2, s, ft_strlen(s));
	exit(0);
}
