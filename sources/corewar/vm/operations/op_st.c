/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:42:44 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:27:01 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_st(t_process *process, t_param *params, t_vm_data *data)
{
	int	indirect;
	int	count;

	indirect = 0;
	count = -1;
	if (process->instruction.type[1] == REG_CODE)
	{
		*(int *)&process->reg[process->instruction.value[1] - 1] =
		*(int *)&process->reg[process->instruction.value[0] - 1];
	}
	else if (process->instruction.type[1] == IND_CODE)
	{
		while (++count < MAX_PLAYERS)
		{
			if (*(int *)&process->reg[0] == params->champs[count].number)
				break;
		}
		indirect =
			calc_indirect(process->prog_count, process->instruction.value[1]);
		put_int_memory(data->memory, indirect,
		*(int *)&process->reg[process->instruction.value[0] - 1], count + 1);
	}
	(void)params;
}
