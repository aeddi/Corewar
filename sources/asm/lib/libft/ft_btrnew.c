/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 09:35:49 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/03 11:05:53 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btrnew(void const *content, size_t c_size)
{
	t_btree	*new;

	if ((new = (t_btree *)ft_memalloc(sizeof(t_btree))))
	{
		if ((new->content = (void *)ft_memalloc(c_size)))
			if (new && new->content)
			{
				if (content)
				{
					new->content = ft_memcpy(new->content, content, c_size);
					new->content_size = c_size;
				}
				else
				{
					new->content = NULL;
					new->content_size = 0;
				}
				new->left = NULL;
				new->right = NULL;
				return (new);
			}
		free(new);
	}
	return (NULL);
}
