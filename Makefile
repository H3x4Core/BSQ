# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpouce <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 11:45:30 by mpouce            #+#    #+#              #
#    Updated: 2022/06/29 12:05:48 by mpouce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/guest_management.c \
	  srcs/parsing.c \
	  srcs/parsing_utils.c \
	  srcs/solver.c \
	  srcs/main.c \
	  srcs/parsing_helper.c \
	  srcs/read_file.c

OBJ = ${SRC:.c=.o}

HDR = include/

CFLAGS = -Wall -Wextra -Werror

.c.o :
	gcc ${CFLAGS} -I ${HDR} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	gcc ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
