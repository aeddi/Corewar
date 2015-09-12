/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:42:45 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:29:35 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_and(t_process *process, t_param *params, t_vm_data *data)
{
	int	first;
	int	second;

	first = 0;
	second = 0;
	if (process->instruction.type[0] == REG_CODE)
		first = *(int *)&process->reg[process->instruction.value[0] - 1];
	else if (process->instruction.type[0] == DIR_CODE)
		first = process->instruction.value[0];
	else if (process->instruction.type[0] == IND_CODE)
		first = get_int_memory(data->memory,
			calc_indirect(process->prog_count, process->instruction.value[0]));
	if (process->instruction.type[1] == REG_CODE)
		second = *(int *)&process->reg[process->instruction.value[1] - 1];
	else if (process->instruction.type[1] == DIR_CODE)
		second = process->instruction.value[1];
	else if (process->instruction.type[1] == IND_CODE)
		second = get_int_memory(data->memory,
			calc_indirect(process->prog_count, process->instruction.value[1]));
	*(int *)&process->reg[process->instruction.value[2] - 1] = first & second;
	(void)params;
}
