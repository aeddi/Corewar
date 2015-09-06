# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 16:00:35 by aeddi             #+#    #+#              #
#    Updated: 2015/09/06 19:53:26 by plastic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	corewar
NAME2			=	asm

CC				=	clang
GDB				?=	0
ifeq ($(GDB), 1)
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -g3 -I $(LIBFT_INCS_DIR) -I $(INCS_DIR)
else
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -O3 -I $(LIBFT_INCS_DIR) -I $(INCS_DIR)
endif
LFLAGS			=	-L $(LIBFT_DIR) -lft

INCS_DIR		=	./includes
LIBFT_DIR		=	./libft
LIBFT_INCS_DIR	=	$(LIBFT_DIR)/includes

SRCS_DIR		=	./sources
OBJS_DIR		=	./objects

SRCS_CW_DIR		=	$(SRCS_DIR)/corewar
SRCS_CW			=	main.c							\
					exit_error.c					\
					args/parse_args.c				\
					args/parse_champs_options.c		\
					args/parse_graphic_options.c	\
					args/parse_misc_options.c		\
					parse_files.c					\
					launch_virual_machine.c			\
					print_memory.c

OBJS_CW_DIR		=	$(OBJS_DIR)/corewar
OBJS_CW			=	$(patsubst %.c, $(OBJS_CW_DIR)/%.o, $(SRCS_CW))

SRCS_AS_DIR		=	$(SRCS_DIR)/asm
SRCS_AS			=	main.c

OBJS_AS_DIR		=	$(OBJS_DIR)/asm
OBJS_AS			=	$(patsubst %.c, $(OBJS_AS_DIR)/%.o, $(SRCS_AS))


all				:	$(NAME) $(NAME2)

$(NAME)			:	$(OBJS_DIR) $(OBJS_CW)
	$(CC) -o $(NAME) $(OBJS_CW) $(LFLAGS)

$(NAME2)		:	$(OBJS_DIR) $(OBJS_AS)
	$(CC) -o $(NAME2) $(OBJS_AS) $(LFLAGS)

$(OBJS_CW_DIR)/%.o	:	$(addprefix $(SRCS_CW_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_AS_DIR)/%.o	:	$(addprefix $(SRCS_AS_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_DIR)		:	make_libft
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_CW_DIR)
	@mkdir -p $(OBJS_CW_DIR)/args
	@mkdir -p $(OBJS_AS_DIR)

make_libft		:
	$(MAKE) -C $(LIBFT_DIR)

fclean			:	clean
	rm -f $(NAME) $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
