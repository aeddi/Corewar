/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 17:44:52 by plastic           #+#    #+#             */
/*   Updated: 2015/09/12 13:29:24 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void	op_aff(t_process *process, t_param *params, t_vm_data *data)
{
	if (params->disp_aff)
		ft_putchar(*(int *)&process->reg[process->instruction.value[0] - 1]);
	(void)data;
}
