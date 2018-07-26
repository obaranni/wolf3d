/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 12:50:19 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/22 12:51:53 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

static void		ft_fill_square(t_win *win, int x_pos, int y_pos, int color)
{
	int			x;
	int			y;

	x = x_pos * BLOCK;
	y = y_pos * BLOCK;
	while (y < BLOCK + y_pos * BLOCK)
	{
		x = x_pos * BLOCK;
		while (x < BLOCK + x_pos * BLOCK)
		{
			if (x % BLOCK == 0 || y % BLOCK == 0 || x - (BLOCK * x_pos)
					== BLOCK - 1 || y - (BLOCK * y_pos) == BLOCK - 1)
				mlx_pixel_put(win->mlx, win->win, y + MX, x + MY, 0x000000);
			else
				mlx_pixel_put(win->mlx, win->win, y + MX, x + MY, color);
			x++;
		}
		y++;
	}
}

void			ft_display_walls(t_win *win, int color)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x + 24 * y < 384)
	{
		if (win->map[y][x] != 0)
			ft_fill_square(win, y, x, color + win->map[y][x]);
		if (x == 23)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}
