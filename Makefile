NAME = bsq

SRC = srcs/*.c

HDR = include/

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	gcc ${CFLAGS} -o ${NAME} -I ${HDR} ${SRC}

fclean:
	rm -f ${NAME}

re: fclean all
