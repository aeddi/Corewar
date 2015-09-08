# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 16:00:35 by aeddi             #+#    #+#              #
#    Updated: 2015/09/08 23:27:47 by plastic          ###   ########.fr        #
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
					launch_virtual_machine.c		\
					exec_virtual_machine.c			\
					byte_to_hex.c					\
					process_list.c					\
					print_text.c					\
					print_memory.c

OBJS_CW_DIR		=	$(OBJS_DIR)/corewar
OBJS_CW			=	$(patsubst %.c, $(OBJS_CW_DIR)/%.o, $(SRCS_CW))

SRCS_AS_DIR		=	$(SRCS_DIR)/asm
SRCS_AS			=	# main.c									\
					# op.c									\
					# champion/add_bytecode.c					\
					# champion/create_champion.c				\
					# champion/del_champion.c					\
					# champion/new_champion.c					\
					# error/error_arg.c						\
					# error/error.c							\
					# parse/parse.c							\
					# parse/parse_cmd.c						\
					# parse/parse_next.c						\
					# parse/read_lexem.c						\
					# instruction/parse_arg_dir.c				\
					# instruction/parse_arg_ind.c				\
					# instruction/parse_arg_reg.c				\
					# instruction/parse_instruction.c			\
					# instruction/parse_opcode.c				\
					# instruction/parse_opcode_encodebyte.c	\
					# label/add_label.c						\
					# label/call_label.c						\
					# label/chk_label.c						\
					# label/parse_label.c

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
	@mkdir -p $(OBJS_AS_DIR)/champion
	@mkdir -p $(OBJS_AS_DIR)/error
	@mkdir -p $(OBJS_AS_DIR)/parse
	@mkdir -p $(OBJS_AS_DIR)/instruction
	@mkdir -p $(OBJS_AS_DIR)/label

make_libft		:
	$(MAKE) -C $(LIBFT_DIR)

fclean			:	clean
	rm -f $(NAME) $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
