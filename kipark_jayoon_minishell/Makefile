# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 21:13:32 by jayoon            #+#    #+#              #
#    Updated: 2022/08/20 14:30:03 by kipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3 -fsanitize=address

LIBFT_FLAGS =	-L$(LIBFT_DIR) -lft
# MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCS_FLAGS	=	-I$(LIBFT_DIR) -I $(INCS_DIR)
LDFLAGS		=	-lreadline -L${HOME}/.brew/opt/readline/lib
CPPFLAGS	=	-I${HOME}/.brew/opt/readline/include

LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include

LIBFT_AR	=	libft.a

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR 	=	./includes/
LIBFT_DIR	=	./libft/

SRCS_NAME	=	main.c 				\
				init_terminal.c		\
				exit_terminal.c		\
				parse.c		\
				token.c \

OBJS_NAME	=	$(SRCS_NAME:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))
LIBFT		=	$(LIBFT_DIR)$(LIBFT_AR)

ifdef DEBUG_FLAG
	CFLAGS += $(DEBUG)
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCS_FLAGS) -c $< -o $@

debug: 
	$(MAKE) DEBUG_FLAG=1

clean:
	@make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean
	make all

.PHONY: all clean fclean re debug
