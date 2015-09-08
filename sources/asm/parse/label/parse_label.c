/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 13:01:24 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/29 14:08:03 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

int	parse_label(t_parse *p)
{
	t_list	*label;

	label = ft_lstnew(LEXEM, ft_strlen(LEXEM) - 1);
	label->content_size = CHAMPION->len;
	ft_lstadd(&LABEL, label);
	if (!chk_label(label->content))
		error(LABEL_NAMED, p);
	if (POS == 0)
		POS++;
	return (1);
}


