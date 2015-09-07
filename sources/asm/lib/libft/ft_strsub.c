/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:13:20 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/25 12:31:30 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	sub = ft_strnew(len);
	i = start;
	j = 0;
	if (sub)
	{
		while (s[i] && j < len)
			sub[j++] = s[i++];
		return (sub);
	}
	return (NULL);
}
