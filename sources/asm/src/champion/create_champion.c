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

static int	put_magic_number(int fd)
{
	int		magic_nb;
	char	magic[4];

	ft_putstr("Magic : \t");
	ft_putnbr(COREWAR_EXEC_MAGIC);
	ft_putchar('\n');
	magic_nb = COREWAR_EXEC_MAGIC;
	magic[0] = magic_nb >> 24 & 0xff;
	magic[1] = magic_nb >> 16 & 0xff;
	magic[2] = magic_nb >> 8 & 0xff;
	magic[3] = magic_nb >> 0 & 0xff;
	write(fd, magic, 4);
	return (1);
}

static int	put_champion_name(t_champ *champion, int fd)
{
	char	*name;

	name = ft_strnew(PROG_NAME_LENGTH);
	ft_putstr("Name : \t\t");
	if (champion->name)
	{
		name = ft_strcpy(name, champion->name);
		ft_putstr(champion->name);
	}
	ft_putchar('\n');
	write(fd, name, PROG_NAME_LENGTH);
	free(name);
	return (1);
}

static int	put_champion_comment(t_champ *champion, int fd)
{
	char	*comment;

	comment = ft_strnew(COMMENT_LENGTH);
	ft_putstr("Comment : \t");
	if (champion->comment)
	{
		ft_putstr(champion->comment);
		comment = ft_strcpy(comment, champion->comment);
	}
	ft_putchar('\n');
	write(fd, comment, COMMENT_LENGTH);
	free(comment);
	return (1);
}

int			create_champion(t_champ *champion, char *name)
{
	int		fd;
	char	*filename;

	(void)champion;
	filename = ft_strrchr(name, 's');
	filename[0] = '\0';
	filename = ft_strjoin(name, "cor");
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR,
			S_IRWXU | S_IRGRP | S_IROTH);
	ft_putstr("\nAssembling : \t");
	ft_putendl(filename);
	put_magic_number(fd);
	put_champion_name(champion, fd);
	put_champion_comment(champion, fd);
	ft_putchar('\n');
	write(fd, champion->bytecode, champion->len);
	return (1);
}
