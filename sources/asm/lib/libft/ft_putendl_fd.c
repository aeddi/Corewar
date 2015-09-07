/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:05:52 by gponsine          #+#    #+#             */
/*   Updated: 2013/11/24 22:43:57 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr && write(fd, ptr, 1) && ++ptr)
		;
	write(fd, "\n", 1);
}
