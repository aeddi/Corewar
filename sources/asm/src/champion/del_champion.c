/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_champion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:33:11 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/24 00:34:22 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champion.h"

int		del_champion(t_champ *champ)
{
	if (champ->name)
		free(champ->name);
	if (champ->comment)
		free(champ->comment);
	if (champ->bytecode)
		free(champ->bytecode);
	free(champ);
	return (1);
}
