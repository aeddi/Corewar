/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:11:34 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 22:19:19 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{

	while (*s && *s != (char)c && ++s)
		;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);

}
