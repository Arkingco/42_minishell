# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 15:49:31 by jisookim          #+#    #+#              #
#    Updated: 2022/08/19 16:01:30 by jisookim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror \
				-g -L /opt/homebrew/Cellar/readline/8.1.2/lib \
				-I /opt/homebrew/Cellar/readline/8.1.2/include
				# -L ~/.brew/Cellar/readline/8.1.2/lib
				# -I ~/.brew/Cellar/readline/8.1.2/include
RM			:=	rm -f
AR			:=	ar
ARFLAGS		:=	rcus
SANITIZE	:=	-fsanitize=address -g3

NAME		:=	minishell

# todo : make srcs directory!

# srcs
SRCS_DIR	:=	./src
SRCS		:=	main.c				\ 
				main_loop.c			\
				init.c				\
				env.c				\
				pwd.c				\
				signal_action.c		\
				env_list_adt_1.c		\
				env_list_adt_2.c		\
				env_list_adt_3.c		\
				util_1.c
SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# libft
LIBFT_DIR	:=	./libft
LIBFT		:=	libft.a
LIBFT		:=	$(addprefix $(LIBFT_DIR)/, $(LIBFT))

# objs
OBJS_DIR	:=	./
OBJS		:=	$(SRCS:.c=.o)
OBJS		+=	$(LIBFT:.c=.o)

# header
INCLUDE_DIR	:=	./include
INCLUDE		:=	minishell.h

INCLUDE		:=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE))

$(NAME)		:	$(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -L$(LIBFT_DIR) -lft -lreadline $(CFLAGS) $(OBJS) -o $@

%.o			: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

# make commands
.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
	$(RM) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

.PHONY		:	fclean
fclean		:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

.PHONY		:	re
re			:
	$(MAKE) fclean
	$(MAKE) all



# $(NAME) : ${OBJS} ${LIBFT}
# 	${CC} -lreadline ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

# ${LIBFT} :
# 	make -C ${DIR_LIB} all

# .c.o : ${SRCS}
# 	${CC} ${CFLAGS} -c $^

# clean :
# 	rm -f ${OBJS}
# 	make -C ${DIR_LIB} fclean

# fclean : clean
# 	rm -f ${NAME}

# .PHONY : all clean fclean bonus re

# re : fclean all
