/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 23:16:20 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/23 14:48:09 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *str, size_t len)
{
	char	*dup;

	dup = NULL;
	if ((dup = ft_strnew(len)))
	{
		if (ft_strlen(str) >= len)
			ft_strncpy(dup, str, len);
		else
			ft_strcpy(dup, str);
	}
	return (dup);
}
