/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 08:22:49 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/24 09:07:33 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int		g_errno;
extern char		**environ;

int		ft_file_access(const char *path)
{
	if (access(path, F_OK) != 1)
		if (access(path, R_OK) != -1
				&& access(path, W_OK) != -1
					&& access(path, X_OK) != -1
						&& !(g_errno = 0))
			return (1);
		else
			g_errno = EACCES;
	else
		g_errno = ENOENT;
	return (0);
}
