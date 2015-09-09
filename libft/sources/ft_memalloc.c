/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:09:21 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/23 16:13:01 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = (int *)malloc(sizeof(int) * (size + 1));
	if (ptr)
		while (i <= size && (ptr[i] = 0) == 0)
			++i;
	return ((void *)ptr);
}
