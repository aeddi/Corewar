/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:03:14 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/25 17:50:59 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;

	elem = *alst;
	del(elem->content, elem->content_size);
	elem->content = NULL;
	elem->content_size = 0;
	free(elem);
	elem = NULL;
}
