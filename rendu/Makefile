NAME = bsq

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I include/

SRCSF = srcs/

SRCS = ${SRCSF}free.c ${SRCSF}main.c ${SRCSF}parsing_helper.c ${SRCSF}parsing_matrix.c ${SRCSF}parsing_read.c ${SRCSF}parsing_utils.c ${SRCSF}parsing_v2.c ${SRCSF}solver.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

.c.o	:
		${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	gcc ${CFLAGS} -o ${NAME} ${INCLUDES} ${OBJS}

clean 	:
		${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
