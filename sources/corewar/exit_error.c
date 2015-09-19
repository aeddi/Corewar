/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:41:37 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/19 14:48:53 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <corewar.h>

static void	print_usage(char *ex_path)
{
	ft_putstr("Usage: ");
	ft_putstr(ex_path);
	ft_putstr(" [-dump N -s N -v N | -g --stealth] [-a] ");
	ft_putendl("<[-n N] champion1.cor> <...>\n");
	ft_putendl("--- Text mode ---------------------------------------------\n");
	ft_putendl("   -dump N\tExit and dump VM memory after N cycles");
	ft_putendl("   -s N\t\tDump VM memory content every N cycles");
	ft_putendl("   -v N\t\tSet the verbosity level with N corresponding to:");
	ft_putendl("   \t\t  0  Show only essentials");
	ft_putendl("   \t\t  1  Show live signals");
	ft_putendl("   \t\t  2  Show cycles count");
	ft_putendl("   \t\t  3  Show operations (Params are NOT litteral ...)");
	ft_putendl("   \t\t  4  Show deaths");
	ft_putendl("   \t\t  5  Show colored memory");
	ft_putendl("   \t\t  6  Show process PC");
	ft_putendl("   \t\t  7  Show memory offset");
	ft_putendl("   \t\t  8  Show memory ascii representation\n");
	ft_putendl("--- Ncurses mode ------------------------------------------\n");
	ft_putendl("   -g\t\tEnable Ncurses mode");
	ft_putendl("   --stealth\tHide memory content\n");
	ft_putendl("--- Both modes --------------------------------------------\n");
	ft_putendl("   -a\t\tDisplay 'aff' instruction output (default: disabled)");
	ft_putendl("   -n N\t\tForce a number for the next champion\n");
}

void		exit_error(char *error, char *detail, char *ex_path)
{
	ft_putstr("\033[31m");
	if (detail)
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(detail, 2);
	}
	else
		perror(error);
	ft_putstr("\033[0m");
	if (ex_path)
	{
		ft_putchar('\n');
		print_usage(ex_path);
	}
	exit(errno);
}
