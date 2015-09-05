/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 11:03:07 by aeddi             #+#    #+#             */
/*   Updated: 2015/09/05 20:18:20 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
# define COREWAR_STRUCT_H

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef struct		s_champ
{
	char			*path;
	char			*name;
	int				number;
}					t_champ;

typedef struct		s_param
{
	char			*ex_path;
	int				exit_dump;
	int				loop_dump;
	int				verb_lvl;
	t_bool			graphic;
	t_bool			hidden_mem;
	t_bool			disp_aff;
	t_champ			champs[4];
}					t_param;

#endif /* !COREWAR_STRUCT_H */
