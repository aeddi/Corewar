/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 15:15:53 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/23 15:27:45 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **begin, t_list *new)
{
	t_list	*tmp;

	tmp = *begin;
	while (begin && tmp && tmp->next)
		tmp = tmp->next;
	if (begin && tmp)
		tmp->next = new;
	else
		*begin = new;
}
