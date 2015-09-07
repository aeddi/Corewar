/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 12:49:34 by gponsine          #+#    #+#             */
/*   Updated: 2014/02/02 03:05:53 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

int		parse_instruction(t_parse *p)
{
	t_op		op;
	int			i;
	int			op_bytepos;

	op_bytepos = CHAMPION->len;
	op = parse_opcode(p);
	i = 0;
	while (i < op.arg_nbr)
	{
		LAST_TYPE = OPCODE_TYPE;
		read_lexem(p);
		if (TYPE == ARG_REG_TYPE && (op.arg_type[i] & T_REG))
			parse_arg_reg(p);
		else if (TYPE == ARG_DIR_TYPE && (op.arg_type[i] & T_DIR))
			parse_arg_dir(p, op_bytepos, op);
		else if (TYPE == ARG_IND_TYPE && (op.arg_type[i] & T_IND))
			parse_arg_ind(p, op_bytepos);
		else if (TYPE == NOTHING)
			error(INVALID_CHAR, p);
		else
			error(ARG, p);
		i++;
	}
	return (0);
}
