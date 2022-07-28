NAME = push_swap

SRCS = push_swap.c ft_create_stack.c ft_sort_funct.c ft_sort_funct2.c ope-part1.c ope-part2.c other-struct-funct.c other-struct-funct2.c \
		printf/libft/ft_putchar_fd.c printf/ft_base16.c printf/ft_base16M.c printf/ft_base16UL.c\
		printf/ft_printf.c printf/ft_putnbru.c printf/ft_string.c printf/ft_char.c printf/ft_check_type.c printf/ft_putnbr_fd2.c \
		printf/ft_addr.c printf/libft/ft_isdigit.c printf/ft_nbrdec.c printf/ft_nbrnsigne.c \
		printf/libft/ft_putstr_fd.c printf/ft_nbrtohexa.c printf/ft_nbrtohexamaj.c \
		printf/libft/ft_atoi.c printf/libft/ft_split.c printf/libft/ft_strlen.c printf/libft/ft_strjoin.c

OBJS	= ${SRCS:.c=.o};

CFLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
						@gcc ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME};

clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:				fclean all

.PHONY:		all clean fclean re
