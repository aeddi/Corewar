/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:01:57 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 22:19:12 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	re;

	re = 0;
	i = -1;
	while (src[++i])
		;
	re = i;
	i = -1;
	while (dst[++i] && i < size)
		;
	re += (i < size) ? i : size;
	d = i;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	size -= i;
	return (re);
}
