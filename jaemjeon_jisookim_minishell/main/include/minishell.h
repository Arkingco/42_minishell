/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:42:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/20 13:38:26 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <stdio.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>

# include "./libft/libft.h"
# include "./parse.h"
# include "./tokenize.h"
# include "./env.h"
# include "./util.h"

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define GET 0
# define SET 1

# define INPUT 0
# define OUTPUT 1

enum	e_token
{
	E_WORD = 0,
	E_REDIRECT,
	E_PIPE,
	E_NULL
};

enum	e_redirect
{
	E_REDI_R = 0,
	E_REDI_L,
	E_REDI_RR,
	E_REDI_LL
};

typedef struct s_token
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

// main.c

//main_loop.c
void	loop_get_commandline(void);

// init.c
void	init(int argc, char *envp[]);
void	init_env_lst(char *envp[]);
void	update_shlvl(void);

// signal_action.c
void	set_signal_action(void);

// pwd.c
void	pwd(void);

#endif
