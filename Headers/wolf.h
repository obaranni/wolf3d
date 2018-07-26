/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:27:59 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/25 19:16:17 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# define W 1536
# define H 1024
# define BLOCK 20
# define S 1
# define D 5
# define FOV 60
# define MX 1050
# define MY 10

typedef struct	s_tex
{
	void		*t_img;
	char		*data;
	int			bpp;
	int			sl;
	int			en;
	int			w;
	int			h;
}				t_tex;

typedef struct	s_wall
{
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			tex_x;
	int			t_w;
	int			t_h;
	char		*data;
	t_tex		tmp_t;
}				t_wall;

typedef struct	s_rayi
{
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			side;
	int			x;
}				t_rayi;

typedef struct	s_win
{
	t_tex		t1;
	t_tex		t2;
	t_tex		t3;
	t_wall		wall;
	t_rayi		rayi;
	void		*mlx;
	void		*win;
	void		*img;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		oldtime;
	double		rotspeed;
	double		movespeed;
	double		heightmod;
	int			**map;
	int			version;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			g;
}				t_win;

int				ft_read_textures(t_win *win);
void			ft_init_window(t_win *win);
void			ft_init_game_params(t_win *win);
int				ft_keyhook(int kc, t_win *win);
void			ft_tex_numb(t_win *win, int n);
void			ft_basic_ray_param(t_win *win);
void			ft_find_side_dist(t_win *win);
void			ft_hit_calculation(t_win *win);
void			ft_set_line_param(t_win *win);
void			ft_set_tex_param(t_win *win);
void			ft_display(t_win *win);
int				ft_readmap(t_win *win);
void			ft_pixel_put(t_win *win, int x, int y, int color);
void			ft_putray_obj(t_win *win);
void			ft_putman(t_win *win);
void			ft_display_walls(t_win *win, int color);

#endif
