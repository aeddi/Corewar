/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:28:22 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/29 15:25:04 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

# include <libft.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_champ
{
	char			*name;
	char			*comment;
	char			*bytecode;
	int				len;
}					t_champ;

t_champ		*new_champion(void);
int			del_champion(t_champ *champ);
int			add_bytecode(t_champ *champ, char byte);
int			create_champion(t_champ *champ, char *filename);

#endif /* !CHAMPION_H */
