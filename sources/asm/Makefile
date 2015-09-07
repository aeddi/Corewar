# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:51:53 by gponsine          #+#    #+#              #
#    Updated: 2015/09/07 14:28:12 by gponsine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	asm

CC				=	gcc

CFLAG			=	-Wall -Wextra -Werror -g -O3

RM				=	rm -f

SRC				=	$(shell find src -type f | grep '\.c')

OBJ				=	$(SRC:.c=.o)

INC				=	-I inc						\
					-I lib/libft/

LIB				=	-L lib/libft/ -lft

# **************************************************************************** #

all				: $(NAME)

$(NAME)			: $(SRC:.c=.o)
					make -C lib/libft/
					$(CC) $(CFLAG) $(OBJ) $(INC) $(LIB) -o $(NAME)

%.o				: %.c
					$(CC) $(CFLAG) -o $@ -c $< $(INC)

fclean			: clean
					@$(RM) $(NAME)

clean			:
					@$(RM) $(OBJS)

re				: fclean all

# **************************************************************************** #
