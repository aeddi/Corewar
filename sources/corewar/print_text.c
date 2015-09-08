/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 23:08:13 by plastic           #+#    #+#             */
/*   Updated: 2015/09/08 23:05:51 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void	print_players_intro(t_param *params)
{
	int	count;

	count = 0;
	while (count < params->champs_amount)
	{
		ft_putstr("Player ");
		ft_putnbr(params->champs[count].number);
		ft_putstr(" \033[1;");
		ft_putnbr(FOREGROUND(count + 1));
		ft_putchar('m');
		ft_putstr(params->champs[count].header.prog_name);
		ft_putstr("\033[0m");
		ft_putstr(" with a weight of ");
		ft_putnbr(params->champs[count].header.prog_size);
		ft_putstr(" bytes, says: ");
		ft_putstr(" \033[1m");
		ft_putendl(params->champs[count].header.comment);
		ft_putstr("\033[0m");
		count++;
	}
}

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

void	print_winner(t_param *params, t_vm_data *data)
{
	int	count;

	if (data->last_champ_alive != UNSET)
	{
		count = 0;
		while (count < params->champs_amount)
		{
			if (data->last_champ_alive == params->champs[count].number)
			{
				ft_putstr("\nle joueur ");
				ft_putnbr(params->champs[count].number);
				ft_putchar('(');
				ft_putstr(params->champs[count].header.prog_name);
				ft_putchar(')');
				ft_putendl(" a gagne");
				return ;
			}
			count++;
		}
	}
}
