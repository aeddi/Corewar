/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:01:57 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 22:19:05 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s1;
	i = ft_strlen(ptr);
	while (*s2 && n > 0)
	{
		ptr[i] = *s2;
		i++;
		s2++;
		n--;
	}
	ptr[i] = '\0';
	return (s1);
}
