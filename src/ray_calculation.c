/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:40:26 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/25 14:42:00 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

void		ft_basic_ray_param(t_win *win)
{
	win->rayi.camerax = (double)win->rayi.x / W * 2 - 1;
	win->rayi.rayposx = win->posx;
	win->rayi.rayposy = win->posy;
	win->rayi.raydirx = win->dirx + win->planex * win->rayi.camerax;
	win->rayi.raydiry = win->diry + win->planey * win->rayi.camerax;
	win->rayi.mapx = (int)win->rayi.rayposx;
	win->rayi.mapy = (int)win->rayi.rayposy;
	win->rayi.deltadistx = sqrt(1 + (win->rayi.raydiry * win->rayi.raydiry)
									/ (win->rayi.raydirx * win->rayi.raydirx));
	win->rayi.deltadisty = sqrt(1 + (win->rayi.raydirx * win->rayi.raydirx)
									/ (win->rayi.raydiry * win->rayi.raydiry));
	win->rayi.side = 0;
}

void		ft_find_side_dist(t_win *win)
{
	if (win->rayi.raydirx < 0)
	{
		win->rayi.stepx = -1;
		win->rayi.sidedistx = (win->rayi.rayposx - win->rayi.mapx)
							* win->rayi.deltadistx;
	}
	else
	{
		win->rayi.stepx = 1;
		win->rayi.sidedistx = (win->rayi.mapx + 1.0
							- win->rayi.rayposx) * win->rayi.deltadistx;
	}
	if (win->rayi.raydiry < 0)
	{
		win->rayi.stepy = -1;
		win->rayi.sidedisty = (win->rayi.rayposy
							- win->rayi.mapy) * win->rayi.deltadisty;
	}
	else
	{
		win->rayi.stepy = 1;
		win->rayi.sidedisty = (win->rayi.mapy + 1.0
							- win->rayi.rayposy) * win->rayi.deltadisty;
	}
}

void		ft_hit_calculation(t_win *win)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (win->rayi.sidedistx < win->rayi.sidedisty)
		{
			win->rayi.sidedistx += win->rayi.deltadistx;
			win->rayi.mapx += win->rayi.stepx;
			win->rayi.side = 0;
		}
		else
		{
			win->rayi.sidedisty += win->rayi.deltadisty;
			win->rayi.mapy += win->rayi.stepy;
			win->rayi.side = 1;
		}
		if (win->map[win->rayi.mapx][win->rayi.mapy] > 0)
			hit = 1;
	}
}

void		ft_set_line_param(t_win *win)
{
	if (win->rayi.side == 0)
		win->rayi.perpwalldist = (win->rayi.mapx - win->rayi.rayposx
								+ (1 - win->rayi.stepx) / 2)
								/ win->rayi.raydirx;
	else
		win->rayi.perpwalldist = (win->rayi.mapy - win->rayi.rayposy
								+ (1 - win->rayi.stepy) / 2)
								/ win->rayi.raydiry;
	win->wall.lineheight = (int)(H / win->rayi.perpwalldist
								* win->heightmod);
	win->wall.drawstart = -win->wall.lineheight / 2 + H / 2;
	if (win->wall.drawstart < 0)
		win->wall.drawstart = 0;
	win->wall.drawend = win->wall.lineheight / 2 + H / 2;
	if (win->wall.drawend >= H)
		win->wall.drawend = H - 1;
}

void		ft_set_tex_param(t_win *win)
{
	double wallx;

	if (win->rayi.side == 0)
		wallx = win->rayi.rayposy + win->rayi.perpwalldist * win->rayi.raydiry;
	else
		wallx = win->rayi.rayposx + win->rayi.perpwalldist * win->rayi.raydirx;
	wallx -= floor((wallx));
	ft_tex_numb(win, win->map[win->rayi.mapx][win->rayi.mapy]);
	win->wall.tex_x = (int)(wallx * (double)win->wall.t_w);
	if (win->rayi.side == 0 && win->rayi.raydirx > 0)
		win->wall.tex_x = win->wall.t_w - win->wall.tex_x - 1;
	if (win->rayi.side == 1 && win->rayi.raydiry < 0)
		win->wall.tex_x = win->wall.t_w - win->wall.tex_x - 1;
}
