/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 07:29:05 by gponsine          #+#    #+#             */
/*   Updated: 2013/12/27 15:38:51 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		ft_file_exist(const char *path)
{
	struct stat	s;

	if (lstat(path, &s) == 0)
		return (1);
	return (0);
}
