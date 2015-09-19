/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/19 14:44:00 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	execute_instruction(t_process *proc, t_param *params, t_vm_data *data)
{
	void	(*operations[NBR_OP])(t_process *pr, t_param *pa, t_vm_data *d) =
	{
		op_live, op_ld, op_st, op_add, op_sub, op_and, op_or, op_xor,
		op_zjmp, op_ldi, op_sti, op_fork, op_lld, op_lldi, op_lfork, op_aff
	};

	(*operations[proc->instruction.op_code -1])(proc, params, data);
	if (!params->graphic && params->verb_lvl >= VERB_LVL_OPERATIONS)
		print_operation(proc);
}
