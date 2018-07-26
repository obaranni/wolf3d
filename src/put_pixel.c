/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:51:19 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/20 20:51:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

void			ft_pixel_put(t_win *win, int x, int y, int color)
{
	if (x >= W || x < 0 || y >= H || y < 0)
		return ;
	ft_memcpy(win->data + (x * 4 + y * win->size_line), &color, 4);
}
