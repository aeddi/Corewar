/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 12:07:31 by plastic           #+#    #+#             */
/*   Updated: 2015/09/11 10:20:39 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	decode_instruction(t_fetched *instruction, int prog_count)
{
	int	count;

	count = 0;
	while (count < MAX_PARAMS && instruction->type[count] != UNSET)
	{
		if (instruction->type[count] == IND_CODE)
		{
			prog_count += instruction->value[count];
			prog_count %= MEM_SIZE;
			instruction->value[count] = prog_count;
		}
		else if (instruction->type[count] == REG_CODE)
		{
			if (instruction->value[count] < 1
				|| instruction->value[count] > REG_NUMBER)
			{
				reset_instruction(instruction);
				return ;
			}
		}
		count++;
	}
}
