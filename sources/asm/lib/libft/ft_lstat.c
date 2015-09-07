/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 05:33:48 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/24 09:08:48 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

extern int	g_errno;

int			ft_lstat(const char *path, struct stat *s)
{
	if (ft_file_access(path))
			return (lstat(path, s));
	return (-1);
}
