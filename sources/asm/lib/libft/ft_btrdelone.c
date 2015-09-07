/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btrdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 09:47:49 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/03 09:56:31 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btrdelone(t_btree **node)
{
	t_btree *del;

	if (node && *node)
	{
		del = *node;
		del->content_size = 0;
		if (del->content)
			free(del->content);
		node = NULL;
		free(del);
	}
}
