/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:42:44 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:36:03 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_live(t_process *process, t_param *params, t_vm_data *data)
{
	int			pid;
	int			index;
	int			count;

	pid = process->instruction.value[0];
	index = UNSET;
	count = -1;
	process->alive = TRUE;
	while (++count < MAX_PLAYERS)
		if (pid == params->champs[count].number)
			index = count;
	if (index != UNSET)
	{
		data->nb_live_champs[index]++;
		data->last_champ_alive = pid;
		if (!params->graphic && params->verb_lvl >= VERB_LVL_LIVES)
			print_live(*(int *)process->reg[0], pid);
		data->memory[process->prog_count].is_live = FALSE;
	}
}
