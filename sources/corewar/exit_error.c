/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:41:58 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/06 15:40:10 by plastic          ###   ########.fr       */
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
	ft_putstr(" [-a] [-g [--stealth]] [-v v_lvl] [-s n_cycles] ");
	ft_putendl("[-dump n_cycles] [[-n num] champion1.cor] ...\n");
	ft_putendl("-a\t\tDisplay aff on stdout (default: disabled)");
	ft_putendl("-g\t\tEnable graphic mode. Set with --stealth to hide memory");
	ft_putendl("-v NUM\t\tSet the verbosity level to NUM for text mode");
	ft_putendl("-s NUM\t\tDump VM memory content every NUM cycles");
	ft_putendl("-dump NUM\tExit and dump memory after NUM cycles");
}

void		exit_error(char *error, char *detail, char *ex_path)
{
	if (detail)
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(detail, 2);
	}
	else
		perror(error);
	if (ex_path)
		print_usage(ex_path);
	exit(errno);
}
