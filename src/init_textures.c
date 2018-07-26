/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:37:58 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/22 15:38:09 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

void		ft_tex_numb(t_win *win, int n)
{
	if (n == 1)
	{
		win->wall.t_w = win->t1.w;
		win->wall.data = win->t1.data;
		win->wall.t_h = win->t1.h;
	}
	if (n == 2)
	{
		win->wall.t_w = win->t2.w;
		win->wall.data = win->t2.data;
		win->wall.t_h = win->t2.h;
	}
	if (n == 3)
	{
		win->wall.t_w = win->t3.w;
		win->wall.data = win->t3.data;
		win->wall.t_h = win->t3.h;
	}
}

int			ft_read_textures(t_win *win)
{
	win->t1.t_img = mlx_xpm_file_to_image(win->mlx,
			"textures/eagle.xpm", &win->t1.w, &win->t1.h);
	win->t1.data = mlx_get_data_addr(win->t1.t_img,
			&win->t1.bpp, &win->t1.sl, &win->t1.en);
	win->t2.t_img = mlx_xpm_file_to_image(win->mlx,
			"textures/colorstone.xpm", &win->t2.w, &win->t2.h);
	win->t2.data = mlx_get_data_addr(win->t2.t_img,
			&win->t2.bpp, &win->t2.sl, &win->t2.en);
	win->t3.t_img = mlx_xpm_file_to_image(win->mlx,
			"textures/irepeta.xpm", &win->t3.w, &win->t3.h);
	win->t3.data = mlx_get_data_addr(win->t3.t_img,
			&win->t3.bpp, &win->t3.sl, &win->t3.en);
	return (0);
}
