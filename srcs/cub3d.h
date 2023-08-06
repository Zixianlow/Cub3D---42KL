/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:20:35 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/06 20:03:27 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"

# define MAP_W 10
# define MAP_H 10
# define TILE_SIZE 64
# define FOV_A M_PI / 3

typedef struct s_line
{
	double			ax;
	double			ay;
	double			bx;
	double			by;
	int				type;
	struct s_line	*next;
}	t_line;

typedef struct s_player
{
	double	x;
	double	y;
	double	m;
	double	c;
	double	angle;
}	t_player;

typedef struct s_fc
{
	int	fr;
	int	fg;
	int	fb;
	int	cr;
	int	cg;
	int	cb;
	int	floor_rgb;
	int	ceiling_rgb;
}	t_fc;

typedef struct s_tex
{
	void			*img;
	unsigned char	*img_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				img_h;
	int				img_w;
	int				type;
	struct s_tex	*next;
}	t_tex;

typedef struct s_dis
{
	double	sh;
	double	wh;
	double	fh;
}	t_dis;

typedef struct s_game
{
	double		tune;
	int			frame;
	int			type;
	double		posx;
	void		*mlx;
	void		*win;
	t_fc		fc;
	t_tex		*tex;
	t_dis		dis;
	t_player	player;
	t_line		*line;
	char		**map;
}	t_game;

void	ft_get_texture_path(t_game *game, int fd);
int		ft_get_map(t_game *game, char *path);
void	draw_minimap(t_game *game);
void	ft_get_line(t_game *game);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	draw_player(t_game *game);

#endif