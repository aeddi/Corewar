/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/19 14:44:09 by gponsine         ###   ########.fr       */
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
