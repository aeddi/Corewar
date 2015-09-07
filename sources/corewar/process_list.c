/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 15:32:28 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/07 15:58:23 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_struct.h>
#include <stdlib.h>

t_plist	*new_process(t_process proc, t_plist *head)
{
	t_plist	*new;

	new = (t_plist *)malloc(sizeof(t_plist));
	new->process = proc;
	return (new);
}
