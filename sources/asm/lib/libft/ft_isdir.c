/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 08:53:21 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/27 15:30:48 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

extern int	g_errno;

int		ft_isdir(const char *path)
{
	struct stat	s;

	g_errno = 0;
	if (path)
		if (stat(path, &s) == 0)
			if (S_ISDIR(s.st_mode))
				return (1);
			else
				g_errno = ENOTDIR;
		else
			g_errno = ENOENT;
	else
		g_errno = ENOENT;
	return (0);
}
