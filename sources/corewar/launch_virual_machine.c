/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_virual_machine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 18:12:13 by plastic           #+#    #+#             */
/*   Updated: 2015/09/06 19:58:27 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static int	calc_champs_offset(t_param *params)
{
	int	count;
	int	total;
	int	ret;

	count = 0;
	total = 0;
	while (count < params->champs_amount)
	{
		total += params->champs[count].header.prog_size;
		count++;
	}
	ret = (MEM_SIZE - total) / params->champs_amount;
	return (ret);
}

static void	load_champs(t_param *params, t_byte *memory)
{
	int				count;
	int				count2;
	unsigned int	count3;
	int				offset;

	count = 0;
	count2 = 0;
	offset = calc_champs_offset(params);
	ft_bzero(memory, MEM_SIZE * sizeof(t_byte));
	while (count < params->champs_amount)
	{
		count3 = 0;
		while (count3 < params->champs[count].header.prog_size)
		{
			memory[count2].color = params->champs[count].color;
			memory[count2].content = params->champs[count].code[count3];
			count2++;
			count3++;
		}
		count2 += offset;
		count++;
	}
}

void		launch_virtual_machine(t_param *params)
{
	t_byte	memory[MEM_SIZE];

	load_champs(params, memory);
	print_memory(memory);
}
