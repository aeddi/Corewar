/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 07:32:38 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/29 14:25:25 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERROR_H
# define ASM_ERROR_H

# include <libft.h>
# include "asm_parse.h"

typedef enum	e_error
{
	CMD,
	CMD_STRING_LENGTH,
	INVALID_CHAR,
	LABEL_NAMED,
	LABEL_EXIST,
	MNEMONIC,
	ARG,
}				t_error;

int		error(t_error e, void *p);
int		error_part_two(t_error e, void *p);
int		error_arg(int ac, char **av);

#endif
