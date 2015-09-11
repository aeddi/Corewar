/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_virtual_machine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 18:12:13 by plastic           #+#    #+#             */
/*   Updated: 2015/09/10 20:05:12 by plastic          ###   ########.fr       */
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

static void	init_process_list(t_param *params, t_vm_data *data)
{
	unsigned int	offset;
	int				iter;
	t_process		current;

	iter = 0;
	offset = MEM_SIZE / params->champs_amount;
	data->head = (t_plist *)malloc(sizeof(t_plist));
	data->head->next = NULL;
	data->head->prev = NULL;
	data->last_champ_alive = params->champs[0].number;
	while (iter < params->champs_amount)
	{
		current.prog_count = iter * offset;
		data->memory[iter * offset].is_pc = TRUE;
		ft_bzero(current.reg, REG_NUMBER * REG_SIZE);
		*(int *)(&current.reg[0]) = params->champs[iter].number;
		current.cycle_rest = 0;
		reset_instruction(&current.instruction);
		current.carry = TRUE;
		current.alive = FALSE;
		new_process(current, data->head);
		data->nb_proc_champs[iter] = 1;
		iter++;
	}
}

static void	init_vm_data(t_vm_data *data)
{
	data->cycle_to_die = CYCLE_TO_DIE;
	data->cycle_count = 0;
	data->last_check = 0;
	data->check_count = 0;
	ft_bzero(data->memory, MEM_SIZE * sizeof(t_byte));
	ft_bzero(data->nb_live_champs, MAX_PLAYERS * sizeof(int));
	ft_bzero(data->nb_proc_champs, MAX_PLAYERS * sizeof(int));
}

void		launch_virtual_machine(t_param *params)
{
	t_vm_data	data;

	init_vm_data(&data);
	load_champs(params, data.memory);
	init_process_list(params, &data);
	/* if (params->graphic) */
	/* 	init_ncurses(params, &data); */
	/* else */
		print_players_intro(params);
	exec_virtual_machine(params, &data);
	/* if (params->graphic) */
	/* 	display_winner(params, data); */
	/* else */
		print_winner(params, &data);
	free_list(data.head);
}
