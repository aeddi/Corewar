/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:43:40 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:33:59 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_fork(t_process *process, t_param *params, t_vm_data *data)
{
	t_process	fork;
	int			first;
	int			count;

	first = process->instruction.value[0];
	count = -1;
	fork = *process;
	fork.prog_count = calc_indirect(process->prog_count, first);
	fork.alive = FALSE;
	reset_instruction(&fork, TRUE);
	new_process(fork, data->head);
	while (++count < MAX_PLAYERS)
		if (*(int *)&process->reg[0] == params->champs[count].number)
			break ;
	data->nb_proc_champs[count]++;
}
