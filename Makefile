PRINTF = printf/

SRCS = ft_push_swap.c

OBJS	= ${SRCS:.c=.o}

NAME = push_swap.a

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
						make -C ${PRINTF}
						cp printf/libftprint.a ${NAME}
						ar src ${NAME} ${OBJS}

all:		${NAME}

clean:
				make clean -C ${PRINTF}
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}
				make fclean -C ${PRINTF}

re:				fclean all

.PHONY:		all clean fclean re
