/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:47:44 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/25 14:47:48 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

int			ft_tx_put(t_win *win, int x, int y)
{
	int		d;
	int		texy;

	while (y <= win->wall.drawend && y < H)
	{
		d = y * 256 - H * 128 + win->wall.lineheight * 128;
		texy = ((d * win->wall.t_h) / win->wall.lineheight) / 256;
		win->data[(W * y + x) * 4] = win->wall.data[(win->wall.t_w
											* texy + win->wall.tex_x) * 4];
		win->data[(W * y + x) * 4 + 1] = win->wall.data[(win->wall.t_w
											* texy + win->wall.tex_x) * 4 + 1];
		win->data[(W * y + x) * 4 + 2] = win->wall.data[(win->wall.t_w
											* texy + win->wall.tex_x) * 4 + 2];
		win->data[(W * y + x) * 4 + 3] = win->wall.data[(win->wall.t_w
											* texy + win->wall.tex_x) * 4 + 3];
		y++;
	}
	return (0);
}

static void	ft_display_line(t_win *win, int x)
{
	int		y;

	y = 0;
	while (y < win->wall.drawstart)
	{
		ft_pixel_put(win, x, y, 0x0ff3f9);
		y++;
	}
	ft_tx_put(win, x, y);
	y = win->wall.drawend;
	while (y <= H)
	{
		ft_pixel_put(win, x, y, 0x524a3c);
		y++;
	}
}

void		ft_putray_obj(t_win *win)
{
	win->rayi.x = 0;
	while (win->rayi.x < W)
	{
		ft_basic_ray_param(win);
		ft_find_side_dist(win);
		ft_hit_calculation(win);
		ft_set_line_param(win);
		ft_set_tex_param(win);
		ft_display_line(win, win->rayi.x);
		win->rayi.x++;
	}
}
