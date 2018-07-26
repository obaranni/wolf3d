/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:51:48 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/25 19:17:18 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

static void	ft_putgun(t_win *win)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(win->mlx,
								"textures/awp.xpm", &w, &h);
	mlx_put_image_to_window(win->mlx, win->win, img, 650, 650);
}

void		ft_display(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, W, H);
	ft_putray_obj(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	if (win->version == 1)
		ft_putman(win);
	if (win->g == 1)
		ft_putgun(win);
}

static void	close_window(void)
{
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(0);
}

int			main(void)
{
	t_win	win;

	if (!ft_readmap(&win))
	{
		ft_putendl("Map ERROR!\n");
		return (0);
	}
	ft_init_window(&win);
	ft_read_textures(&win);
	ft_init_game_params(&win);
	system("killall afplay 2&>/dev/null >/dev/null");
	system("afplay mus/circle.mp3&");
	ft_display(&win);
	mlx_hook(win.win, 2, 5, ft_keyhook, &win);
	mlx_hook(win.win, 17, (1L << 17), (void *)close_window, NULL);
	mlx_loop(win.mlx);
	return (0);
}
