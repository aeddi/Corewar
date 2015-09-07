/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:33:48 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/24 09:18:04 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

extern int	g_errno;

int			ft_stat(const char *path, struct stat *s)
{
	if (ft_file_access(path))
			return (stat(path, s));
	return (-1);
}
