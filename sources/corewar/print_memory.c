/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 19:06:12 by plastic           #+#    #+#             */
/*   Updated: 2015/09/06 20:02:26 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <libft.h>

static void	print_byte_to_hex(char byte, int color)
{
	char			str[2];
	short			count;
	short			char_hex;
	unsigned char	cast;
	char			*colors[] = {"m", "31m", "32m", "33m", "34m"};

	cast = (unsigned char)byte;
	count = -1;
	while (++count != 2)
	{
		char_hex = cast % 16;
		cast /= 16;
		if (char_hex < 10)
			str[count] = char_hex + '0';
		else
			str[count] = (char_hex % 10) + 'a';
	}
	ft_putstr("\033[1;");
	ft_putstr(colors[color]);
	ft_putchar(str[1]);
	ft_putchar(str[0]);
	ft_putstr("\033[0m");
}

void		print_memory(t_byte *memory)
{
	int	count;
	int	count2;

	count = 0;
	while (count < MEM_SIZE)
	{
		count2 = 0;
		ft_putchar('\t');
		while (count2 < TEXT_PRINT_WIDTH)
		{
			print_byte_to_hex(memory[count].content, memory[count].color);
			count++;
			count2++;
			if (count2 % 8 == 0 && count2 < TEXT_PRINT_WIDTH)
				ft_putstr("   ");
			else if (count2 < TEXT_PRINT_WIDTH)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
