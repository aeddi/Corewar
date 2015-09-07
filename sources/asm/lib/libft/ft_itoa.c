/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:10:37 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/08 01:59:17 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(long long n)
{
	long long	n2;
	long long	i;
	int			neg;
	char	*s;

	if (n == 0 && (s = ft_strnew(1)) && (s[0] = '0'))
		return (s);
	neg = 0;
	n2 = n;
	i = 0;
	while (n2 != 0 && ++i)
		n2 = n2 / 10;
	s = ft_strnew(i + 1);
	i = 0;
	n *= 10;
	if (n < 0 && (n *= -1))
		neg = 1;
	while (n && (n /= 10))
		s[i++] = n % 10 + 48;
	if (neg)
		s[i] = '-';
	ft_strrev(s);
	return (s);
}
