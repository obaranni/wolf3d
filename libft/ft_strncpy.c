/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:27:48 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/04 18:19:30 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i != len)
	{
		if (src[i] == '\0')
			flag = 1;
		else
			dst[i] = src[i];
		if (flag)
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
