/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 14:57:09 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/24 02:06:17 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = j = 0;
	while (s[j] && ++i)
		while (s[j++] == c);
	while (s[j] && s[j] != c)
		j++;
	tab = malloc(sizeof(char *) * (i + 1));
	i = j = k = 0;
	while (s[j])
	{
		i = 0;
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j + i] != c && s[j + i] != '\0')
			i++;
		tab[k++] = (s[j]) ? ft_strncpy(ft_strnew(i), &(s[j]), i) : 0;
		j = (s[j + i] != '\0') ? j + i + 1 : j + i;
	}
	tab[k] = 0;
	return (tab);
}
