/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 15:32:18 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/06 16:03:43 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_sorttab_rev(char **tab)
{
	char	*swap1;
	char	*swap2;
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				swap1 = tab[i];
				swap2 = tab[j];
				tab[i] = swap2;
				tab[j] = swap1;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
