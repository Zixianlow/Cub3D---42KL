/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:20:35 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/31 12:30:26 by lzi-xian         ###   ########.fr       */
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

typedef struct s_line
{
	int				x;
	int				y;
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

typedef struct s_gun
{
	void	*gun1;
	void	*gun2;
	void	*gun3;
	void	*gun4;
}	t_gun;

typedef struct s_dis
{
	double	sh;
	double	wh;
}	t_dis;

typedef struct s_inter
{
	double	x[4];
	double	tx;
	double	ty;
	double	fx;
	double	fy;
	double	tdis;
	double	fdis;
}	t_inter;

typedef struct s_game
{
	int			frame;
	int			gunframe;
	int			type;
	int			guntype;
	int			map_i;
	double		posx;
	void		*mlx;
	void		*win;
	t_fc		fc;
	t_gun		gun;
	t_tex		*tex;
	t_dis		dis;
	t_inter		v;
	t_player	player;
	t_line		*line;
	char		**map;
	char		**map2;
	char		**file;
}	t_game;

void	ft_get_texture_path(t_game *game);
int		ft_get_map(t_game *game, char *path);
void	ft_draw_minimap(t_game *game);
void	ft_get_line(t_game *game);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	ft_draw_player(t_game *game);
void	ft_door_open(t_game *game);
int		kclose(int keycode, t_game *game);
int		mouse_hook(int x, int y, t_game *game);
void	ft_draw_view(t_game *game, int pos);
void	ft_draw_line(t_game *game, double x1, double y1, double a);
void	ft_node_line1(t_game *game, int i, int j, int type);
void	ft_node_line2(t_game *game, int i, int j, int type);
void	ft_node_line3(t_game *game, int i, int j, int type);
void	ft_node_line4(t_game *game, int i, int j, int type);
double	ft_intersect(t_game *game, double *lx, double *ly);
void	ft_get_tdis(t_game *game, double *lx, double *ly, t_inter *v);
void	ft_map2(t_game *game);
void	ft_makemap(t_game *game, int maxlen);
char	*ft_check_cf(t_game *game, char ch);
void	ft_get_file(t_game *game, int fd);
void	ft_get_map_tile(t_game *game, int fd);
void	ft_get_floor_rgb(t_game *game, char *line);
void	ft_get_ceiling_rgb(t_game *game, char *line);
int		ft_check_element(t_game *game);
int		ft_check_valid(t_game *game, char ***final);
char	**ft_final_line(t_game *game, int maxlen);
void	ft_perror_exit(char *s, t_game *game, int type);
void	ft_wall_collision(t_game *game, int move);
void	ft_get_gun_pic(t_game *game);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_check_line(char *s);
int		ft_check_map(t_game *game);
int		render_next_frame(t_game *game, int type);
int		ft_change_pos(t_game *game, double i, double j);

#endif