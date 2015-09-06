/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_graphic_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 15:08:50 by plastic           #+#    #+#             */
/*   Updated: 2015/09/05 20:32:34 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

void			parse_graphic_options(t_param *params, int ac, char **av)
{
	int	count;

	count = 0;
	while (count++ < ac)
	{
		if (av[count] && !ft_strcmp(av[count], "-g"))
		{
			params->graphic = TRUE;
			av[count] = NULL;
			if (av[count + 1] && !ft_strcmp(av[count + 1], "--stealth"))
			{
				av[count + 1] = NULL;
				params->hidden_mem = TRUE;
			}
		}
	}
}
