/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 15:58:45 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/23 16:06:02 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch(t_list *b, void *content, int (*cmp)())
{
	t_list	*tmp;

	tmp = b;
	while (tmp && cmp(tmp->content, content))
		tmp = tmp->next;
	return (tmp);
}
