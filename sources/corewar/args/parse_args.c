/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 12:16:08 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/09 10:17:22 by plastic          ###   ########.fr       */
/* ************************************************************************** */

#include <corewar.h>
#include <stdlib.h>
#include <libft.h>

static void	set_default_params(t_param *params, char *ex_path)
{
	unsigned int	count;

	count = 0;
	params->ex_path = ex_path;
	params->exit_dump = UNSET;
	params->loop_dump = UNSET;
	params->verb_lvl = 0;
	params->graphic = FALSE;
	params->hidden_mem = FALSE;
	params->disp_aff = FALSE;
	while (count < 4)
	{
		params->champs[count].path = NULL;
		params->champs[count].number = 0;
		params->champs[count].code = NULL;
		params->champs[count].color = UNSET;
		count++;
	}
}

t_bool		is_number(char *value)
{
	unsigned int	count;
	t_bool			neg;

	count = 0;
	neg = FALSE;
	if (value[count] == '-')
	{
		neg = TRUE;
		count++;
		if (value[count] == '\0')
			return FALSE;
	}
	while (value[count])
	{
		if (value[count] < '0' || value[count] > '9')
			return FALSE;
		count++;
	}
	if ((count > 0 && !neg) || (count > 1 && neg))
		return TRUE;
	return FALSE;
}

int			get_options_value(char *flag, char *value, char *ex_path)
{
	int	ret;

	if (is_number(value) != TRUE)
		exit_error(flag, "need a numeric value as option", ex_path);
	ret = ft_atoi(value);
	if (ret < 0)
		exit_error(flag, "need a positive number as option", ex_path);
	return (ret);
}

void		parse_args(t_param *params, int ac, char **av)
{
	set_default_params(params, av[0]);
	parse_misc_options(params, ac, av);
	parse_graphic_options(params, ac, av);
	parse_champs_options(params, ac, av);
}
