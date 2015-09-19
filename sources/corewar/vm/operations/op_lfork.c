/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/19 14:44:26 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_lfork(t_process *process, t_param *params, t_vm_data *data)
{
	t_process	fork;
	int			first;
	int			count;

	count = -1;
	first = process->instruction.value[0];
	fork = *process;
	fork.prog_count = get_adress(process->prog_count + first);
	fork.alive = FALSE;
	reset_instruction(&fork, TRUE);
	new_process(fork, data->head);
	while (++count < MAX_PLAYERS)
		if (*(int *)&process->reg[0] == params->champs[count].number)
			break ;
	data->nb_proc_champs[count]++;
}
