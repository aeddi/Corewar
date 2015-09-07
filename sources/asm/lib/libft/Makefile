# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:51:53 by gponsine          #+#    #+#              #
#    Updated: 2014/01/22 05:48:39 by gponsine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -O3

AR				=	ar rc

RM				=	rm -f

SRCS			=	$(shell find . -type f | grep 'ft_' | grep '\.c')

OBJS			=	$(shell find . -type f | grep 'ft_' | grep '\.o')

# *************************************************************************** #

all				: $(NAME)

$(NAME)			: $(SRCS:.c=.o)
					$(AR) $(LIBFLAGS) $(NAME) $(OBJS)

config			:
					@echo -I`pwd` -L`pwd` -lft

%.o				: %.c
					$(CC) $(CFLAGS) -c $<

fclean			: clean
					$(RM) $(NAME)

clean			:
					$(RM) $(OBJS)

re				: fclean all


# *************************************************************************** #
