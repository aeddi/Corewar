/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 12:59:00 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/28 12:28:05 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static int save_lexem(t_parse *p)
{
	char	*t;
	char	c[2];
	int		i;

	if (LEXEM)
		free(LEXEM);
	LEXEM = ft_strnew(0);
	i = c[1] = 0;
	while (LINE(POS)
			&& LINE(POS) != ' ' && LINE(POS) != '\t' && LINE(POS) != ',')
	{
		c[0] = LINE(POS);
		t = LEXEM;
		LEXEM = ft_strjoin(LEXEM, c);
		free(t);
		POS++;
		i++;
	}
	POS -= i;
	return (i--);
}

int			read_lexem(t_parse *p)
{
	int		i;

	if (POS != 0 || LINE(POS) == ' ' || LINE(POS) == '\t')
		if (!parse_next(p) && !(TYPE = NOTHING))
			return (0);
	i = save_lexem(p);
	if (LAST_LINE == LINE_NBR && LAST_TYPE == LABEL_TYPE)
		TYPE = OPCODE_TYPE;
	else if (LINE(POS) == '.')
		TYPE = CMD_TYPE;
	else if (ft_strlen(LEXEM) > 1 && *(&LINE(POS) + i - 1) == LABEL_CHAR)
		TYPE = LABEL_TYPE;
	else if (LAST_TYPE == OPCODE_TYPE && LINE(POS) == 'r')
		TYPE = ARG_REG_TYPE;
	else if (LAST_TYPE == OPCODE_TYPE && LINE(POS) == DIRECT_CHAR)
		TYPE = ARG_DIR_TYPE;
	else if (LAST_TYPE == OPCODE_TYPE
			&& (ft_isdigit(LINE(POS)) || LINE(POS) == LABEL_CHAR))
		TYPE = ARG_IND_TYPE;
	else if (ft_isalpha(LINE(POS)))
		TYPE = OPCODE_TYPE;
	else if (!LINE(POS) || LINE(POS) == COMMENT_CHAR)
		TYPE = NOTHING;
	else
		error(INVALID_CHAR, p);
	LAST_LINE = LINE_NBR;
	LAST_TYPE = TYPE;
	return (1);
}
