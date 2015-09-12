/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:42:45 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:29:17 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_zjmp(t_process *process, t_param *params, t_vm_data *data)
{
	if (process->carry)
	{
		process->instruction.pc_gap = 0;
		process->prog_count =
				get_adress(process->prog_count + process->instruction.value[0]);
	}
	(void)params;
	(void)data;
}
