/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:46:41 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 19:02:08 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i])
	{
		if (i >= j)
			return (s);
		swap = s[i];
		s[i] = s[j];
		s[j] = swap;
		i++;
		j--;
	}
	return (s);
}
