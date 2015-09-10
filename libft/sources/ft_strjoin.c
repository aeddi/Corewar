/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:31:35 by gponsine          #+#    #+#             */
/*   Updated: 2015/01/25 18:32:17 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;

	join = NULL;
	if (s1 && s2)
	{
		join = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		ft_strcpy(join, s1);
		ft_strcpy(&join[ft_strlen(s1)], s2);
	}
	else if (s1)
	{
		join = ft_strdup(s1);
	}
	else if (s2)
	{
		join = ft_strdup(s2);
	}
	return (join);
}
