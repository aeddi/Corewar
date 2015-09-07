/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:20:25 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/27 15:34:55 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

extern int g_errno;

int		ft_isfile(char *path)
{
	struct stat	s;

	g_errno = 0;
	if (path)
		if (stat(path, &s) == 0)
			if (S_ISREG(s.st_mode))
				return (1);
	g_errno = ENOENT;
	return (0);
}
