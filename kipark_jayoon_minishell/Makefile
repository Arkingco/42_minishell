NAME						=	minishell

CC							=	cc
CFLAGS						=	-Wall -Wextra -Werror
DEBUG						=	-g3 -fsanitize=address

LIBFT_FLAGS 				=	-L$(DIR_LIBFT) -lft
INCS_FLAGS					=	-I $(DIR_LIBFT) -I $(DIR_INCS)
RL_LIB						=	-lreadline -L${HOME}/.brew/opt/readline/lib
RL_INCLUDE					=	-I${HOME}/.brew/opt/readline/include

LIBFT_AR					:=	libft.a

DIR_SRCS					:=	./srcs
DIR_OBJS					:=	./objs
DIR_INCS 					:=	./includes/
DIR_LIBFT					:=	./libft

DIR_TERMINAL				:=	$(DIR_SRCS)/terminal
DIR_LEXICAL_ANALYSIS		:=	$(DIR_SRCS)/lexical_analysis
DIR_SYNTAX_ANALYSIS			:=	$(DIR_SRCS)/syntax_analysis
DIR_EXECUTION				:=	$(DIR_SRCS)/execution
DIR_BUILT_IN				:=	$(DIR_SRCS)/built_in

SRCS_TERMINAL				:=	exit_terminal.c		\
								init_terminal.c
SRCS_TERMINAL				:=	$(addprefix $(DIR_TERMINAL)/, $(SRC_TERMINAL))

SRCS_LEXICAL_ANALYSIS		:=	parse_util.c		\
								parse.c				\
								token.c				
SRCS_LEXICAL_ANALYSIS		:=	$(addprefix $(DIR_LEXICAL_ANALYSIS)/, $(SRCS_LEXICAL_ANALYSIS))

SRCS_SYNTAX_ANALYSIS		:=	parser.c
SRCS_SYNTAX_ANALYSIS		:=	$(addprefix $(DIR_SYNTAX_ANALYSIS)/, $(SRCS_SYNTAX_ANALYSIS))

SRCS_EXECUTION				:=	
SRCS_EXECUTION				:=	$(addprefix $(DIR_EXECUTION)/, $(SRCS_EXECUTION))

SRCS_BUILT_IN				:=	
SRCS_BUILT_IN				:=	$(addprefix $(DIR_BUILT_IN)/, $(SRCS_BUILT_IN))

SRCS						:=	$(SRCS_TERMINAL)			\
								$(SRCS_LEXICAL_ANALYSIS)	\
								$(SRCS_SYNTAX_ANALYSIS)		\
								$(SRCS_EXECUTION)			\
								$(SRCS_BUILT_IN)

OBJS						:=	$(SRCS:.c=.o)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(RL_INCLUDE) $(INCS_FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(RL_LIB) $(LIBFT_FLAGS) $(OBJS) -o $@

$(LIBFT):
	make -C $(DIR_LIBFT)

# $(DIR_OBJS):
# 	mkdir $(DIR_OBJS)

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	make clean -C $(DIR_LIBFT)
	rm -rf $(DIR_OBJS)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME) $(BONUS_NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re debug
