/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:02:50 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/07 11:58:02 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <corewar_struct.h>

# define FOREGROUND(x)	(x + 30)
# define BACKGROUND(x)	(x + 40)

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

void	launch_virtual_machine(t_param *params);

void	byte_to_hex(char byte, char hex[3]);

void	print_memory(t_byte *memory, int verb_lvl);

void	exit_error(char *error, char *detail, char *ex_path);

#endif /* !COREWAR_H */
