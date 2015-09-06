/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 23:55:04 by plastic           #+#    #+#             */
/*   Updated: 2015/09/07 00:06:09 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	byte_to_hex(char byte, char hex[3])
{
	short			count;
	short			char_hex;
	char			swap;
	unsigned char	cast;

	cast = (unsigned char)byte;
	count = -1;
	while (++count != 2)
	{
		char_hex = cast % 16;
		cast /= 16;
		if (char_hex < 10)
			hex[count] = char_hex + '0';
		else
			hex[count] = (char_hex % 10) + 'a';
	}
	swap = hex[0];
	hex[0] = hex[1];
	hex[1] = swap;
	hex[3] = '\0';
}
