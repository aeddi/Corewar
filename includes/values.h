/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 22:25:26 by plastic           #+#    #+#             */
/*   Updated: 2015/09/07 22:57:34 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUES_H
# define VALUES_H

# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define REG_NUMBER				16
# define REG_SIZE				4

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

# define TEXT_PRINT_WIDTH		32

# define VERB_LVL_LIVES			1
# define VERB_LVL_CYCLES		2
# define VERB_LVL_OPERATIONS	3
# define VERB_LVL_DEATH			4
# define VERB_LVL_COLOR			5
# define VERB_LVL_OFFSET		6
# define VERB_LVL_PC			7
# define VERB_LVL_ASCII			8

			# define IND_SIZE				2
			# define DIR_SIZE				REG_SIZE

			# define T_LAB					8
			# define MAX_ARGS_NUMBER		4

#endif /* !VALUES_H */
