NAME						=	minishell

CC							=	cc
CFLAGS						=	-Wall -Wextra -Werror
DEBUG						=	-g -fsanitize=address
LEAKS						=	-g

LIBFT_FLAGS 				=	-L$(DIR_LIBFT) -lft
INCS_FLAGS					=	-I $(DIR_LIBFT) -I $(DIR_INCS)
RL_LIB						=	-lreadline -L${HOME}/.brew/opt/readline/lib
RL_INCLUDE					=	-I${HOME}/.brew/opt/readline/include
LIBFT						=	$(DIR_LIBFT)/libft.a

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
								env_add.c				\
								env_print.c				\
								env_util.c				\
								env_key_value.c
SRCS_LEXICAL_ANALYSIS		:=	$(addprefix $(DIR_LEXICAL_ANALYSIS)/, $(SRCS_LEXICAL_ANALYSIS))

SRCS_SYNTAX_ANALYSIS		:=	add_parsing_list_node.c \
								add_redir_chunk_node.c 	\
								add_simple_cmd_node.c 	\
								free_parsing_list.c 	\
								init_parsing_list.c 	\
								init_redir_chunk_node.c \
								init_simple_cmd_node.c 	\
								is_redirection.c 		\
								is_word.c 				\
								parser.c 				\
								init_redir_iter.c		\
								is_pipe.c
SRCS_SYNTAX_ANALYSIS		:=	$(addprefix $(DIR_SYNTAX_ANALYSIS)/, $(SRCS_SYNTAX_ANALYSIS))

SRCS_EXECUTION				:=	count_num_processes.c	\
								do_it_child.c 			\
								do_it_parent.c 			\
								execute_cmd.c 			\
								execve_cmd.c			\
								init_curr_envp.c 		\
								init_fd_by_redirection.c\
								init_execve_args.c 		\
								is_last_cmd.c			\
								is_single_cmd.c			\
								parent_init_fd_redir.c	\
								run_single_built_in.c	\
								safe_close.c 			\
								safe_dup2.c 			\
								safe_dup2_and_close.c	\
								safe_fork.c 			\
								safe_open.c				\
								safe_pipe.c 			\
								wait_all_child.c 		\
								here_doc.c 				\
								here_doc_add.c 			\
								here_doc_signal.c
SRCS_EXECUTION				:=	$(addprefix $(DIR_EXECUTION)/, $(SRCS_EXECUTION))

SRCS_BUILT_IN				:=	built_in.c		\
								cd.c			\
								echo.c			\
								env.c			\
								exit.c			\
								export.c		\
								pwd.c			\
								unset.c	
SRCS_BUILT_IN				:=	$(addprefix $(DIR_BUILT_IN)/, $(SRCS_BUILT_IN))

SRCS_ERROR					:=	printf_syntax_error.c	\
								is_exceed_max_fd.c		\
								is_system_call_error.c
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

ifdef LEAKS_FLAG
	CFLAGS += $(LEAKS)
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

leaks:
	$(MAKE) LEAKS_FLAG=1

clean:
	rm -rf $(OBJS) $(NAME).dSYM
	make clean -C $(DIR_LIBFT)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME) $(BONUS_NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re debug
