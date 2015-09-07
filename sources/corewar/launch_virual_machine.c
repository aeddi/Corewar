/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_virual_machine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 18:12:13 by plastic           #+#    #+#             */
/*   Updated: 2015/09/07 14:24:09 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static void	load_champs(t_param *params, t_byte *memory)
{
	unsigned int	mem_c;
	unsigned int	champ_c;
	unsigned int	offset;
	int				iter;

	iter = 0;
	offset = MEM_SIZE / params->champs_amount;
	ft_bzero(memory, MEM_SIZE * sizeof(t_byte));
	while (iter < params->champs_amount)
	{
		mem_c = iter * offset;
		champ_c = 0;
		while (champ_c < params->champs[iter].header.prog_size)
		{
			memory[mem_c + champ_c].color = params->champs[iter].color;
			memory[mem_c + champ_c].content = params->champs[iter].code[champ_c];
			champ_c++;
		}
		iter++;
	}
}

void		launch_virtual_machine(t_param *params)
{
	t_byte	memory[MEM_SIZE];

	load_champs(params, memory);
	print_memory(memory, params->verb_lvl);
}
