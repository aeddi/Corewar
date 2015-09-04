/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 12:16:08 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/04 15:55:56 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <stdlib.h>

static t_param	set_default_params(char *ex_path)
{
	t_param			params;
	unsigned int	count;

	count = 0;
	params.ex_path = ex_path;
	params.exit_dump = -1;
	params.loop_dump = 0;
	params.verb_lvl = 0;
	params.graphic = FALSE;
	while (count < 4)
	{
		params.champs[count].path = NULL;
		params.champs[count].name = NULL;
		params.champs[count].number = 0;
		count++;
	}
	return params;
}

static void		check_params(t_param *params, int ac, char **av)
{
	(void)params;
	(void)ac;
	(void)av;
}

t_param			parse_args(int ac, char **av)
{
	t_param	params;

	params = set_default_params(av[0]);
	parse_champs(&params, ac, av);
	parse_misc_options(&params, ac, av);
	check_params(&params, ac, av);
	return params;
}
