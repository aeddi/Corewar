/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_cycle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 12:01:32 by plastic           #+#    #+#             */
/*   Updated: 2015/09/09 23:37:27 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdlib.h>

t_op    g_op_tab[NBR_OP] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void		reset_instruction(t_fetched *instruction)
{
	instruction->opcode = UNSET;
	instruction->type_first = UNSET;
	instruction->val_first = UNSET;
	instruction->type_second = UNSET;
	instruction->val_second = UNSET;
	instruction->type_third = UNSET;
	instruction->val_third = UNSET;
	instruction->size = UNSET;
}

t_op		*get_op_detail(int op_code)
{
	int	count;

	count = 0;
	while (count < NBR_OP)
	{
		if (g_op_tab[count].op_code == op_code)
			return (&g_op_tab[count]);
		count++;
	}
	return (NULL);
}

void		instruction_cycle(t_param *params, t_vm_data *data)
{
	t_plist	*iter;

	iter = data->head->next;
	while (iter)
	{
		if (iter->process.cycle_rest)
			iter->process.cycle_rest--;
		if (!iter->process.cycle_rest)
		{
			if (iter->process.instruction.opcode != UNSET)
			{
				/* execute_instruction(iter->process, data->memory, params); */
				reset_instruction(&iter->process.instruction);
			}
			fetch_instruction(&iter->process, data->memory);
		//	decode_instruction(iter->process.instruction);
(void)params;
		}
		iter = iter->next;
	}
}
