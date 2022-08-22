CC = cc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
NAME_LIBFT = libft.a
DIR_LIBFT = ./libft
INCLUDE_READLINE = -I readline/include
INCLUDE = -I include -I include/var_header -I $(DIR_LIBFT)
LIB_READLINE = -L readline/lib
RM = rm -f

SRCS_DIR := ./src

DIR_BUILT_IN	:=	$(SRCS_DIR)/built_in
DIR_ENV			:=	$(SRCS_DIR)/env
DIR_PARSER		:=	$(SRCS_DIR)/parser
DIR_TERMINAL	:=	$(SRCS_DIR)/terminal
DIR_TOKENIZER	:=	$(SRCS_DIR)/tokenizer
DIR_UTILS		:=	$(SRCS_DIR)/utils
DIR_MAIN		:=	$(SRCS_DIR)/main

SRC_BUILT_IN	:=	env.c pwd.c
SRC_BUILT_IN	:= $(addprefix $(DIR_BUILT_IN)/, $(SRC_BUILT_IN))

SRC_ENV			:= env_list_adt_1.c env_list_adt_2.c env_list_adt_3.c
SRC_ENV			:= $(addprefix $(DIR_ENV)/, $(SRC_ENV))

SRC_PARSER		:= parsing.c parse_make_cmd.c parse_make_token.c
SRC_PARSER		:= $(addprefix $(DIR_PARSER)/, $(SRC_PARSER))

SRC_TERMINAL	:= signal_action.c
SRC_TERMINAL	:= $(addprefix $(DIR_TERMINAL)/, $(SRC_TERMINAL))

SRC_TOKENIZER	:= token_list_adt_1.c
SRC_TOKENIZER	:= $(addprefix $(DIR_TOKENIZER)/, $(SRC_TOKENIZER))

SRC_UTILS		:= util_1.c
SRC_UTILS		:= $(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

SRC_MAIN		:= main.c init.c main_loop.c
SRC_MAIN		:= $(addprefix $(DIR_MAIN)/, $(SRC_MAIN))

SRCS			=	$(SRC_BUILT_IN) $(SRC_ENV) $(SRC_PARSER) $(SRC_TERMINAL) \
					$(SRC_TOKENIZER) $(SRC_UTILS) $(SRC_MAIN)

OBJS 			=	${SRCS:.c=.o}




all : ${NAME}

$(NAME) : $(NAME_LIBFT) ${OBJS}
	${CC} -o ${NAME} ${CFLAGS} ${OBJS} -lreadline -lft $(LIB_READLINE) -L $(DIR_LIBFT)

$(NAME_LIBFT)	:
	make -C $(DIR_LIBFT) all

# .c.o	:	$(SRCS)
# 	${CC} ${CFLAGS} -c $< $(INCLUDE) $(INCLUDE_READLINE)

%.o		:	%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(INCLUDE_READLINE)

clean :
	make -C $(DIR_LIBFT) clean
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
