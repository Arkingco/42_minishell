NAME						=	minishell

CC							=	cc
CFLAGS						=	-Wall -Wextra -Werror
DEBUG						=	-g3 -fsanitize=address

LIBFT_FLAGS 				=	-L$(DIR_LIBFT) -lft
INCS_FLAGS					=	-I $(DIR_LIBFT) -I $(DIR_INCS)
RL_LIB						=	-lreadline -L${HOME}/.brew/opt/readline/lib
RL_INCLUDE					=	-I${HOME}/.brew/opt/readline/include
LIBFT						=	libft.a

DIR_SRCS					:=	./srcs
DIR_INCS 					:=	./includes
DIR_LIBFT					:=	./libft

DIR_TERMINAL				:=	$(DIR_SRCS)/terminal
DIR_LEXICAL_ANALYSIS		:=	$(DIR_SRCS)/lexical_analysis
DIR_SYNTAX_ANALYSIS			:=	$(DIR_SRCS)/syntax_analysis
DIR_EXECUTION				:=	$(DIR_SRCS)/execution
DIR_BUILT_IN				:=	$(DIR_SRCS)/built_in
DIR_ERROR					:=	$(DIR_SRCS)/error

SRCS_MAIN					:=	main.c
SRCS_MAIN					:=	$(addprefix $(DIR_SRCS)/, $(SRCS_MAIN))

SRCS_TERMINAL				:=	exit_terminal.c		\
								init_terminal.c		\
								free_terminal.c
SRCS_TERMINAL				:=	$(addprefix $(DIR_TERMINAL)/, $(SRCS_TERMINAL))

SRCS_LEXICAL_ANALYSIS		:=	lexer_util.c			\
								lexer.c					\
								token.c					\
								token_expand.c			\
								token_quote_remove.c	\
								env.c					\
								env_util.c				\
								env_list.c
SRCS_LEXICAL_ANALYSIS		:=	$(addprefix $(DIR_LEXICAL_ANALYSIS)/, $(SRCS_LEXICAL_ANALYSIS))

SRCS_SYNTAX_ANALYSIS		:=	add_parsing_list_node.c \
								add_redir_chunk_node.c \
								add_simple_cmd_node.c \
								check_syntax_and_set_parsing_list.c \
								free_parsing_list.c \
								init_parsing_list.c \
								init_redirection_node.c \
								init_simple_cmd_node.c \
								is_redirection.c \
								is_word.c \
								parser.c
SRCS_SYNTAX_ANALYSIS		:=	$(addprefix $(DIR_SYNTAX_ANALYSIS)/, $(SRCS_SYNTAX_ANALYSIS))

SRCS_EXECUTION				:=	
SRCS_EXECUTION				:=	$(addprefix $(DIR_EXECUTION)/, $(SRCS_EXECUTION))

SRCS_BUILT_IN				:=	
SRCS_BUILT_IN				:=	$(addprefix $(DIR_BUILT_IN)/, $(SRCS_BUILT_IN))

SRCS_ERROR					:=	print_syntax_error_pipe.c \
								printf_syntax_error.c
SRCS_ERROR					:=	$(addprefix $(DIR_ERROR)/, $(SRCS_ERROR))

SRCS						:=	$(SRCS_MAIN)				\
								$(SRCS_TERMINAL)			\
								$(SRCS_LEXICAL_ANALYSIS)	\
								$(SRCS_SYNTAX_ANALYSIS)		\
								$(SRCS_EXECUTION)			\
								$(SRCS_BUILT_IN)			\
								$(SRCS_ERROR)

OBJS						:=	$(SRCS:.c=.o)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(RL_LIB) $(LIBFT_FLAGS) $(OBJS) -o $@

%.o			: %.c
	$(CC) $(CFLAGS) $(RL_INCLUDE) $(INCS_FLAGS) -c $< -o $@

$(LIBFT)	:
	make -C $(DIR_LIBFT) all

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	rm -f $(OBJS)
	make clean -C $(DIR_LIBFT)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME) $(BONUS_NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re debug
