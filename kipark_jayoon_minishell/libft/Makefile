# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 18:08:18 by jayoon            #+#    #+#              #
#    Updated: 2022/09/24 15:22:57 by kipark           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I.
CC = cc
HEADER = ./libft.h
SRCS =		ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprint.c			\
			ft_isspace.c			\
			ft_issign.c				\
			ft_isint.c				\
			ft_tolower.c			\
			ft_toupper.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strncmp.c			\
			ft_strlen.c				\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_strnstr.c			\
			ft_atoi.c				\
			ft_atol.c				\
			ft_calloc.c				\
			ft_strdup.c				\
			ft_memset.c				\
			ft_bzero.c				\
			ft_memcmp.c				\
			ft_memcpy.c				\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_striteri.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_safe_free.c			\
			ft_safe_malloc.c		\
			ft_check_error.c		\
			ft_strchr_index.c
			
		
SRCS_B = 		ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c	

OBJECTS = $(SRCS:%.c=%.o)

OBJECTS_B = $(SRCS_B:%.c=%.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJECTS) $(OBJECTS_B)
else
	OBJ_FILES = $(OBJECTS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(HEADER)
	ar rcs $(NAME) $(OBJ_FILES)

bonus : 
	@make WITH_BONUS=1

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all bonus clean fclean re
