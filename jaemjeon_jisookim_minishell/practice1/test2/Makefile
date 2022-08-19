CC = gcc
NAME = minishell
CFLAGS = -g -L /opt/homebrew/Cellar/readline/8.1.2/lib \
		-I /opt/homebrew/Cellar/readline/8.1.2/include
# -L ~/.brew/Cellar/readline/8.1.2/lib
# -I ~/.brew/Cellar/readline/8.1.2/include
DIR_LIBFT = ./libft
NAME_LIBFT = ${DIR_LIBFT}/libft.a

SRCS = main.c				\
	   init.c				\
	   main_loop.c			\
	   env.c				\
	   pwd.c				\
	   signal_action.c		\
	   env_list_adt_1.c		\
	   env_list_adt_2.c		\
	   env_list_adt_3.c		\
	   util_1.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS} ${NAME_LIBFT}
	${CC} -lreadline ${CFLAGS} -o ${NAME} ${OBJS} ${NAME_LIBFT}

${NAME_LIBFT} :
	make -C ${DIR_LIBFT} all

.c.o : ${SRCS}
	${CC} ${CFLAGS} -c $^

clean :
	rm -f ${OBJS}
	make -C ${DIR_LIBFT} fclean

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
