/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:31:35 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 14:28:24 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_strnew(len);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	return (join);
}
