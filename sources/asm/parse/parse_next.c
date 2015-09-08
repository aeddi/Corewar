/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:44:44 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/24 02:12:26 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

int		parse_next(t_parse *p)
{
	while (LINE(POS) && LINE(POS) != ' ' && LINE(POS) != '\t')
		POS++;
	while (LINE(POS) && (LINE(POS) == ' ' || LINE(POS) == '\t'))
		POS++;
	if (LINE(POS))
		return (1);
	return (0);
}
