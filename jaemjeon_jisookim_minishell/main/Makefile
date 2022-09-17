CC = cc
NAME = minishell
CFLAGS = -g #-Wall -Wextra -Werror
NAME_LIBFT = libft.a
DIR_LIBFT = ./libft
LIB_LIBFT = -L$(DIR_LIBFT)
DIR_READLINE = readline
LIB_READLINE = -L$(DIR_READLINE)
INCLUDE_READLINE = -I$(DIR_READLINE)
INCLUDE = -Iinclude -I$(DIR_LIBFT)
RM = rm -f

READLINE = $(DIR_READLINE)/libreadline.a \
		   $(DIR_READLINE)/libhistory.a

SRCS_DIR := ./src

DIR_ENV			:=	$(SRCS_DIR)/env
DIR_TOKENIZE	:=	$(SRCS_DIR)/tokenize
DIR_UTILS		:=	$(SRCS_DIR)/utils
DIR_MAIN		:=	$(SRCS_DIR)/main
DIR_EXPAND		:=	$(SRCS_DIR)/expand
DIR_PARSE		:=	$(SRCS_DIR)/parse
DIR_DEBUG		:=	$(SRCS_DIR)/debug
DIR_EXECUTE		:=	$(SRCS_DIR)/execute
DIR_BUILT_IN	:=	$(SRCS_DIR)/built_in

SRC_ENV			:= env_list_adt_1.c env_list_adt_2.c env_list_adt_3.c
SRC_ENV			:= $(addprefix $(DIR_ENV)/, $(SRC_ENV))

SRC_TOKENIZE	:= tokenize.c split_all_component.c token_list_adt_1.c \
					token_list_adt_2.c read_token_func.c read_token_util_1.c
SRC_TOKENIZE	:= $(addprefix $(DIR_TOKENIZE)/, $(SRC_TOKENIZE))

SRC_UTILS		:= ifs.c error_exit.c signal.c terminal.c
SRC_UTILS		:= $(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

SRC_MAIN		:= main.c init.c
SRC_MAIN		:= $(addprefix $(DIR_MAIN)/, $(SRC_MAIN))

SRC_EXPAND		:= expand.c expand_util_1.c
SRC_EXPAND		:= $(addprefix $(DIR_EXPAND)/, $(SRC_EXPAND))

SRC_PARSE		:= parse.c cmd_adt_1.c parse_util_1.c
SRC_PARSE		:= $(addprefix $(DIR_PARSE)/, $(SRC_PARSE))

SRC_DEBUG		:= print_lst_token.c print_lst_cmd.c
SRC_DEBUG		:= $(addprefix $(DIR_DEBUG)/, $(SRC_DEBUG))

SRC_EXECUTE		:= execute.c execute_utils_1.c
SRC_EXECUTE		:=	$(addprefix $(DIR_EXECUTE)/, $(SRC_EXECUTE))


SRC_BUILT_IN	:=	ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c \
					ft_unset.c built_in_utils.c
SRC_BUILT_IN	:=	$(addprefix $(DIR_BUILT_IN)/, $(SRC_BUILT_IN))

SRCS			=	$(SRC_ENV) $(SRC_TOKENIZE) $(SRC_UTILS) $(SRC_MAIN) \
					$(SRC_DEBUG) $(SRC_EXPAND) $(SRC_PARSE) $(SRC_EXECUTE) \
					$(SRC_BUILT_IN)

OBJS 			=	${SRCS:.c=.o}


all : ${NAME}

$(NAME) : $(NAME_LIBFT) ${OBJS} $(READLINE)
	${CC} -o ${NAME} ${CFLAGS} ${OBJS} $(LIB_READLINE) $(LIB_LIBFT) -lreadline -lft -lncurses

$(NAME_LIBFT)	:
	make -C $(DIR_LIBFT) all

$(READLINE)		:
	cd $(DIR_READLINE); ./configure
	make -C $(DIR_READLINE) all

%.o		:	%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(INCLUDE_READLINE)

clean :
	make -C $(DIR_READLINE) clean
	make -C $(DIR_LIBFT) fclean
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
