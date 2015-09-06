/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 10:52:24 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/06 12:01:14 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/* To delete */
#include <stdio.h>
/* To delete */

int main(int ac, char **av)
{
	t_param	params;

	parse_args(&params, ac, av);
	parse_files(&params);

/********* To delete *********/
	unsigned int	count = 0;

	printf("Path of exec: %s\n", params.ex_path);
	printf("Exit after: %d\n", params.exit_dump);
	printf("Dump every: %d\n", params.loop_dump);
	printf("Verbosity lvl: %d\n", params.verb_lvl);
	printf("Graphic enable: %d\n", params.graphic);
	printf("Hidden mem: %d\n", params.hidden_mem);
	printf("Display aff: %d\n", params.disp_aff);
	while (count < 4)
	{
		if (params.champs[count].path)
		{
			printf("\nChamp path: %s\n", params.champs[count].path);
			printf("Champ number: %d\n", params.champs[count].number);
		}
		count++;
	}
/********* To delete *********/

	return 0;
}
