/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 12:29:00 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/25 19:20:38 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

static void		ft_gun(t_win *win)
{
	if (win->g == 0)
		win->g = 1;
	else
		win->g = 0;
}

static void		ft_rot(t_win *win, int kc)
{
	double		old_dx;
	double		old_px;
	int			x;

	x = 1;
	if (kc == 123)
		x = x * -1;
	old_dx = win->dirx;
	win->dirx = win->dirx * cos(x * (win->rotspeed))
				- win->diry * sin(x * (win->rotspeed));
	win->diry = old_dx * sin(x * (win->rotspeed))
				+ win->diry * cos(x * (win->rotspeed));
	old_px = win->planex;
	win->planex = win->planex * cos(x * (win->rotspeed))
				- win->planey * sin(x * (win->rotspeed));
	win->planey = old_px * sin(x * (win->rotspeed))
				+ win->planey * cos(x * (win->rotspeed));
}

static void		ft_runrot(int kc, t_win *win)
{
	if (kc == 126)
	{
		if (win->map[(int)(win->posx + win->dirx * win->movespeed)]
		[(int)win->posy] == 0)
			win->posx += win->dirx * win->movespeed;
		if (win->map[(int)(win->posx)]
		[(int)(win->posy + win->diry * win->movespeed)] == 0)
			win->posy += win->diry * win->movespeed;
	}
	else if (kc == 125)
	{
		if (win->map[(int)(win->posx - win->dirx * win->movespeed)]
		[(int)(win->posy)] == 0)
			win->posx -= win->dirx * win->movespeed;
		if (win->map[(int)(win->posx)]
		[(int)(win->posy - win->diry * win->movespeed)] == 0)
			win->posy -= win->diry * win->movespeed;
	}
	else
		ft_rot(win, kc);
}

int				ft_keyhook(int kc, t_win *win)
{
	mlx_clear_window(win->mlx, win->win);
	if (kc == 5)
		ft_gun(win);
	else if (kc >= 123 && kc <= 126)
		ft_runrot(kc, win);
	else if (kc == 9)
	{
		if (win->version == 0)
			win->version = 1;
		else
			win->version = 0;
	}
	else if (kc == 30 && win->heightmod < 3)
		win->heightmod += 0.1;
	else if (kc == 33 && win->heightmod > 0.3)
		win->heightmod -= 0.1;
	else if (kc == 53)
	{
		system("killall afplay 2&>/dev/null >/dev/null");
		exit(0);
	}
	ft_display(win);
	return (0);
}
