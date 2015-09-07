/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 09:56:52 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/03 11:43:19 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_btradd(t_btree **root, t_btree *elem, int (*sort)())
{
	t_btree	*tmp;
	t_btree	*node;

	if (root && *root)
	{
		tmp = *root;
		while ((node = tmp))
		{
			if (sort(elem, tmp) > 0)
			{
				if (!(tmp = tmp->right))
					node->right = elem;
			}
			else
			{
				if (!(tmp = tmp->left))
					node->left = elem;
			}
		}
	}
	else
		*root = elem;
}
