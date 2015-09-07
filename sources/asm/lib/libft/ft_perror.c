/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:24:13 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/27 16:56:33 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern unsigned int		g_errno;

void	ft_perror(const char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(ft_strerror(g_errno), 2);
}
