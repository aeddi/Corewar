/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/25 11:05:38 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/08 01:57:31 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str)
{
	long long	i;
	long long	n;
	long long	r;

	i = n = r = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	while ((*str == '-' || *str == '+') && ++i && ++str)
		if (*(str - 1) == '-')
			n++;
	while (*str >= '0' && *str <= '9' && i <= 1)
	{
		r *= 10;
		r += *str - 48;
		str++;
	}
	if (n)
		r *= -1;
	return (r);
}
