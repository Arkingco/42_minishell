# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 15:49:31 by jisookim          #+#    #+#              #
#    Updated: 2022/08/21 18:06:48 by jisookim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# HEADER
INCLUDE_DIR	:=	./include
INCLUDE		:=	minishell.h env.h parse.h tokenize.h util.h
INCLUDE		:=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE))

# SRCS
SRCS_DIR	:=	./src

# DIRECTORIES
DIR_BUILT_IN	:=	$(SRCS_DIR)/built_in
DIR_ENV			:=	$(SRCS_DIR)/env
DIR_EXECUTEOR	:=	$(SRCS_DIR)/executor
DIR_EXPAND		:=	$(SRCS_DIR)/expand
DIR_HEREDOC		:=	$(SRCS_DIR)/heredoc
DIR_LEXER		:=	$(SRCS_DIR)/lexer
DIR_PARSER		:=	$(SRCS_DIR)/parser
DIR_REDIRECTION	:=	$(SRCS_DIR)/redirection
DIR_TERMINAL	:=	$(SRCS_DIR)/terminal
DIR_TOKENIZER	:=	$(SRCS_DIR)/tokenizer
DIR_UTILS		:=	$(SRCS_DIR)/utils
DIR_MAIN		:=	$(SRCS_DIR)

# built_in
SRC_BUILT_IN	:= env.c pwd.c
SRC_BUILT_IN	:= $(addprefix $(DIR_BUILT_IN)/, $(SRC_BUILT_IN))

# env
SRC_ENV			:= env_list_adt_1.c env_list_adt_2.c env_list_adt_3.c
SRC_ENV			:= $(addprefix $(DIR_ENV)/, $(SRC_ENV))

# executor
SRC_EXECUTOR	:= 
SRC_EXECUTOR	:= $(addprefix $(DIR_EXECUTOR)/, $(SRC_EXECUTOR))

# expand
SRC_EXPAND	:= 
SRC_EXPAND	:= $(addprefix $(DIR_EXPAND)/, $(SRC_EXPAND))

# heredoc
SRC_HEREDOC	:= 
SRC_HEREDOC	:= $(addprefix $(DIR_HEREDOC)/, $(SRC_HEREDOC))

# lexer
SRC_LEXER	:= 
SRC_LEXER	:= $(addprefix $(DIR_LEXER)/, $(SRC_LEXER))

# parser
SRC_PARSER	:= parse_make_cmd.c parse_token.c parsing.c
SRC_PARSER	:= $(addprefix $(DIR_PARSER)/, $(SRC_PARSER))

# redirection
SRC_REDIRECTION	:= 
SRC_REDIRECTION	:= $(addprefix $(DIR_REDIRECTION)/, $(SRC_REDIRECTION))

# terminal
SRC_TERMINAL	:= signal_action.c
SRC_TERMINAL	:= $(addprefix $(DIR_TERMINAL)/, $(SRC_TERMINAL))

# tokenizer
SRC_TOKENIZER	:= token_list_adt_1.c tokenizing.c
SRC_TOKENIZER	:= $(addprefix $(DIR_TOKENIZER)/, $(SRC_TOKENIZER))

# utils
SRC_UTILS		:= init.c leaks.c main_loop.c util_1.c
SRC_UTILS		:= $(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

# main
SRCS_MAIN		:=	main.c
SRCS_MAIN		:=	$(addprefix $(DIR_MAIN)/, $(SRC_MAIN))


# MINISHELL
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror \
				-g -L /opt/homebrew/Cellar/readline/8.1.2/lib \
				-I /opt/homebrew/Cellar/readline/8.1.2/include
				# -L ~/.brew/Cellar/readline/8.1.2/lib
				# -I ~/.brew/Cellar/readline/8.1.2/include
RM			:=	rm -f
SANITIZE	:=	-fsanitize=address -g3

NAME		:=	minishell

SRCS	:=	$(SRC_BUILT_IN) $(SRC_ENV) $(SRC_EXECUTOR) \
			$(SRC_EXPANDER) $(SRC_HEREDOC) $(SRC_LEXER) \
			$(SRC_REDIRECTION) $(SRC_PARSER) $(SRC_TERMINAL) \
			$(SRC_TOKENIZER) $(SRC_UTILS) $(SRC_MAIN)

# libft
DIR_LIBFT	:=	./libft
LIBFT		:=	libft.a
LIBFT		:=	$(addprefix $(DIR_LIBFT)/, $(LIBFT))

# objs
DIR_OBJS	:=	./
OBJS		:=	$(SRCS:.c=.o)
OBJS		+=	$(LIBFT:.c=.o)


$(NAME)		:	$(OBJS)
	$(MAKE) -C $(DIR_LIBFT)
	$(CC) -L$(DIR_LIBFT) -lft -lreadline $(CFLAGS) $(OBJS) -o $@

%.o			: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

# MAKE COMMANDS
.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
	$(MAKE) -C $(DIR_LIBFT) clean
	$(RM) $(OBJS)

.PHONY		:	fclean
fclean		:	clean
	$(MAKE) -C $(DIR_LIBFT) fclean
	$(RM) $(NAME)

.PHONY		:	re
re			:
	$(MAKE) fclean
	$(MAKE) all
