/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:02:50 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/04 15:37:50 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <shared.h>
# include <corewar_struct.h>

/*
**	Parse functions
*/
t_param	parse_args(int ac, char **av);
void	parse_champs(t_param *params, int ac, char **av);
void	parse_misc_functions(t_param *params, int ac, char **av);

#endif /* !COREWAR_H */