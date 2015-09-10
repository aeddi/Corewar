/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:02:50 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/09 23:32:25 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <corewar_struct.h>

# define UNSET			-1

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

/*
**	Process list functions
*/
void	new_process(t_process proc, t_plist *head);
void	delete_process(t_plist *elem);
void	free_list(t_plist *head);
int		count_list(t_plist *head, int player);

/*
**	Virtual machine functions
*/
void	launch_virtual_machine(t_param *params);
void	exec_virtual_machine(t_param *params, t_vm_data *data);

/*
**	Instruction cycle functions
*/
void	instruction_cycle(t_param *params, t_vm_data *data);
t_op	*get_op_detail(int op_code);
void	reset_instruction(t_fetched *instruction)	;
void	fetch_instruction(t_process *process, t_byte *memory);

/*
**	Text mode functions
*/
void	print_memory(t_byte *memory, int verb_lvl);
void	print_players_intro(t_param *params);
void	print_turn(t_param *params, t_vm_data *data);
void	print_death(int count, t_param *params);
void	print_winner(t_param *params, t_vm_data *data);

/*
**	Misc functions
*/
void	parse_files(t_param *params);
void	byte_to_hex(char byte, char hex[3]);
void	exit_error(char *error, char *detail, char *ex_path);

#endif /* !COREWAR_H */
