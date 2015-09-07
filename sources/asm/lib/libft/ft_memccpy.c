/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:57:20 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 22:17:57 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	if (!s1 || !s2)
		return (s1);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (i < n && n > 0 && *t2)
	{
		if (t1 + i != t2 && t2 + i != t1)
			t1[i] = t2[i];
		else
			return (s1);
		i++;
		if (t2[i - 1] == (unsigned char)c)
			return ((void *)&(t1[i]));
	}
	return (NULL);
}
