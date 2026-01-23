# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 17:23:47 by esttina           #+#    #+#              #
#    Updated: 2026/01/23 17:24:51 by esttina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

all: ${NAME}

SRCS = 

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

%.o: %.c push_swap.h
	${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf ${OBJECTS}

fclean:	clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re