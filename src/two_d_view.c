/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 12:05:16 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/22 12:06:14 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

static int		ft_isitwall(t_win *win, double x, double y)
{
	int			newx;
	int			newy;

	newx = (int)x / BLOCK;
	newy = (int)y / BLOCK;
	if ((newx > 16 || newy > 24 || newy < 0 || newx < 0)
		|| (win->map[newx][newy] != 0))
		return (0);
	else
		return (1);
}

static void		ft_draw_rayway(t_win *win, double tmp_a,
								double ray_x, double ray_y)
{
	if (round(tmp_a) != (sin(win->dirx) + cos(win->diry)))
		mlx_pixel_put(win->mlx, win->win, (int)round(ray_y) + MX,
					(int)round(ray_x) + MY, 0xFFFFFF);
	else
		mlx_pixel_put(win->mlx, win->win, (int)round(ray_y) + MX,
					(int)round(ray_x) + MY, 0xFF0000);
}

static void		ft_rayway(t_win *win, double tmp_a)
{
	double		ray_x;
	double		ray_y;
	double		dir_x;
	double		dir_y;

	ray_x = win->posx * BLOCK;
	ray_y = win->posy * BLOCK;
	dir_x = ray_x + cos(0.0174533 * tmp_a);
	dir_y = ray_y + sin(0.0174533 * tmp_a);
	dir_x -= ray_x;
	dir_y -= ray_y;
	while (ft_isitwall(win, ray_x, ray_y))
	{
		ft_draw_rayway(win, tmp_a, ray_x, ray_y);
		ray_x += dir_x;
		ray_y += dir_y;
	}
}

static void		ft_putray(t_win *win)
{
	int			i;
	double		tmp_a;

	i = 0;
	if (win->dirx > 1.0)
		win->dirx = 1;
	tmp_a = (acos(win->dirx) * 180 / 3.14);
	if (win->diry < 0)
		tmp_a = -1 * tmp_a;
	tmp_a -= (FOV / 2);
	while (i < W)
	{
		ft_rayway(win, tmp_a);
		tmp_a += (double)FOV / (W * 1.1);
		i++;
	}
}

void			ft_putman(t_win *win)
{
	ft_display_walls(win, 0x000000);
	mlx_pixel_put(win->mlx, win->win, (int)(win->posy * BLOCK + MX),
				(int)(win->posx * BLOCK - 1 + MY), 0x000000);
	mlx_pixel_put(win->mlx, win->win, (int)(win->posy * BLOCK + MX),
				(int)(win->posx * BLOCK + 1 + MY), 0x000000);
	mlx_pixel_put(win->mlx, win->win, (int)(win->posy * BLOCK + MX),
				(int)(win->posx * BLOCK + MY), 0x000000);
	mlx_pixel_put(win->mlx, win->win, (int)(win->posy * BLOCK - 1 + MX),
				(int)(win->posx * BLOCK + MY), 0x000000);
	mlx_pixel_put(win->mlx, win->win, (int)(win->posy * BLOCK + 1 + MX),
				(int)(win->posx * BLOCK + MY), 0x000000);
	ft_putray(win);
}
