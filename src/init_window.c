/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:52:42 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/20 20:52:59 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

void		ft_init_window(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, W, H, "Wolf3D");
	win->img = mlx_new_image(win->mlx, W, H);
	win->data = mlx_get_data_addr(win->img, &(win->bpp),
			&(win->size_line), &(win->endian));
}
