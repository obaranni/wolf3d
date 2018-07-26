/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:48:55 by obaranni          #+#    #+#             */
/*   Updated: 2017/10/20 20:49:53 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/wolf.h"

static void		ft_initarr(int *arr, char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < 48)
	{
		arr[i] = line[j] - 48;
		j += 2;
		i++;
	}
}

static int		ft_parsarr(t_win *win, char **tab)
{
	int			i;

	i = 0;
	win->map = (int**)malloc(sizeof(int*) * 16);
	while (i < 16)
	{
		win->map[i] =
			(int*)malloc(sizeof(int) * 24);
		ft_initarr(win->map[i], tab[i]);
		free(tab[i]);
		i++;
	}
	return (1);
}

int				ft_readmap(t_win *win)
{
	char		buf[4096];
	int			fd;
	char		**tab;
	int			ret;

	fd = open("map/map1", O_RDONLY);
	ret = read(fd, buf, 4095);
	buf[ret] = 0;
	tab = ft_strsplit(buf, 10);
	ft_parsarr(win, tab);
	free(tab);
	close(fd);
	return (1);
}
