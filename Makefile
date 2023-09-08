NAME = push_swap

SRCS = 	push_swap.c ft_create_stack.c ft_sort_funct.c ft_sort_funct2.c \
		other-struct-funct.c other-struct-funct2.c \
		operations/ft_push_a.c \
		operations/ft_push_b.c \
		operations/ft_swap_a.c \
		operations/ft_swap_b.c \
		operations/ft_reverse_rotate_a.c \
		operations/ft_reverse_rotate_b.c \
		operations/ft_rotate_a.c \
		operations/ft_rotate_b.c \
		operations/ft_swap_ab.c \
		operations/ft_max_int.c \
		operations/ft_is_full.c \
		operations/ft_is_empty.c \
		operations/ft_two_spots.c \
		operations/ft_min_int.c \

# > MESSAGES COLORS <<<<<<

MSG_BCOLOR_FAILURE		:=	\001\e[1;31m\002
MSG_BCOLOR_PRIMARY		:=	\001\e[1;36m\002
MSG_BCOLOR_SUCCESS		:=	\001\e[1;32m\002
MSG_BCOLOR_WARNING		:=	\001\e[1;33m\002
MSG_NCOLOR_FAILURE		:=	\001\e[0;31m\002
MSG_NCOLOR_PRIMARY		:=	\001\e[0;36m\002
MSG_NCOLOR_SUCCESS		:=	\001\e[0;32m\002
MSG_NCOLOR_WARNING		:=	\001\e[0;33m\002

# > TERMINAL <<<<<<<<<<<<<

TERM_CONTROL_CLEAR		:=	\001\e[1;1H\e[2J\002
TERM_CONTROL_RESET		:=	\001\e[0m\002

CC = gcc

CFLAGS = -Wall -Werror -Wextra

# > COMPILING C FILES <<<<
OBJS = ${SRCS:.c=.o};

LIBFOLDER_PRINTF = printf
LIBFOLDER_LIBFT = libft

INCLUDE = -I./${LIBFOLDER_PRINTF}
INCLUDE_LIBFT = -I./${LIBFOLDER_LIBFT}

LIBRARY1 = -L./${LIBFOLDER_PRINTF} -lftprintf
LIBRARY2 = -L./${LIBFOLDER_LIBFT} -lft

%.o:	%.c
	@printf "$(MSG_BCOLOR_PRIMARY) COMPILING C FILES : "
	@printf "$(TERM_CONTROL_RESET)"
	${CC} ${CFLAGS} -DONE=1 $(INCLUDE) $(INCLUDE_LIBFT) -c $< -o $@

${NAME}:	${OBJS}
	@printf "\n\n"
	@printf "$(MSG_BCOLOR_SUCCESS) MAKING AND LINKING LIBRARIES WITH MANDATORY: "
	@printf "$(TERM_CONTROL_RESET)"
	make -s -C ${LIBFOLDER_PRINTF}
	${CC} ${CFLAGS} $^ ${LIBRARY1} ${LIBRARY2} -o $@
	@printf "\n"

all:		${NAME};

clean_libft:
				@printf "$(MSG_BCOLOR_WARNING) CLEANING LIBFT FILES : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} libft/*.o libft/libft.a

clean_printf:
				@printf "$(MSG_BCOLOR_WARNING) CLEANING PRINTF FILES : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} printf/*.o printf/libftprintf.a

clean_libs:	clean_libft clean_printf

clean:
				@printf "$(MSG_BCOLOR_WARNING) CLEANING OBJECT FILES : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} ${OBJS}
				@printf "\n"

fclean:		clean clean_libs
				@printf "$(MSG_BCOLOR_WARNING) CLEANING EXECUTABLE : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} ${NAME}
				@printf "\n"

re:				fclean all

.PHONY:		all clean fclean re
