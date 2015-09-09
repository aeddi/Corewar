/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 23:08:13 by plastic           #+#    #+#             */
/*   Updated: 2015/09/09 09:18:46 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void	print_turn(t_param *params, t_vm_data *data)
{
	if (params->verb_lvl >= VERB_LVL_CYCLES)
	{
		ft_putstr("\n--- Cycle #");
		ft_putnbr(data->cycle_count);
		ft_putendl(" -----------------------------------------------------");
	}
	if (params->loop_dump > 0 && data->cycle_count
		&& !(data->cycle_count % params->loop_dump))
		print_memory(data->memory, params->verb_lvl);
}

void	print_death(int count, t_param *params)
{
	ft_putstr("Player ");
	ft_putnbr(params->champs[count].number);
	ft_putstr(" \033[1;");
	ft_putnbr(FOREGROUND(count + 1));
	ft_putchar('m');
	ft_putstr(params->champs[count].header.prog_name);
	ft_putstr("\033[0m");
	ft_putendl(" is dead");
}
