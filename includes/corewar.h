/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:02:50 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/06 14:04:24 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <corewar_struct.h>

/*
**	Parameters functions
*/
void	parse_args(t_param *params, int ac, char **av);
t_bool	is_number(char *value);
int		get_options_value(char *flag, char *value, char *ex_path);
void	parse_misc_options(t_param *params, int ac, char **av);
void	parse_graphic_options(t_param *params, int ac, char **av);
void	parse_champs_options(t_param *params, int ac, char **av);

void	parse_files(t_param *params);

void	exit_error(char *error, char *detail, char *ex_path);

#endif /* !COREWAR_H */
