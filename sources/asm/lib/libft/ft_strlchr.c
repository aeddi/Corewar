/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 23:24:24 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/08 00:21:05 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t		ft_strlchr(char *str, char c)
{
	size_t	n;

	n = 0;
	while (str[n] && str[n] != c)
		n++;
	if (str[n] == c)
		return (n);
	return (0);
}
