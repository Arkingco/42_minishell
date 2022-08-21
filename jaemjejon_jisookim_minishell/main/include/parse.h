/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:44:45 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/21 11:23:44 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define GET 0
# define SET 1

# define INPUT 0
# define OUTPUT 1

typedef enum e_token	t_token_type;
typedef enum e_redirect	t_redirect_type;

enum e_token
{
	E_WORD 		= 1,
	E_REDIRECT	= 2,
	E_PIPE		= 3,
	E_NULL		= 4
};

enum e_redirect
{
	E_REDI_R 	= 1, // >
	E_REDI_L	= 2, // >>
	E_REDI_RR	= 3, // <
	E_REDI_LL	= 4
// <<
};

typedef struct s_token // to do : value 초기화, redirect_type = 0
{
	int				type;
	int				redirect_type;
	char			*word_value;
	struct s_token	*next;
}	t_token;

typedef struct s_simple_command
{
	t_token						cur;
	struct	s_simple_command	*next;
}	t_simple_command;

typedef struct s_redirect
{
	t_token		*redirect_input[2]; // [0] -> REDIRECT_TOKEN [1] -> FILENAME_TOKEN
	t_token		*redirect_output[2];
}	t_redirect;

typedef struct s_cmd
{
	t_simple_command	simple_command;
	t_redirect			redirect;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_envlst
{
	char			*key;
	char			*value;
	struct s_envlst	*next;
}	t_envlst;

typedef struct s_global
{
	char		**envp;
	t_envlst	*lst_env;
	t_token		*lst_token;
	t_cmd		*lst_cmd;
}	t_global;

//libft.c


// paring.c
void	parsing(t_token *inter, t_token *test1, t_token *test2, t_token *test3, t_token *test4);
void	print_token_list(t_token *token);
void	make_cmd_line(int list_size, t_token *token, t_token_type token_value, t_redirect_type redirect, char *word_value);
t_token *make_next_token(t_token *new_token, t_token *next_token);
t_token	*input_cmd_list_test(t_token *token, t_token_type token_value, t_redirect_type redirect, char *word_value);
t_token	*point_next(t_token *token);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

// parse_make_cmd.c

void	make_redirect_tokens(t_token *cur_token);
void	make_word_token(t_token *cur_token);
t_cmd	*ft_getlstcmd_last(void);
void	make_cmd_node(t_token *cur_token);
void	make_cmd_list(void);
void	parse_add_redirect_token(t_token *token_addr, int io);
void	parse_add_word_token(t_token *token_addr);

// parse_token.c
void	parse_add_redirect_token(t_token *token_addr, int io);

#endif