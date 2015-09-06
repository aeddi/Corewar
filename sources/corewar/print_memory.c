/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 19:06:12 by plastic           #+#    #+#             */
/*   Updated: 2015/09/07 01:08:19 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static void	print_byte(char byte, int color, t_bool is_pc)
{
	char	*colors[] = {"", "31", "32", "33", "34"};
	char	hex[3];

	ft_putstr("\033[1;");
	ft_putstr(colors[color]);
	if (is_pc)
		ft_putstr(";47");
	ft_putchar('m');
	byte_to_hex(byte, hex);
	ft_putstr(hex);
	ft_putstr("\033[0m");
}

static void	print_line(t_byte *memory, int verb_lvl)
{
	int		count;
	t_byte	*cur;

	count = 0;
	while (count < TEXT_PRINT_WIDTH)
	{
		cur = &memory[count];
		if (verb_lvl >= VERB_LVL_PC)
			print_byte(cur->content, cur->color, cur->is_pc);
		else if (verb_lvl >= VERB_LVL_COLOR)
			print_byte(cur->content, cur->color, FALSE);
		else
			print_byte(cur->content, 0, FALSE);
		count++;
		if (count % 8 == 0 && count < TEXT_PRINT_WIDTH)
			ft_putstr("  ");
		else if (count < TEXT_PRINT_WIDTH)
			ft_putchar(' ');
	}
}

static void	print_ascii(t_byte *memory)
{
	int		count;
	t_byte	*cur;

	count = 0;
	ft_putstr("   ");
	while (count < TEXT_PRINT_WIDTH)
	{
		cur = &memory[count];
		if (ft_isprint(cur->content))
			ft_putchar(cur->content);
		else
			ft_putchar('.');
		count++;
		if (count % 8 == 0 && count < TEXT_PRINT_WIDTH)
			ft_putchar(' ');
	}
}

static void	print_offset_to_hex(short offset)
{
	char	*cast;

	cast = (char *)&offset;
	ft_putstr(" 0x");
	print_byte(cast[1], 0, FALSE);
	print_byte(cast[0], 0, FALSE);
	ft_putstr(":   ");
}

void		print_memory(t_byte *memory, int verb_lvl)
{
	int		count;

	count = 0;
	ft_putchar('\n');
	while (count < MEM_SIZE)
	{
		if (verb_lvl >= VERB_LVL_OFFSET)
			print_offset_to_hex(count);
		else
			ft_putchar('\t');
		print_line(&memory[count], verb_lvl);
		if (verb_lvl >= VERB_LVL_ASCII)
			print_ascii(&memory[count]);
		ft_putchar('\n');
		count += TEXT_PRINT_WIDTH;
	}
	ft_putchar('\n');
}