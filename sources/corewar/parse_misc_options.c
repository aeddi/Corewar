/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_misc_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 15:35:35 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/04 15:56:58 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static unsigned int	get_options_value(char *flag, char *value)
{

}

void				parse_misc_options(t_param *params, int ac, char **av)
{
	unsigned int	count;

	count = 0;
	while (count++ < (unsigned int)ac - 1)
	{
		if (!ft_strcmp(av[count], "-d"))
			param->exit_dump = get_options_value("-d", av[count + 1]);
		else if (!ft_strcmp(av[count], "-s"))
			param->exit_dump = get_options_value("-s", av[count + 1]);
		else if (!ft_strcmp(av[count], "-v"))
			param->exit_dump = get_options_value("-v", av[count + 1]);
	}
}
