<<<<<<< HEAD
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/08/27 12:06:40 by kipark           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3 -fsanitize=address

LIBFT_FLAGS =	-L$(LIBFT_DIR) -lft
INCS_FLAGS	=	-I$(LIBFT_DIR) -I $(INCS_DIR)
RL_LIB		=	-lreadline -L${HOME}/.brew/opt/readline/lib
RL_INCLUDE	=	-I${HOME}/.brew/opt/readline/include

LIBFT_AR	=	libft.a

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR 	=	./includes/
LIBFT_DIR	=	./libft/

SRCS_NAME	=	main.c 					\
				init_terminal.c			\
				exit_terminal.c			\
				parse.c					\
				parse_util.c 			\
				token.c					\
				token_expand.c			\
				token_quote_remove.c	\
				env.c

OBJS_NAME	=	$(SRCS_NAME:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))
LIBFT		=	$(LIBFT_DIR)$(LIBFT_AR)
=======
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

SRCS_MAIN					:=	main.c
SRCS_MAIN					:=	$(addprefix $(DIR_SRCS)/, $(SRCS_MAIN))

SRCS_TERMINAL				:=	exit_terminal.c		\
								init_terminal.c
SRCS_TERMINAL				:=	$(addprefix $(DIR_TERMINAL)/, $(SRCS_TERMINAL))

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

SRCS						:=	$(SRCS_MAIN)				\
								$(SRCS_TERMINAL)			\
								$(SRCS_LEXICAL_ANALYSIS)	\
								$(SRCS_SYNTAX_ANALYSIS)		\
								$(SRCS_EXECUTION)			\
								$(SRCS_BUILT_IN)

OBJS						:=	$(SRCS:.c=.o)
>>>>>>> e2c55cfd9d54d452a560d3991c0b8270565fca56

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(RL_LIB) $(LIBFT_FLAGS) $(OBJS) -o $@

<<<<<<< HEAD
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(RL_INCLUDE) $(INCS_FLAGS) -c -g $< -o $@
=======
%.o			: %.c
	$(CC) $(CFLAGS) $(RL_INCLUDE) $(INCS_FLAGS) -c $< -o $@
>>>>>>> e2c55cfd9d54d452a560d3991c0b8270565fca56

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
