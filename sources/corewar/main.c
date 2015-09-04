/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 10:52:24 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/04 12:53:07 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/* To delete */
#include <stdio.h>
/* To delete */

int main(int ac, char **av)
{
	t_param	params;

	params = parse_args(ac, av);

/********* To delete *********/
	unsigned int	count = 0;
	printf("Path of exec: %s\n", params.ex_path);
	printf("Verbosity lvl: %d\n", params.verb_lvl);
	printf("Exit after: %d\n", params.exit_dump);
	printf("Dump every: %d\n", params.loop_dump);
	printf("Graphic enable: %d\n", params.graphic);
	while (count < 4)
	{
		if (params.champs[count].name)
		{
			printf("Champ path: %s\n", params.champs[count].path);
			printf("Champ number: %d\n", params.champs[count].number);
		}
		count++;
	}
/********* To delete *********/

	return 0;
}
