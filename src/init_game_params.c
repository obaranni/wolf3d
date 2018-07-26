/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:50:32 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/26 16:49:35 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

void		ft_init_game_params(t_win *win)
{
	win->posx = 1.5;
	win->posy = 1.5;
	win->dirx = 1;
	win->diry = 0;
	win->planex = 0;
	win->planey = 0.66;
	win->version = 0;
	win->movespeed = 0.1;
	win->rotspeed = 0.1;
	win->heightmod = 1;
	win->g = 0;
}
