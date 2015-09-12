/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:42:44 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:06:08 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_add(t_process *process, t_param *params, t_vm_data *data)
{
	int	first;
	int	second;

	first = *(int *)&process->reg[process->instruction.value[0] - 1];
	second = *(int *)&process->reg[process->instruction.value[1] - 1];
	*(int *)&process->reg[process->instruction.value[2] - 1] = first + second;
	(void)params;
	(void)data;
}
