CC = cc
NAME = minishell
CFLAGS = -g -Wall -Wextra -Werror# -fsanitize=address -g3
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
DIR_HEREDOC		:=	$(SRCS_DIR)/heredoc

SRC_ENV			:= 	env_list_adt_1.c env_list_adt_2.c env_list_adt_3.c \
					env_list_adt_4.c
SRC_ENV			:=	$(addprefix $(DIR_ENV)/, $(SRC_ENV))

SRC_TOKENIZE	:=	token_free.c token_lst_adt_1.c token_lst_adt_2.c \
					token_read_func.c token_read.c token_split.c tokenize.c
SRC_TOKENIZE	:=	$(addprefix $(DIR_TOKENIZE)/, $(SRC_TOKENIZE))

SRC_UTILS		:=	ifs.c error_exit.c signal.c terminal.c setting.c \
					free.c error_message.c
SRC_UTILS		:=	$(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

SRC_MAIN		:= main.c init.c check_error.c check_syntax.c
SRC_MAIN		:= $(addprefix $(DIR_MAIN)/, $(SRC_MAIN))

SRC_EXPAND		:= expand.c expand_tools.c expand_env.c expand_pid_env.c
SRC_EXPAND		:= $(addprefix $(DIR_EXPAND)/, $(SRC_EXPAND))

SRC_PARSE		:=	parse_cmd_lst.c parse_free.c parse_ifs.c parse_remove.c \
					parse_tools.c parse_word.c parse.c 
SRC_PARSE		:= $(addprefix $(DIR_PARSE)/, $(SRC_PARSE))

SRC_DEBUG		:=	print_lst_token.c print_lst_cmd.c
SRC_DEBUG		:=	$(addprefix $(DIR_DEBUG)/, $(SRC_DEBUG))

SRC_EXECUTE		:=	exec_built_in.c exec_do.c exec_file.c exec_ft_tools.c \
					exec_path.c exec_pipe.c exec_redirect.c exec_utils.c \
					execute.c exec_file_check.c exec_redi_handler.c \
					exec_multi_child.c exec_multi.c
SRC_EXECUTE		:=	$(addprefix $(DIR_EXECUTE)/, $(SRC_EXECUTE))

SRC_HEREDOC		:= heredoc.c heredoc_util.c heredoc_do.c
SRC_HEREDOC		:= $(addprefix $(DIR_HEREDOC)/, $(SRC_HEREDOC))

SRC_BUILT_IN	:=	ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c \
					ft_unset.c ft_cd_path.c
SRC_BUILT_IN	:=	$(addprefix $(DIR_BUILT_IN)/, $(SRC_BUILT_IN))

SRCS			=	$(SRC_ENV) $(SRC_TOKENIZE) $(SRC_UTILS) $(SRC_MAIN) \
					$(SRC_DEBUG) $(SRC_EXPAND) $(SRC_PARSE) $(SRC_EXECUTE) \
					$(SRC_BUILT_IN) $(SRC_HEREDOC)

OBJS 			=	${SRCS:.c=.o}


all : ${NAME}

$(NAME) : $(NAME_LIBFT) ${OBJS} $(READLINE)
	@cat ./decoration/intro
	@${CC} -o ${NAME} ${CFLAGS} ${OBJS} $(LIB_READLINE) $(LIB_LIBFT) -lreadline -lft -lncurses
	@chmod +x ./decoration/loading.sh
	@./decoration/loading.sh
$(NAME_LIBFT)	:
	@make -C $(DIR_LIBFT) all

$(READLINE)		:
	@cd $(DIR_READLINE); ./configure
	@make -C $(DIR_READLINE) all

%.o		:	%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(INCLUDE_READLINE)

clean :
	#@make -C $(DIR_READLINE) clean
	@make -C $(DIR_LIBFT) fclean
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
