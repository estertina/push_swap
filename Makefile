# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 17:23:47 by esttina           #+#    #+#              #
#    Updated: 2026/07/14 13:45:36 by esttina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

all: ${NAME}

SRCS = 	srcs/index.c \
		srcs/list_utils.c \
		srcs/utils.c \
		srcs/push.c \
		srcs/radix.c \
		srcs/rev_rotate.c \
		srcs/rotate.c \
		srcs/small_sort.c \
		srcs/swap.c \
		srcs/main.c


OBJECTS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror -I includes -I $(LIBFT_DIR)

CC = cc

%.o: %.c includes/push_swap.h
	${CC} ${FLAGS} -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	${CC} ${FLAGS} $(OBJECTS) $(LIBFT) -o $(NAME)

clean:
	rm -rf ${OBJECTS}
	@make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -rf ${NAME}
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re