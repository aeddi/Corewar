/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 12:06:54 by plastic           #+#    #+#             */
/*   Updated: 2015/09/09 23:36:01 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

#include <libft.h>

void	fetch_instruction(t_process *process, t_byte *memory)
{
	t_op	*op_detail;

	op_detail = get_op_detail((int)memory[process->prog_count].content);
	ft_putstr(op_detail->mnemonic);
	ft_putstr(" ");
	ft_putendl(op_detail->description);
}
