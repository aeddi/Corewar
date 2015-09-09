/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:11:34 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 22:20:43 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	int			i;

	ptr = (unsigned char *)s;
	i = ft_strlen(s);
	while (i != -1)
	{
		if (ptr[i] == (unsigned char)c)
			return ((char *)&ptr[i]);
		i--;
	}
	return (NULL);
}
