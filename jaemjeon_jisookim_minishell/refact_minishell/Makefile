CC = cc
NAME = minishell
CFLAGS = -g -Wall -Wextra -Werror
NAME_LIBFT = libft.a
DIR_LIBFT = ./libft
INCLUDE_READLINE = -I readline/include
INCLUDE = -I include -I include/var_header -I $(DIR_LIBFT)
LIB_READLINE = -L readline/lib
RM = rm -f

SRCS_DIR := ./src

DIR_ENV			:=	$(SRCS_DIR)/env
DIR_TOKENIZE	:=	$(SRCS_DIR)/tokenize
DIR_UTILS		:=	$(SRCS_DIR)/utils
DIR_MAIN		:=	$(SRCS_DIR)/main
DIR_DEBUG		:=	$(SRCS_DIR)/debug

SRC_ENV			:= env.c env_list_adt_1.c env_list_adt_2.c env_list_adt_3.c
SRC_ENV			:= $(addprefix $(DIR_ENV)/, $(SRC_ENV))

SRC_TOKENIZE	:= token_list_adt_1.c token_list_adt_2.c
SRC_TOKENIZE	:= $(addprefix $(DIR_TOKENIZER)/, $(SRC_TOKENIZER))

SRC_UTILS		:= ifs.c error_exit.c
SRC_UTILS		:= $(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

SRC_MAIN		:= main.c init.c
SRC_MAIN		:= $(addprefix $(DIR_MAIN)/, $(SRC_MAIN))


SRCS			=	$(SRC_ENV) $(SRC_TOKENIZE) $(SRC_UTILS) $(SRC_MAIN)

OBJS 			=	${SRCS:.c=.o}


all : ${NAME}

$(NAME) : $(NAME_LIBFT) ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS} -lreadline -lft $(LIB_READLINE) -L $(DIR_LIBFT)

debug : $(NAME_LIBFT) ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS} -lreadline -lft $(LIB_READLINE) -L $(DIR_LIBFT)

$(NAME_LIBFT)	:
	make -C $(DIR_LIBFT) all

%.o		:	%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(INCLUDE_READLINE)

clean :
	make -C $(DIR_LIBFT) fclean
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
