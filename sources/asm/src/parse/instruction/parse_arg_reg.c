/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_reg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:46:20 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/29 12:47:33 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

int		parse_arg_reg(t_parse *p)
{
	int		n;

	if ((n = ft_atoi(&LEXEM[1])) && n < REG_NUMBER)
		add_bytecode(CHAMPION, n & 0xFF);
	else
		error(ARG, p);
	return (1);
}

