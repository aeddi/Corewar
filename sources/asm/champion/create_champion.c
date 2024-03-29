/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 15:09:08 by gponsine          #+#    #+#             */
/*   Updated: 2014/02/02 03:18:30 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"
#include "op.h"

int		create_champion(t_champ *champion, char *name)
{
	int			fd;
	char		*filename;
	t_header	header;

	filename = ft_strrchr(name, 's');
	filename[0] = '\0';
	filename = ft_strjoin(name, "cor");
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR,
			S_IRWXU | S_IRGRP | S_IROTH);
	ft_putstr("\nAssembling : \t");
	ft_putendl(filename);
	ft_bzero(&header, sizeof(t_header));
	header.magic = ft_revint32(COREWAR_EXEC_MAGIC);
	ft_strcpy(header.prog_name, champion->name);
	header.prog_size = ft_revint32(champion->len);
	ft_strcpy(header.comment, champion->comment);
	write(fd, &header, sizeof(t_header));
	ft_putchar('\n');
	write(fd, champion->bytecode, champion->len);
	return (1);
}
